#pragma once
#define _CRT_SECURE_NO_WARNINGS
// Отключаем самые назойливые предупреждения для машинно-генерируемого кода
#ifdef _MSC_VER
    #pragma warning(disable : 4101) // Неиспользуемые локальные переменные
    #pragma warning(disable : 4102) // Неиспользуемые метки (labels) - их будет МНОГО
    #pragma warning(disable : 4244) // Преобразование типов (например, из 64-бит в 32-бит)
    #pragma warning(disable : 4018) // Сравнение знаковых и беззнаковых целых
    #pragma warning(disable : 4715) // Не все пути управления возвращают значение
    #pragma warning(disable : 4098) // 'return' с выражением в функции void
    #pragma warning(disable : 4267) // Возможная потеря данных (size_t в int)

    #pragma warning(disable : 4013)
    
#endif