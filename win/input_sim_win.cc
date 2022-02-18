#include "input_sim.h"

#include <string>
#include <windows.h>

namespace Coast {
    DWORD ConvertToNative(KeyCodes key)
    {
        switch (key) {
        case KeyCodes::COAST_A:
        case KeyCodes::COAST_B:
        case KeyCodes::COAST_C:
        case KeyCodes::COAST_D:
        case KeyCodes::COAST_E:
        case KeyCodes::COAST_F:
        case KeyCodes::COAST_G:
        case KeyCodes::COAST_H:
        case KeyCodes::COAST_I:
        case KeyCodes::COAST_J:
        case KeyCodes::COAST_K:
        case KeyCodes::COAST_L:
        case KeyCodes::COAST_M:
        case KeyCodes::COAST_N:
        case KeyCodes::COAST_O:
        case KeyCodes::COAST_P:
        case KeyCodes::COAST_Q:
        case KeyCodes::COAST_R:
        case KeyCodes::COAST_S:
        case KeyCodes::COAST_T:
        case KeyCodes::COAST_U:
        case KeyCodes::COAST_V:
        case KeyCodes::COAST_W:
        case KeyCodes::COAST_X:
        case KeyCodes::COAST_Y:
        case KeyCodes::COAST_Z:
            return static_cast<int>('A') + (key - KeyCodes::COAST_A);
        case KeyCodes::COAST_1:
        case KeyCodes::COAST_2:
        case KeyCodes::COAST_3:
        case KeyCodes::COAST_4:
        case KeyCodes::COAST_5:
        case KeyCodes::COAST_6:
        case KeyCodes::COAST_7:
        case KeyCodes::COAST_8:
        case KeyCodes::COAST_9:
            return static_cast<int>('1') + (key - KeyCodes::COAST_1);
        case KeyCodes::COAST_0:
            return static_cast<int>('0');
        case KeyCodes::COAST_Enter:
            return VK_RETURN;
        case KeyCodes::COAST_Escape:
            return VK_ESCAPE;
        case KeyCodes::COAST_Backspace:
            return VK_BACK;
        case KeyCodes::COAST_Tab:
            return VK_TAB;
        case KeyCodes::COAST_Space:
            return VK_SPACE;
        case KeyCodes::COAST_Minus:
            return VK_OEM_MINUS;
        case KeyCodes::COAST_Equals:
            return VK_OEM_PLUS; // this is correct and not a mistype
        case KeyCodes::COAST_LeftBracket:
            return VK_OEM_4;
        case KeyCodes::COAST_RightBracket:
            return VK_OEM_6;
        case KeyCodes::COAST_Backslash:
            return VK_OEM_5;
        case KeyCodes::COAST_Semicolon:
            return VK_OEM_1;
        case KeyCodes::COAST_Quote:
            return VK_OEM_7;
        case KeyCodes::COAST_Grave:
            return VK_OEM_3;
        case KeyCodes::COAST_Comma:
            return VK_OEM_COMMA;
        case KeyCodes::COAST_Period:
            return VK_OEM_PERIOD;
        case KeyCodes::COAST_Slash:
            return VK_OEM_2;
        case KeyCodes::COAST_CapsLock:
            return VK_CAPITAL;
        case KeyCodes::COAST_F1:
        case KeyCodes::COAST_F2:
        case KeyCodes::COAST_F3:
        case KeyCodes::COAST_F4:
        case KeyCodes::COAST_F5:
        case KeyCodes::COAST_F6:
        case KeyCodes::COAST_F7:
        case KeyCodes::COAST_F8:
        case KeyCodes::COAST_F9:
        case KeyCodes::COAST_F10:
        case KeyCodes::COAST_F11:
        case KeyCodes::COAST_F12:
            return VK_F1 + (key - KeyCodes::COAST_F1);
        case KeyCodes::COAST_F13:
        case KeyCodes::COAST_F14:
        case KeyCodes::COAST_F15:
        case KeyCodes::COAST_F16:
        case KeyCodes::COAST_F17:
        case KeyCodes::COAST_F18:
        case KeyCodes::COAST_F19:
        case KeyCodes::COAST_F20:
        case KeyCodes::COAST_F21:
        case KeyCodes::COAST_F22:
        case KeyCodes::COAST_F23:
        case KeyCodes::COAST_F24:
            return VK_F13 + (key - KeyCodes::COAST_F13);
        case KeyCodes::COAST_PrintScreen:
            return VK_SNAPSHOT;
        case KeyCodes::COAST_ScrollLock:
            return VK_SCROLL;
        case KeyCodes::COAST_Pause:
            return VK_PAUSE;
        case KeyCodes::COAST_Insert:
            return VK_INSERT;
        case KeyCodes::COAST_Home:
            return VK_HOME;
        case KeyCodes::COAST_PageUp:
            return VK_PRIOR;
        case KeyCodes::COAST_Delete:
            return VK_DELETE;
        case KeyCodes::COAST_End:
            return VK_END;
        case KeyCodes::COAST_PageDown:
            return VK_NEXT;
        case KeyCodes::COAST_Right:
            return VK_RIGHT;
        case KeyCodes::COAST_Left:
            return VK_LEFT;
        case KeyCodes::COAST_Down:
            return VK_DOWN;
        case KeyCodes::COAST_Up:
            return VK_UP;
        case KeyCodes::KP_NumLock:
            return VK_NUMLOCK;
        case KeyCodes::KP_Divide:
            return VK_DIVIDE;
        case KeyCodes::KP_Multiply:
            return VK_MULTIPLY;
        case KeyCodes::KP_Subtract:
            return VK_SUBTRACT;
        case KeyCodes::KP_Add:
            return VK_ADD;
        case KeyCodes::KP_Enter:
            return VK_RETURN;
        case KeyCodes::KP_1:
        case KeyCodes::KP_2:
        case KeyCodes::KP_3:
        case KeyCodes::KP_4:
        case KeyCodes::KP_5:
        case KeyCodes::KP_6:
        case KeyCodes::KP_7:
        case KeyCodes::KP_8:
        case KeyCodes::KP_9:
            return VK_NUMPAD1 + (key - KeyCodes::KP_1);
        case KeyCodes::KP_0:
            return VK_NUMPAD0;
        case KeyCodes::KP_Point:
            return VK_DECIMAL;
        case KeyCodes::COAST_Help:
            return VK_HELP;
        case KeyCodes::COAST_Menu:
            return VK_MENU;
        case KeyCodes::COAST_LeftControl:
            return VK_CONTROL;
        case KeyCodes::COAST_LeftShift:
            return VK_SHIFT;
        case KeyCodes::COAST_LeftAlt:
            return VK_MENU;
        case KeyCodes::COAST_LeftMeta:
            return VK_LWIN;
        case KeyCodes::COAST_RightControl:
            return VK_CONTROL;
        case KeyCodes::COAST_RightShift:
            return VK_SHIFT;
        case KeyCodes::COAST_RightAlt:
            return VK_MENU;
        case KeyCodes::COAST_RightMeta:
            return VK_RWIN;
        default:
            return 255;
        }
    }
    KeyCodes ConvertToKeyCode(DWORD key)
    {

        switch (key) {
        case '0':
            return KeyCodes::COAST_0;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return static_cast<KeyCodes>(KeyCodes::COAST_1 + (key - static_cast<int>('1')));
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return static_cast<KeyCodes>(KeyCodes::COAST_A + (key - static_cast<int>('A')));
        case VK_RETURN:
            return KeyCodes::COAST_Enter;
        case VK_ESCAPE:
            return KeyCodes::COAST_Escape;
        case VK_BACK:
            return KeyCodes::COAST_Backspace;
        case VK_TAB:
            return KeyCodes::COAST_Tab;
        case VK_SPACE:
            return KeyCodes::COAST_Space;
        case VK_OEM_MINUS:
            return KeyCodes::COAST_Minus;
        case VK_OEM_PLUS:
            return KeyCodes::COAST_Equals; // this is correct and not a mistype
        case VK_OEM_4:
            return KeyCodes::COAST_LeftBracket;
        case VK_OEM_6:
            return KeyCodes::COAST_RightBracket;
        case VK_OEM_5:
            return KeyCodes::COAST_Backslash;
        case VK_OEM_1:
            return KeyCodes::COAST_Semicolon;
        case VK_OEM_7:
            return KeyCodes::COAST_Quote;
        case VK_OEM_3:
            return KeyCodes::COAST_Grave;
        case VK_OEM_COMMA:
            return KeyCodes::COAST_Comma;
        case VK_OEM_PERIOD:
            return KeyCodes::COAST_Period;
        case VK_OEM_2:
            return KeyCodes::COAST_Slash;
        case VK_CAPITAL:
            return KeyCodes::COAST_CapsLock;
        case VK_F1:
        case VK_F2:
        case VK_F3:
        case VK_F4:
        case VK_F5:
        case VK_F6:
        case VK_F7:
        case VK_F8:
        case VK_F9:
        case VK_F10:
        case VK_F11:
        case VK_F12:
            return static_cast<KeyCodes>(KeyCodes::COAST_F1 + (key - VK_F1));
        case VK_F13:
        case VK_F14:
        case VK_F15:
        case VK_F16:
        case VK_F17:
        case VK_F18:
        case VK_F19:
        case VK_F20:
        case VK_F21:
        case VK_F22:
        case VK_F23:
        case VK_F24:
            return static_cast<KeyCodes>(KeyCodes::COAST_F13 + (key - VK_F13));
        case VK_SNAPSHOT:
            return KeyCodes::COAST_PrintScreen;
        case VK_SCROLL:
            return KeyCodes::COAST_ScrollLock;
        case VK_PAUSE:
            return KeyCodes::COAST_Pause;
        case VK_INSERT:
            return KeyCodes::COAST_Insert;
        case VK_HOME:
            return KeyCodes::COAST_Home;
        case VK_PRIOR:
            return KeyCodes::COAST_PageUp;
        case VK_DELETE:
            return KeyCodes::COAST_Delete;
        case VK_END:
            return KeyCodes::COAST_End;
        case VK_NEXT:
            return KeyCodes::COAST_PageDown;
        case VK_RIGHT:
            return KeyCodes::COAST_Right;
        case VK_LEFT:
            return KeyCodes::COAST_Left;
        case VK_DOWN:
            return KeyCodes::COAST_Down;
        case VK_UP:
            return KeyCodes::COAST_Up;
        case VK_NUMLOCK:
            return KeyCodes::KP_NumLock;
        case VK_DIVIDE:
            return KeyCodes::KP_Divide;
        case VK_MULTIPLY:
            return KeyCodes::KP_Multiply;
        case VK_SUBTRACT:
            return KeyCodes::KP_Subtract;
        case VK_ADD:
            return KeyCodes::KP_Add;
        case VK_NUMPAD1:
        case VK_NUMPAD2:
        case VK_NUMPAD3:
        case VK_NUMPAD4:
        case VK_NUMPAD5:
        case VK_NUMPAD6:
        case VK_NUMPAD7:
        case VK_NUMPAD8:
        case VK_NUMPAD9:
            return static_cast<KeyCodes>(KeyCodes::KP_1 + (key - VK_NUMPAD1));
        case VK_NUMPAD0:
            return KeyCodes::KP_0;
        case VK_DECIMAL:
            return KeyCodes::KP_Point;
        case VK_HELP:
            return KeyCodes::COAST_Help;
        case VK_MENU:
        case VK_LMENU:
        case VK_RMENU:
            return KeyCodes::COAST_Menu;
        case VK_CONTROL:
        case VK_LCONTROL:
        case VK_RCONTROL:
            return KeyCodes::COAST_LeftControl;
        case VK_SHIFT:
        case VK_LSHIFT:
        case VK_RSHIFT:
            return KeyCodes::COAST_LeftShift;
        case VK_LWIN:
            return KeyCodes::COAST_LeftMeta;
        case VK_RWIN:
            return KeyCodes::COAST_RightMeta;
        default:
            return KeyCodes::INVALID;
        }
    }

