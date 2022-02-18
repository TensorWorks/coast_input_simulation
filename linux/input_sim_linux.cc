#include "input_sim.h"

#include <iostream>
#include <linux/uinput.h>

namespace Coast
{
    unsigned char ConvertToNative(KeyCodes key)
    {
        switch(key) {
        case KeyCodes::COAST_A:
            return 38;
        case KeyCodes::COAST_B:
            return 56;
        case KeyCodes::COAST_C:
            return 54;
        case KeyCodes::COAST_D:
            return 40;
        case KeyCodes::COAST_E:
            return 26;
        case KeyCodes::COAST_F:
            return 41;
        case KeyCodes::COAST_G:
            return 42;
        case KeyCodes::COAST_H:
            return 43;
        case KeyCodes::COAST_I:
            return 31;
        case KeyCodes::COAST_J:
            return 44;
        case KeyCodes::COAST_K:
            return 45;
        case KeyCodes::COAST_L:
            return 46;
        case KeyCodes::COAST_M:
            return 58;
        case KeyCodes::COAST_N:
            return 57;
        case KeyCodes::COAST_O:
            return 32;
        case KeyCodes::COAST_P:
            return 33;
        case KeyCodes::COAST_Q:
            return 24;
        case KeyCodes::COAST_R:
            return 27;
        case KeyCodes::COAST_S:
            return 39;
        case KeyCodes::COAST_T:
            return 28;
        case KeyCodes::COAST_U:
            return 30;
        case KeyCodes::COAST_V:
            return 55;
        case KeyCodes::COAST_W:
            return 25;
        case KeyCodes::COAST_X:
            return 53;
        case KeyCodes::COAST_Y:
            return 29;
        case KeyCodes::COAST_Z:
            return 52;
        case KeyCodes::COAST_1:
            return 10;
        case KeyCodes::COAST_2:
            return 11;
        case KeyCodes::COAST_3:
            return 12;
        case KeyCodes::COAST_4:
            return 13;
        case KeyCodes::COAST_5:
            return 14;
        case KeyCodes::COAST_6:
            return 15;
        case KeyCodes::COAST_7:
            return 16;
        case KeyCodes::COAST_8:
            return 17;
        case KeyCodes::COAST_9:
            return 18;
        case KeyCodes::COAST_0:
            return 19;
        case KeyCodes::COAST_Enter:
            return 36;
        case KeyCodes::COAST_Escape:
            return 9;
        case KeyCodes::COAST_Backspace:
            return 22;
        case KeyCodes::COAST_Tab:
            return 23;
        case KeyCodes::COAST_Space:
            return 65;
        case KeyCodes::COAST_Minus:
            return 20;
        case KeyCodes::COAST_Equals:
            return 21;
        case KeyCodes::COAST_LeftBracket:
            return 34;
        case KeyCodes::COAST_RightBracket:
            return 35;
        case KeyCodes::COAST_Backslash:
            return 51;
        case KeyCodes::COAST_Semicolon:
            return 47;
        case KeyCodes::COAST_Quote:
            return 48;
        case KeyCodes::COAST_Grave:
            return 49;
        case KeyCodes::COAST_Comma:
            return 59;
        case KeyCodes::COAST_Period:
            return 60;
        case KeyCodes::COAST_Slash:
            return 61;
        case KeyCodes::COAST_CapsLock:
            return 66;
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
            return 67 + (key - KeyCodes::COAST_F1);
        case KeyCodes::COAST_F11:
            return 95;
        case KeyCodes::COAST_F12:
            return 96;
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
            return 191 + (key - KeyCodes::COAST_F13);
        case KeyCodes::COAST_PrintScreen:
            return 107;
        case KeyCodes::COAST_ScrollLock:
            return 78;
        case KeyCodes::COAST_Pause:
            return 127;
        case KeyCodes::COAST_Insert:
            return 118;
        case KeyCodes::COAST_Home:
            return 110;
        case KeyCodes::COAST_PageUp:
            return 112;
        case KeyCodes::COAST_Delete:
            return 119;
        case KeyCodes::COAST_End:
            return 115;
        case KeyCodes::COAST_PageDown:
            return 117;
        case KeyCodes::COAST_Right:
            return 114;
        case KeyCodes::COAST_Left:
            return 113;
        case KeyCodes::COAST_Down:
            return 116;
        case KeyCodes::COAST_Up:
            return 111;
        case KeyCodes::KP_NumLock:
            return 77;
        case KeyCodes::KP_Divide:
            return 106;
        case KeyCodes::KP_Multiply:
            return 63;
        case KeyCodes::KP_Subtract:
            return 82;
        case KeyCodes::KP_Add:
            return 86;
        case KeyCodes::KP_Enter:
            return 104;
        case KeyCodes::KP_1:
            return 87;
        case KeyCodes::KP_2:
            return 88;
        case KeyCodes::KP_3:
            return 89;
        case KeyCodes::KP_4:
            return 83;
        case KeyCodes::KP_5:
            return 84;
        case KeyCodes::KP_6:
            return 85;
        case KeyCodes::KP_7:
            return 79;
        case KeyCodes::KP_8:
            return 80;
        case KeyCodes::KP_9:
            return 81;
        case KeyCodes::KP_0:
            return 90;
        case KeyCodes::KP_Point:
            return 91;
        case KeyCodes::COAST_Help:
            return 146;
        case KeyCodes::COAST_Menu:
            return 135;
        case KeyCodes::COAST_LeftControl:
            return 37;
        case KeyCodes::COAST_LeftShift:
            return 50;
        case KeyCodes::COAST_LeftAlt:
            return 64;
        case KeyCodes::COAST_LeftMeta:
            return 133;
        case KeyCodes::COAST_RightControl:
            return 105;
        case KeyCodes::COAST_RightShift:
            return 62;
        case KeyCodes::COAST_RightAlt:
            return 108;
        case KeyCodes::COAST_RightMeta:
            return 134;
        default:
            return 255;
        }
    }

