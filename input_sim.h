#pragma once
#include "input_sim_macros.h"

namespace Coast {
    enum KeyCodes : unsigned int {
        COAST_A = 4,
        COAST_B = 5,
        COAST_C = 6,
        COAST_D = 7,
        COAST_E = 8,
        COAST_F = 9,
        COAST_G = 10,
        COAST_H = 11,
        COAST_I = 12,
        COAST_J = 13,
        COAST_K = 14,
        COAST_L = 15,
        COAST_M = 16,
        COAST_N = 17,
        COAST_O = 18,
        COAST_P = 19,
        COAST_Q = 20,
        COAST_R = 21,
        COAST_S = 22,
        COAST_T = 23,
        COAST_U = 24,
        COAST_V = 25,
        COAST_W = 26,
        COAST_X = 27,
        COAST_Y = 28,
        COAST_Z = 29,
        COAST_1 = 30,
        COAST_2 = 31,
        COAST_3 = 32,
        COAST_4 = 33,
        COAST_5 = 34,
        COAST_6 = 35,
        COAST_7 = 36,
        COAST_8 = 37,
        COAST_9 = 38,
        COAST_0 = 39,
        COAST_Enter = 40,
        COAST_Escape = 41,
        COAST_Backspace = 42,
        COAST_Tab = 43,
        COAST_Space = 44,
        COAST_Minus = 45,
        COAST_Equals = 46,
        COAST_LeftBracket = 47,
        COAST_RightBracket = 48,
        COAST_Backslash = 49,
        COAST_Semicolon = 51,
        COAST_APOSTROPHE = 52,
        COAST_Grave = 53,
        COAST_Comma = 54,
        COAST_Period = 55,
        COAST_Slash = 56,
        COAST_CapsLock = 57,
        COAST_F1 = 58,
        COAST_F2 = 59,
        COAST_F3 = 60,
        COAST_F4 = 61,
        COAST_F5 = 62,
        COAST_F6 = 63,
        COAST_F7 = 64,
        COAST_F8 = 65,
        COAST_F9 = 66,
        COAST_F10 = 67,
        COAST_F11 = 68,
        COAST_F12 = 69,
        COAST_PrintScreen = 70,
        COAST_ScrollLock = 71,
        COAST_Pause = 72,
        COAST_Insert = 73,
        COAST_Home = 74,
        COAST_PageUp = 75,
        COAST_Delete = 76,
        COAST_End = 77,
        COAST_PageDown = 78,
        COAST_Right = 79,
        COAST_Left = 80,
        COAST_Down = 81,
        COAST_Up = 82,
        COAST_KP_NumLock = 83,
        COAST_KP_Divide = 84,
        COAST_KP_Asterisk = 85,
        COAST_KP_Subtract = 86,
        COAST_KP_Add = 87,
        COAST_KP_Enter = 88,
        COAST_KP_1 = 89,
        COAST_KP_2 = 90,
        COAST_KP_3 = 91,
        COAST_KP_4 = 92,
        COAST_KP_5 = 93,
        COAST_KP_6 = 94,
        COAST_KP_7 = 95,
        COAST_KP_8 = 96,
        COAST_KP_9 = 97,
        COAST_KP_0 = 98,
        COAST_KP_Period = 99,
        COAST_KP_Equals = 103,
        COAST_F13 = 104,
        COAST_F14 = 105,
        COAST_F15 = 106,
        COAST_F16 = 107,
        COAST_F17 = 108,
        COAST_F18 = 109,
        COAST_F19 = 110,
        COAST_F20 = 111,
        COAST_F21 = 112,
        COAST_F22 = 113,
        COAST_F23 = 114,
        COAST_F24 = 115,
        COAST_Help = 117,
        COAST_Menu = 118,
        COAST_LeftControl = 224,
        COAST_LeftShift = 225,
        COAST_LeftAlt = 226,
        COAST_LeftMeta = 227,
        COAST_RightControl = 228,
        COAST_RightShift = 229,
        COAST_RightAlt = 230,
        COAST_RightMeta = 231,
        INVALID = 255
    };

    enum MouseButtons : unsigned char 
    { 
        LEFT, 
        MIDDLE, 
        RIGHT 
    };

    struct KeyEvent {
        bool Pressed;
        KeyCodes Key;
    };
    struct MouseButtonEvent {
        bool Pressed;
        MouseButtons Button;
    };
    struct MouseScrollEvent {
        int Offset;
    };
    struct MousePositionOffsetEvent {
        int X = 0;
        int Y = 0;
    };
    struct MousePositionAbsoluteEvent {
        int X = 0;
        int Y = 0;
    };

    bool SYMBOL_EXPORT InitialiseInputSimulation();
    void SYMBOL_EXPORT ReleaseInputSimulation();
    void SYMBOL_EXPORT SendInput(const KeyEvent &e);
    void SYMBOL_EXPORT SendInput(const MouseButtonEvent &e);
    void SYMBOL_EXPORT SendInput(const MouseScrollEvent &e);
    void SYMBOL_EXPORT SendInput(const MousePositionOffsetEvent &e);
    void SYMBOL_EXPORT SendInput(const MousePositionAbsoluteEvent &e);
}