    void SendInput(const KeyEvent &e)
    {
        INPUT k = {0};
        k.type = INPUT_KEYBOARD;
        k.ki.dwFlags = e.Pressed ? 0 : KEYEVENTF_KEYUP;
        k.ki.wVk = static_cast<WORD>(ConvertToNative(e.Key));
        if (k.ki.wVk == 255) {
            return; // no good!
        }
        SendInput(1, &k, sizeof(INPUT));
    }
    void SendInput(const MouseButtonEvent &e)
    {
        INPUT inp = {0};
        inp.type = INPUT_MOUSE;
        switch (e.Button) {
        case (MouseButtons::LEFT):
            inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_LEFTUP;
            break;
        case (MouseButtons::RIGHT):
            inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_RIGHTDOWN : MOUSEEVENTF_RIGHTUP;
            break;
        case (MouseButtons::MIDDLE):
            inp.mi.dwFlags = e.Pressed ? MOUSEEVENTF_MIDDLEDOWN : MOUSEEVENTF_MIDDLEUP;
            break;
        default:
            return;
        }
        SendInput(1, &inp, sizeof(INPUT));
    }

    void SendInput(const MouseScrollEvent &e)
    {
        INPUT inp = {0};
        inp.type = INPUT_MOUSE;
        inp.mi.dwFlags = MOUSEEVENTF_WHEEL;
        inp.mi.mouseData = e.Offset * 120;
        SendInput(1, &inp, sizeof(INPUT));
    }

    void SendMousePosition_Impl(int x, int y, int modifier)
    {
        INPUT inp = {0};
        inp.type = INPUT_MOUSE;
        inp.mi.dwFlags = MOUSEEVENTF_MOVE | modifier;
        inp.mi.dx = x;
        inp.mi.dy = y;
        SendInput(1, &inp, sizeof(INPUT));
    }
    void SendInput(const MousePositionOffsetEvent &e) { SendMousePosition_Impl(e.X, e.Y, 0); }
    void SendInput(const MousePositionAbsoluteEvent &e)
    {
        SendMousePosition_Impl((e.X * 65536) / GetSystemMetrics(SM_CXSCREEN), (e.Y * 65536) / GetSystemMetrics(SM_CYSCREEN), MOUSEEVENTF_ABSOLUTE);
    }
}