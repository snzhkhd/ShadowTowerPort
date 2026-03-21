# PS1→PC Port Shadow Tower Projects

## Status: Early Stage

### EXE Structure
```
SLUS_008.63  — bootloader (2KB), Load=0x80010000
ST.EXE       — main game (489KB), Load=0x80011000, Entry=0x80014320
VS.EXE       — PvP mode (338KB), Load=0x80011000
TITLE.EXE    — title screen, Load=0x80012000
END.EXE      — ending, Load=0x80011000
STR.EXE      — streaming, Load=0x80011000
```
All overlay at same address. Only ST.EXE recompiled. Function table base = `0x80010000` (IDA exports offsets from this base).

### What Works
- EXE loading from .bin disc image
- BIOS dispatch (A/B/C functions)
- CD system: CdSearchFile with subdirectories, CdReadWithRetry, streaming
- Graphics init: SetDefDrawEnv/DispEnv, PutDrawEnv/PutDispEnv
- HUD rendering (HP/MP bars visible)
- NEW GAME / LOAD GAME menu renders and responds to selection
- Scratchpad RAM mapped
- malloc3/free3 via bump allocator (original heap gets corrupted)
- OTag pipeline working (primitives render)
- 3D world rendering

### What Doesn't Work Yet
- **Input partially broken** — buttons register in `dword_801CD184` and `pad_80198F54` but menu navigation incomplete. Game converts pad→game buttons via player script at 0x801ED498 which may not be initialized.
- **Audio not implemented** — type=4 CD streams (VAB) skipped with NextCdTask
- **Load next world**

### Key Addresses (Shadow Tower)
- g_CDTaskQueue: 0x80088BD4
- g_ActiveCdStream: 0x80088BD8
- State machine: byte_80199140 (0=init, 4=gameplay, 1=death/menu)
- Game pad: pad_80198F54 (game buttons), dword_801CD184 (raw converted)
- Pad buffer: 0x801CD130 (pad1), 0x801CD152 (pad2).RCnt callback, manual call - sub_800153B4.
- Heap pointer: dword_80087C50
- Menu selection: byte_80199086
- Level data pointers: dword_80165398, dword_8016539C

### CD Stream Layout (Shadow Tower) — DIFFERENT from KF2!
```
offset 0  = type (2=data with callback, 3=textures, 4=audio)
offset 1  = read state
offset 4  = RECT/slot data
offset 16 = data_ready
offset 17 = status (audio: 2=ready for transfer)
offset 24 = CdlLOC current position
offset 32 = dest buffer ptr
offset 36 = flag
offset 40 = sectors per chunk
offset 44 = callback ptr
```

### SeekL Handler (ST)
```cpp
case 0x15: case 0x16:
    // Read data, then set flags based on stream type:
    // type==3: stream[16]=1 (data_ready)
    // type==4: skip with NextCdTask (audio not implemented)
    // type==2: read data, call callback at stream+44, then NextCdTask
```

### Main Game Loop (ST)
```
sub_800164B4()    — returns timestamp
sub_80016508()    — resets flags
sub_80042D74()    — large update function with CD loading
sub_80050768()    — math/physics (SquareRoot0, GTE)
sub_8004E324()    — more math
sub_80053AA4()    — more GTE math
sub_8003BC40()    — state machine with cases
sub_8005735C()    — calls function pointer at dword_801B592C+4 (player script?)
sub_800456F8()    — CD work, SsVabClose
sub_8003E734()    — possibly copies player coords/rotation
sub_80058288()    — more global data updates
ProcessAssetLoadQueue()
ProcessCDAudioLoad()
sub_80026AFC()    — RENDER FUNCTION (Begin2D, GTE, DrawOTag)
```

### Render Function sub_80026AFC (ST)
```
sub_80057B10()        — pad vibration reset
sub_800176A8()        — unknown
sub_80016A14()        — unknown
sub_80033110()        — called when state=0,1,5,6 (camera/input setup?)
Begin2D_800174C4()    — ClearOTagR
sub_800340F8()        — unknown
sub_80034FC4()        — unknown
if state==1: draw menu boxes (NEW GAME/LOAD)
sub_8002181C()        — uses sub_80021518
sub_800218D8()        — uses sub_80021518
sub_80021654()        — fade overlays
sub_80021AC4(0)       — **GTE 3D RENDER** (cop2, scratchpad 0x1F800000) ← NOT PRODUCING GEOMETRY
sub_80021AC4(1)       — same, second pass
sub_80020A80()        — **more GTE render** (scratchpad)
sub_8001C8E0..CAB8    — unknown
sub_800241D0..800255F0 — various render (some with GTE)
sub_80017680()        — DrawOTag + buffer swap
sub_8001535C()        — wait CD (stubbed)
```

### Known Issues to Investigate
1. **Next world not loading**
2. **Other EXE not loading**
3. **sub_8003E734 / sub_80058288** — likely copy player position/rotation, similar to KFPlayerCopyPositionRotation in KF2. Need to identify player coordinate addresses.


### Stubbed/HLE Functions (ST)
- CdReset, CdStatus (return ready)
- PadGetState (return 6=stable)
- PadSetAct (vibration — stubbed)
- malloc3/InitHeap3 (bump allocator)
- sub_8001535C (wait CD — instant return)
- dword_8008820C (CD complete flag — set to 1)
- SquareRoot0 (using recompiled version, PsyX version causes issues)
