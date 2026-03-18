// crash_handler.h
#pragma once
#ifdef _WIN32
#include <windows.h>
#include <dbghelp.h>
#include <cstdio>
#pragma comment(lib, "dbghelp.lib")

static LONG WINAPI CrashHandler(EXCEPTION_POINTERS* pException)
{
    // Имя файла с датой/временем
    char filename[256];
    SYSTEMTIME st;
    GetLocalTime(&st);
    snprintf(filename, sizeof(filename),
        "crash_%04d%02d%02d_%02d%02d%02d.dmp",
        st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond);

    HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile != INVALID_HANDLE_VALUE)
    {
        MINIDUMP_EXCEPTION_INFORMATION mei;
        mei.ThreadId = GetCurrentThreadId();
        mei.ExceptionPointers = pException;
        mei.ClientPointers = FALSE;

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),
            hFile,
            (MINIDUMP_TYPE)(MiniDumpWithDataSegs |
                MiniDumpWithHandleData |
                MiniDumpWithThreadInfo),
            &mei, NULL, NULL);
        CloseHandle(hFile);

        printf("\n=== CRASH ===\nDump saved: %s\n", filename);
    }

    // Покажи MessageBox с инфой
    char msg[512];
    snprintf(msg, sizeof(msg),
        "The game has crashed!\n\n"
        "Exception: 0x%08X\n"
        "Address: 0x%p\n\n"
        "Crash dump saved to:\n%s\n\n"
        "Please send this file to the developer.",
        pException->ExceptionRecord->ExceptionCode,
        pException->ExceptionRecord->ExceptionAddress,
        filename);
    MessageBoxA(NULL, msg, "King's Field II - Crash", MB_OK | MB_ICONERROR);

    return EXCEPTION_EXECUTE_HANDLER;
}

static inline void InstallCrashHandler()
{
    SetUnhandledExceptionFilter(CrashHandler);
}

#else
// Linux/Mac — простой signal handler
#include <signal.h>
#include <execinfo.h>
#include <cstdio>
#include <cstdlib>

static void CrashHandler(int sig)
{
    void* frames[64];
    int count = backtrace(frames, 64);
    fprintf(stderr, "\n=== CRASH (signal %d) ===\n", sig);
    backtrace_symbols_fd(frames, count, 2);
    exit(1);
}

static inline void InstallCrashHandler()
{
    signal(SIGSEGV, CrashHandler);
    signal(SIGABRT, CrashHandler);
    signal(SIGFPE, CrashHandler);
}
#endif