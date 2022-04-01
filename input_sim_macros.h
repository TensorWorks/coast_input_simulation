#pragma once

#if defined(_WIN32) && defined(COAST_IS_SHARED)
    #ifdef EXPORT_COAST_IS_SYMBOLS
        #define COAST_IS_API __declspec(dllexport)
    #else
        #define COAST_IS_API __declspec(dllimport)
    #endif
#else
    #define COAST_IS_API
#endif