    KeyCodes ConvertToKeyCode(unsigned char key)
    {
        switch(key) {
        case 9:
            return KeyCodes::COAST_Escape;
        case 10:
            return KeyCodes::COAST_1;
        case 11:
            return KeyCodes::COAST_2;
        case 12:
            return KeyCodes::COAST_3;
        case 13:
            return KeyCodes::COAST_4;
        case 14:
            return KeyCodes::COAST_5;
        case 15:
            return KeyCodes::COAST_6;
        case 16:
            return KeyCodes::COAST_7;
        case 17:
            return KeyCodes::COAST_8;
        case 18:
            return KeyCodes::COAST_9;
        case 19:
            return KeyCodes::COAST_0;
        case 20:
            return KeyCodes::COAST_Minus;
        case 21:
            return KeyCodes::COAST_Equals;
        case 22:
            return KeyCodes::COAST_Backspace;
        case 23:
            return KeyCodes::COAST_Tab;
        case 24:
            return KeyCodes::COAST_Q;
        case 25:
            return KeyCodes::COAST_W;
        case 26:
            return KeyCodes::COAST_E;
        case 27:
            return KeyCodes::COAST_R;
        case 28:
            return KeyCodes::COAST_T;
        case 29:
            return KeyCodes::COAST_Y;
        case 30:
            return KeyCodes::COAST_U;
        case 31:
            return KeyCodes::COAST_I;
        case 32:
            return KeyCodes::COAST_O;
        case 33:
            return KeyCodes::COAST_P;
        case 34:
            return KeyCodes::COAST_LeftBracket;
        case 35:
            return KeyCodes::COAST_RightBracket;
        case 36:
            return KeyCodes::COAST_Enter;
        case 37:
            return KeyCodes::COAST_LeftControl;
        case 38:
            return KeyCodes::COAST_A;
        case 39:
            return KeyCodes::COAST_S;
        case 40:
            return KeyCodes::COAST_D;
        case 41:
            return KeyCodes::COAST_F;
        case 42:
            return KeyCodes::COAST_G;
        case 43:
            return KeyCodes::COAST_H;
        case 44:
            return KeyCodes::COAST_J;
        case 45:
            return KeyCodes::COAST_K;
        case 46:
            return KeyCodes::COAST_L;
        case 47:
            return KeyCodes::COAST_Semicolon;
        case 48:
            return KeyCodes::COAST_Quote;
        case 49:
            return KeyCodes::COAST_Grave;
        case 50:
            return KeyCodes::COAST_LeftShift;
        case 51:
            return KeyCodes::COAST_Backslash;
        case 52:
            return KeyCodes::COAST_Z;
        case 53:
            return KeyCodes::COAST_X;
        case 54:
            return KeyCodes::COAST_C;
        case 55:
            return KeyCodes::COAST_V;
        case 56:
            return KeyCodes::COAST_B;
        case 57:
            return KeyCodes::COAST_N;
        case 58:
            return KeyCodes::COAST_M;
        case 59:
            return KeyCodes::COAST_Comma;
        case 60:
            return KeyCodes::COAST_Period;
        case 61:
            return KeyCodes::COAST_Slash;
        case 62:
            return KeyCodes::COAST_RightShift;
        case 63:
            return KeyCodes::KP_Multiply;
        case 64:
            return KeyCodes::COAST_LeftAlt;
        case 65:
            return KeyCodes::COAST_Space;
        case 66:
            return KeyCodes::COAST_CapsLock;
        case 67: // f1
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76: // f10
            return static_cast<KeyCodes>(KeyCodes::COAST_F1 + (key - 67));
        case 77:
            return KeyCodes::KP_NumLock;
        case 78:
            return KeyCodes::COAST_ScrollLock;
        case 79:
            return KeyCodes::KP_7;
        case 80:
            return KeyCodes::KP_8;
        case 81:
            return KeyCodes::KP_9;
        case 82:
            return KeyCodes::KP_Subtract;
        case 83:
            return KeyCodes::KP_4;
        case 84:
            return KeyCodes::KP_5;
        case 85:
            return KeyCodes::KP_6;
        case 86:
            return KeyCodes::KP_Add;
        case 87:
            return KeyCodes::KP_1;
        case 88:
            return KeyCodes::KP_2; 
        case 89:
            return KeyCodes::KP_3;
        case 90:
            return KeyCodes::KP_0;
        case 91:
            return KeyCodes::KP_Point;
        case 94:
            return KeyCodes::COAST_NonUSBackslash;
        case 95:
            return KeyCodes::COAST_F11;
        case 96:
            return KeyCodes::COAST_F12;
        case 104:
            return KeyCodes::KP_Enter;
        case 105:
            return KeyCodes::COAST_RightControl;
        case 106:
            return KeyCodes::KP_Divide;
        case 107:
            return KeyCodes::COAST_PrintScreen;
        case 108:
            return KeyCodes::COAST_RightAlt;
        case 110:
            return KeyCodes::COAST_Home;
        case 111:
            return KeyCodes::COAST_Up;
        case 112:
            return KeyCodes::COAST_PageUp;
        case 113:
            return KeyCodes::COAST_Left;
        case 114:
            return KeyCodes::COAST_Right;
        case 115:
            return KeyCodes::COAST_End;
        case 116:
            return KeyCodes::COAST_Down;
        case 117:
            return KeyCodes::COAST_PageDown;
        case 118:
            return KeyCodes::COAST_Insert;
        case 119:
            return KeyCodes::COAST_Delete;
        case 125:
            return KeyCodes::KP_Equals;
        case 127:
            return KeyCodes::COAST_Pause; 
        case 133:
            return KeyCodes::COAST_LeftMeta;
        case 134:
            return KeyCodes::COAST_RightMeta;
        case 135:
            return KeyCodes::COAST_Menu;
            case 146:
            return KeyCodes::COAST_Help;
        case 191://f13
        case 192:
        case 193:
        case 194:
        case 195:
        case 196:
        case 197:
        case 198:
        case 199:
        case 200:
        case 201:
        case 202:
            return static_cast<KeyCodes>(KeyCodes::COAST_F13 + (key - 191));
        default:
            return KeyCodes::INVALID;
        }
    }

    void SendInput(const KeyEvent& e)
    {
        auto mappedkey = ConvertToNative(e.Key);
        if(mappedkey == 255)
            return; // key doesnt exist 
    }

    void SendInput(const MouseButtonEvent& e)
    {
        switch(e.Button) {
        case MouseButtons::LEFT:
            break;
        case MouseButtons::MIDDLE:
            break;
        case MouseButtons::RIGHT:
            break;
        default:
            break;
        }
    }

    void SendInput(const MouseScrollEvent& e)
    {
        if(e.Offset < 0) {
            for(auto i = 0; i < abs(e.Offset) && i < 5; i++) { /// cap at 5
            }
        } else if(e.Offset > 0) {
            for(auto i = 0; i < e.Offset && i < 5; i++) { /// cap at 5
            }
        }
    }

    void SendInput(const MousePositionOffsetEvent& e)
    {
    }

    void SendInput(const MousePositionAbsoluteEvent& e)
    {
    }
}