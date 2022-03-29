#pragma once

#ifdef _WIN32
    #ifdef EXPORT_SYMBOLS
        #define SYMBOL_EXPORT __declspec(dllexport)
    #else
        #define SYMBOL_EXPORT __declspec(dllimport)
    #endif
#else
    #define SYMBOL_EXPORT
#endif