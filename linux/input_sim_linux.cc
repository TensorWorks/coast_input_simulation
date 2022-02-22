#include "input_sim.h"

#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/uinput.h>

namespace Coast
{
    static int InputFd = 0;

    bool InitialiseInputSimulation()
    {
        struct uinput_setup usetup;
    
        int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
        if (fd < 0) {
            fprintf(stderr, "failed to open device %s\n", strerror(errno));
            return false;
        }

        /* enable events */
        ioctl(fd, UI_SET_EVBIT, EV_SYN);
        ioctl(fd, UI_SET_EVBIT, EV_KEY);
        //ioctl(fd, UI_SET_EVBIT, EV_ABS);
        ioctl(fd, UI_SET_EVBIT, EV_REL);

        for(int i = 0; i <= KEY_MAX; i++) {
            ioctl(fd, UI_SET_KEYBIT, i);
        }
    
        ioctl(fd, UI_SET_RELBIT, REL_X);
        ioctl(fd, UI_SET_RELBIT, REL_Y);
        ioctl(fd, UI_SET_RELBIT, REL_HWHEEL);

        // ABS mouse movement setup (seems to be incompatible with other input)
        // ioctl(fd, UI_SET_ABSBIT, ABS_X);
        // ioctl(fd, UI_SET_ABSBIT, ABS_Y);

        // // X Axis
        // uinput_abs_setup uinput_abs_setup_x {
        //     { ABS_X }, // code
        //     {
        //             { 0 }, // value
        //             { 0 }, // minimum
        //             { 6000 }, // maximum
        //             { 0 }, // fuzz
        //             { 0 }, // flat
        //             { 40 }, // resolution
        //     } // absinfo
        // };

        // ioctl(fd, UI_ABS_SETUP, &uinput_abs_setup_x);

        // // Y Axis
        // uinput_abs_setup uinput_abs_setup_y = {
        //     { ABS_Y }, // code
        //     {
        //             { 0 }, // value
        //             { 0 }, // minimum
        //             { 6000 }, // maximum
        //             { 0 }, // fuzz
        //             { 0 }, // flat
        //             { 40 }, // resolution
        //     } // absinfo
        // };

        // ioctl(fd, UI_ABS_SETUP, &uinput_abs_setup_y);

        
        memset(&usetup, 0, sizeof(usetup));
        usetup.id.bustype = BUS_USB;
        usetup.id.vendor = 0x1234; /* sample vendor */
        usetup.id.product = 0x5678; /* sample product */
        strcpy(usetup.name, "Coast input simulation device");
    
        ioctl(fd, UI_DEV_SETUP, &usetup);
        ioctl(fd, UI_DEV_CREATE);

        InputFd = fd;

        sleep(1);
        return true;
    }

    void ReleaseInputSimulation() {
        if(InputFd > 0) {
            ioctl(InputFd, UI_DEV_DESTROY);
            close(InputFd);
            InputFd = 0;
        }
    }

    void EmitInput(int fd, int type, int code, int val) {
        struct input_event ie;

        ie.type = type;
        ie.code = code;
        ie.value = val;
        /* timestamp values below are ignored */
        ie.time.tv_sec = 0;
        ie.time.tv_usec = 0;

        write(fd, &ie, sizeof(ie));
    }

    unsigned char ConvertToNative(KeyCodes key)
    {
        switch(key) {
        case KeyCodes::COAST_A:
            return KEY_A;
        case KeyCodes::COAST_B:
            return KEY_B;
        case KeyCodes::COAST_C:
            return KEY_C;
        case KeyCodes::COAST_D:
            return KEY_D;
        case KeyCodes::COAST_E:
            return KEY_E;
        case KeyCodes::COAST_F:
            return KEY_F;
        case KeyCodes::COAST_G:
            return KEY_G;
        case KeyCodes::COAST_H:
            return KEY_H;
        case KeyCodes::COAST_I:
            return KEY_I;
        case KeyCodes::COAST_J:
            return KEY_J;
        case KeyCodes::COAST_K:
            return KEY_K;
        case KeyCodes::COAST_L:
            return KEY_L;
        case KeyCodes::COAST_M:
            return KEY_M;
        case KeyCodes::COAST_N:
            return KEY_N;
        case KeyCodes::COAST_O:
            return KEY_O;
        case KeyCodes::COAST_P:
            return KEY_P;
        case KeyCodes::COAST_Q:
            return KEY_Q;
        case KeyCodes::COAST_R:
            return KEY_R;
        case KeyCodes::COAST_S:
            return KEY_S;
        case KeyCodes::COAST_T:
            return KEY_T;
        case KeyCodes::COAST_U:
            return KEY_U;
        case KeyCodes::COAST_V:
            return KEY_V;
        case KeyCodes::COAST_W:
            return KEY_W;
        case KeyCodes::COAST_X:
            return KEY_X;
        case KeyCodes::COAST_Y:
            return KEY_Y;
        case KeyCodes::COAST_Z:
            return KEY_Z;
        case KeyCodes::COAST_1:
            return KEY_1;
        case KeyCodes::COAST_2:
            return KEY_2;
        case KeyCodes::COAST_3:
            return KEY_3;
        case KeyCodes::COAST_4:
            return KEY_4;
        case KeyCodes::COAST_5:
            return KEY_5;
        case KeyCodes::COAST_6:
            return KEY_6;
        case KeyCodes::COAST_7:
            return KEY_7;
        case KeyCodes::COAST_8:
            return KEY_8;
        case KeyCodes::COAST_9:
            return KEY_9;
        case KeyCodes::COAST_0:
            return KEY_0;
        case KeyCodes::COAST_Enter:
            return KEY_ENTER;
        case KeyCodes::COAST_Escape:
            return KEY_ESC;
        case KeyCodes::COAST_Backspace:
            return KEY_BACKSPACE;
        case KeyCodes::COAST_Tab:
            return KEY_TAB;
        case KeyCodes::COAST_Space:
            return KEY_SPACE;
        case KeyCodes::COAST_Minus:
            return KEY_MINUS;
        case KeyCodes::COAST_Equals:
            return KEY_EQUAL;
        case KeyCodes::COAST_LeftBracket:
            return KEY_LEFTBRACE;
        case KeyCodes::COAST_RightBracket:
            return KEY_RIGHTBRACE;
        case KeyCodes::COAST_Backslash:
            return KEY_BACKSLASH;
        case KeyCodes::COAST_Semicolon:
            return KEY_SEMICOLON;
        case KeyCodes::COAST_APOSTROPHE:
            return KEY_APOSTROPHE;
        case KeyCodes::COAST_Grave:
            return KEY_GRAVE;
        case KeyCodes::COAST_Comma:
            return KEY_COMMA;
        case KeyCodes::COAST_Period:
            return KEY_DOT;
        case KeyCodes::COAST_Slash:
            return KEY_SLASH;
        case KeyCodes::COAST_CapsLock:
            return KEY_CAPSLOCK;
        case KeyCodes::COAST_F1:
            return KEY_F1;
        case KeyCodes::COAST_F2:
            return KEY_F2;
        case KeyCodes::COAST_F3:
            return KEY_F3;
        case KeyCodes::COAST_F4:
            return KEY_F4;
        case KeyCodes::COAST_F5:
            return KEY_F5;
        case KeyCodes::COAST_F6:
            return KEY_F6;
        case KeyCodes::COAST_F7:
            return KEY_F7;
        case KeyCodes::COAST_F8:
            return KEY_F8;
        case KeyCodes::COAST_F9:
            return KEY_F9;
        case KeyCodes::COAST_F10:
            return KEY_F10;
        case KeyCodes::COAST_F11:
            return KEY_F11;
        case KeyCodes::COAST_F12:
            return KEY_F12;
        case KeyCodes::COAST_F13:
            return KEY_F13;
        case KeyCodes::COAST_F14:
            return KEY_F14;
        case KeyCodes::COAST_F15:
            return KEY_F15;
        case KeyCodes::COAST_F16:
            return KEY_F16;
        case KeyCodes::COAST_F17:
            return KEY_F17;
        case KeyCodes::COAST_F18:
            return KEY_F18;
        case KeyCodes::COAST_F19:
            return KEY_F19;
        case KeyCodes::COAST_F20:
            return KEY_F20;
        case KeyCodes::COAST_F21:
            return KEY_F21;
        case KeyCodes::COAST_F22:
            return KEY_F22;
        case KeyCodes::COAST_F23:
            return KEY_F23;
        case KeyCodes::COAST_F24:
            return KEY_F24;
        case KeyCodes::COAST_PrintScreen:
            return KEY_PRINT;
        case KeyCodes::COAST_ScrollLock:
            return KEY_SCROLLLOCK;
        case KeyCodes::COAST_Pause:
            return KEY_PAUSE;
        case KeyCodes::COAST_Insert:
            return KEY_INSERT;
        case KeyCodes::COAST_Home:
            return KEY_HOME;
        case KeyCodes::COAST_PageUp:
            return KEY_PAGEUP;
        case KeyCodes::COAST_Delete:
            return KEY_DELETE;
        case KeyCodes::COAST_End:
            return KEY_END;
        case KeyCodes::COAST_PageDown:
            return KEY_PAGEDOWN;
        case KeyCodes::COAST_Right:
            return KEY_RIGHT;
        case KeyCodes::COAST_Left:
            return KEY_LEFT;
        case KeyCodes::COAST_Down:
            return KEY_DOWN;
        case KeyCodes::COAST_Up:
            return KEY_UP;
        case KeyCodes::COAST_KP_NumLock:
            return KEY_NUMLOCK;
        case KeyCodes::COAST_KP_Divide:
            return KEY_KPSLASH;
        case KeyCodes::COAST_KP_Asterisk:
            return KEY_KPASTERISK;
        case KeyCodes::COAST_KP_Subtract:
            return KEY_KPMINUS;
        case KeyCodes::COAST_KP_Add:
            return KEY_KPPLUS;
        case KeyCodes::COAST_KP_Enter:
            return KEY_KPENTER;
        case KeyCodes::COAST_KP_1:
            return KEY_KP1;
        case KeyCodes::COAST_KP_2:
            return KEY_KP2;
        case KeyCodes::COAST_KP_3:
            return KEY_KP3;
        case KeyCodes::COAST_KP_4:
            return KEY_KP4;
        case KeyCodes::COAST_KP_5:
            return KEY_KP5;
        case KeyCodes::COAST_KP_6:
            return KEY_KP6;
        case KeyCodes::COAST_KP_7:
            return KEY_KP7;
        case KeyCodes::COAST_KP_8:
            return KEY_KP8;
        case KeyCodes::COAST_KP_9:
            return KEY_KP9;
        case KeyCodes::COAST_KP_0:
            return KEY_KP0;
        case KeyCodes::COAST_KP_Period:
            return KEY_KPDOT;
        case KeyCodes::COAST_Help:
            return KEY_HELP;
        case KeyCodes::COAST_Menu:
            return KEY_MENU;
        case KeyCodes::COAST_LeftControl:
            return KEY_LEFTCTRL;
        case KeyCodes::COAST_LeftShift:
            return KEY_LEFTSHIFT;
        case KeyCodes::COAST_LeftAlt:
            return KEY_LEFTALT;
        case KeyCodes::COAST_LeftMeta:
            return KEY_LEFTMETA;
        case KeyCodes::COAST_RightControl:
            return KEY_RIGHTCTRL;
        case KeyCodes::COAST_RightShift:
            return KEY_RIGHTSHIFT;
        case KeyCodes::COAST_RightAlt:
            return KEY_RIGHTALT;
        case KeyCodes::COAST_RightMeta:
            return KEY_RIGHTMETA;
        default:
            return 0;
        }
    }

    KeyCodes ConvertToKeyCode(unsigned char key)
    {
        switch(key) {
        case KEY_ESC:
            return KeyCodes::COAST_Escape;
        case KEY_1:
            return KeyCodes::COAST_1;
        case KEY_2:
            return KeyCodes::COAST_2;
        case KEY_3:
            return KeyCodes::COAST_3;
        case KEY_4:
            return KeyCodes::COAST_4;
        case KEY_5:
            return KeyCodes::COAST_5;
        case KEY_6:
            return KeyCodes::COAST_6;
        case KEY_7:
            return KeyCodes::COAST_7;
        case KEY_8:
            return KeyCodes::COAST_8;
        case KEY_9:
            return KeyCodes::COAST_9;
        case KEY_0:
            return KeyCodes::COAST_0;
        case KEY_MINUS:
            return KeyCodes::COAST_Minus;
        case KEY_EQUAL:
            return KeyCodes::COAST_Equals;
        case KEY_BACKSPACE:
            return KeyCodes::COAST_Backspace;
        case KEY_TAB:
            return KeyCodes::COAST_Tab;
        case KEY_Q:
            return KeyCodes::COAST_Q;
        case KEY_W:
            return KeyCodes::COAST_W;
        case KEY_E:
            return KeyCodes::COAST_E;
        case KEY_R:
            return KeyCodes::COAST_R;
        case KEY_T:
            return KeyCodes::COAST_T;
        case KEY_Y:
            return KeyCodes::COAST_Y;
        case KEY_U:
            return KeyCodes::COAST_U;
        case KEY_I:
            return KeyCodes::COAST_I;
        case KEY_O:
            return KeyCodes::COAST_O;
        case KEY_P:
            return KeyCodes::COAST_P;
        case KEY_LEFTBRACE:
            return KeyCodes::COAST_LeftBracket;
        case KEY_RIGHTBRACE:
            return KeyCodes::COAST_RightBracket;
        case KEY_ENTER:
            return KeyCodes::COAST_Enter;
        case KEY_LEFTCTRL:
            return KeyCodes::COAST_LeftControl;
        case KEY_A:
            return KeyCodes::COAST_A;
        case KEY_S:
            return KeyCodes::COAST_S;
        case KEY_D:
            return KeyCodes::COAST_D;
        case KEY_F:
            return KeyCodes::COAST_F;
        case KEY_G:
            return KeyCodes::COAST_G;
        case KEY_H:
            return KeyCodes::COAST_H;
        case KEY_J:
            return KeyCodes::COAST_J;
        case KEY_K:
            return KeyCodes::COAST_K;
        case KEY_L:
            return KeyCodes::COAST_L;
        case KEY_SEMICOLON:
            return KeyCodes::COAST_Semicolon;
        case KEY_APOSTROPHE:
            return KeyCodes::COAST_APOSTROPHE;
        case KEY_GRAVE:
            return KeyCodes::COAST_Grave;
        case KEY_LEFTSHIFT:
            return KeyCodes::COAST_LeftShift;
        case KEY_BACKSLASH:
            return KeyCodes::COAST_Backslash;
        case KEY_Z:
            return KeyCodes::COAST_Z;
        case KEY_X:
            return KeyCodes::COAST_X;
        case KEY_C:
            return KeyCodes::COAST_C;
        case KEY_V:
            return KeyCodes::COAST_V;
        case KEY_B:
            return KeyCodes::COAST_B;
        case KEY_N:
            return KeyCodes::COAST_N;
        case KEY_M:
            return KeyCodes::COAST_M;
        case KEY_COMMA:
            return KeyCodes::COAST_Comma;
        case KEY_DOT:
            return KeyCodes::COAST_Period;
        case KEY_SLASH:
            return KeyCodes::COAST_Slash;
        case KEY_RIGHTSHIFT:
            return KeyCodes::COAST_RightShift;
        case KEY_KPASTERISK:
            return KeyCodes::COAST_KP_Asterisk;
        case KEY_LEFTALT:
            return KeyCodes::COAST_LeftAlt;
        case KEY_SPACE:
            return KeyCodes::COAST_Space;
        case KEY_CAPSLOCK:
            return KeyCodes::COAST_CapsLock;
        case KEY_F1:
            return KeyCodes::COAST_F1;
        case KEY_F2:
            return KeyCodes::COAST_F2;
        case KEY_F3:
            return KeyCodes::COAST_F3;
        case KEY_F4:
            return KeyCodes::COAST_F4;
        case KEY_F5:
            return KeyCodes::COAST_F5;
        case KEY_F6:
            return KeyCodes::COAST_F6;
        case KEY_F7:
            return KeyCodes::COAST_F7;
        case KEY_F8:
            return KeyCodes::COAST_F8;
        case KEY_F9:
            return KeyCodes::COAST_F9;
        case KEY_F10:
            return KeyCodes::COAST_F10;
        case KEY_F11:
            return KeyCodes::COAST_F11;
        case KEY_F12:
            return KeyCodes::COAST_F12;
        case KEY_F13:
            return KeyCodes::COAST_F13;
        case KEY_F14:
            return KeyCodes::COAST_F14;
        case KEY_F15:
            return KeyCodes::COAST_F15;
        case KEY_F16:
            return KeyCodes::COAST_F16;
        case KEY_F17:
            return KeyCodes::COAST_F17;
        case KEY_F18:
            return KeyCodes::COAST_F18;
        case KEY_F19:
            return KeyCodes::COAST_F19;
        case KEY_F20:
            return KeyCodes::COAST_F20;
        case KEY_F21:
            return KeyCodes::COAST_F21;
        case KEY_F22:
            return KeyCodes::COAST_F22;
        case KEY_F23:
            return KeyCodes::COAST_F23;
        case KEY_F24:
            return KeyCodes::COAST_F24;
        case KEY_NUMLOCK:
            return KeyCodes::COAST_KP_NumLock;
        case KEY_SCROLLLOCK:
            return KeyCodes::COAST_ScrollLock;
        case KEY_KP7:
            return KeyCodes::COAST_KP_7;
        case KEY_KP8:
            return KeyCodes::COAST_KP_8;
        case KEY_KP9:
            return KeyCodes::COAST_KP_9;
        case KEY_KPMINUS:
            return KeyCodes::COAST_KP_Subtract;
        case KEY_KP4:
            return KeyCodes::COAST_KP_4;
        case KEY_KP5:
            return KeyCodes::COAST_KP_5;
        case KEY_KP6:
            return KeyCodes::COAST_KP_6;
        case KEY_KPPLUS:
            return KeyCodes::COAST_KP_Add;
        case KEY_KP1:
            return KeyCodes::COAST_KP_1;
        case KEY_KP2:
            return KeyCodes::COAST_KP_2; 
        case KEY_KP3:
            return KeyCodes::COAST_KP_3;
        case KEY_KP0:
            return KeyCodes::COAST_KP_0;
        case KEY_KPDOT:
            return KeyCodes::COAST_KP_Period;
        case KEY_KPENTER:
            return KeyCodes::COAST_KP_Enter;
        case KEY_RIGHTCTRL:
            return KeyCodes::COAST_RightControl;
        case KEY_KPSLASH:
            return KeyCodes::COAST_KP_Divide;
        case KEY_PRINT:
            return KeyCodes::COAST_PrintScreen;
        case KEY_RIGHTALT:
            return KeyCodes::COAST_RightAlt;
        case KEY_HOME:
            return KeyCodes::COAST_Home;
        case KEY_UP:
            return KeyCodes::COAST_Up;
        case KEY_PAGEUP:
            return KeyCodes::COAST_PageUp;
        case KEY_LEFT:
            return KeyCodes::COAST_Left;
        case KEY_RIGHT:
            return KeyCodes::COAST_Right;
        case KEY_END:
            return KeyCodes::COAST_End;
        case KEY_DOWN:
            return KeyCodes::COAST_Down;
        case KEY_PAGEDOWN:
            return KeyCodes::COAST_PageDown;
        case KEY_INSERT:
            return KeyCodes::COAST_Insert;
        case KEY_DELETE:
            return KeyCodes::COAST_Delete;
        case KEY_KPEQUAL:
            return KeyCodes::COAST_KP_Equals;
        case KEY_PAUSE:
            return KeyCodes::COAST_Pause; 
        case KEY_LEFTMETA:
            return KeyCodes::COAST_LeftMeta;
        case KEY_RIGHTMETA:
            return KeyCodes::COAST_RightMeta;
        case KEY_MENU:
            return KeyCodes::COAST_Menu;
        case KEY_HELP:
            return KeyCodes::COAST_Help;
        default:
            return KeyCodes::INVALID;
        }
    }

    void SendInput(const KeyEvent& e)
    {
        auto mappedkey = ConvertToNative(e.Key);
        if(mappedkey == KeyCodes::INVALID)
            return;

        EmitInput(InputFd, EV_KEY, mappedkey, e.Pressed ? 1 : 0);
        EmitInput(InputFd, EV_SYN, SYN_REPORT, 0);
    }

    void SendInput(const MouseButtonEvent& e)
    {
        switch(e.Button) {
        case MouseButtons::LEFT:
            EmitInput(InputFd, EV_KEY, BTN_LEFT, e.Pressed ? 1 : 0);
            break;
        case MouseButtons::MIDDLE:
            EmitInput(InputFd, EV_KEY, BTN_MIDDLE, e.Pressed ? 1 : 0);
            break;
        case MouseButtons::RIGHT:
            EmitInput(InputFd, EV_KEY, BTN_RIGHT, e.Pressed ? 1 : 0);
            break;
        default:
            return;
        }

        EmitInput(InputFd, EV_SYN, SYN_REPORT, 0);
    }

    void SendInput(const MouseScrollEvent& e)
    {
        EmitInput(InputFd, EV_REL, REL_HWHEEL, e.Offset);
        EmitInput(InputFd, EV_SYN, SYN_REPORT, 0);
    }

    void SendInput(const MousePositionOffsetEvent& e)
    {
        EmitInput(InputFd, EV_REL, REL_X, e.X);
        EmitInput(InputFd, EV_REL, REL_Y, e.Y);
        EmitInput(InputFd, EV_SYN, SYN_REPORT, 0);
    }

    void SendInput(const MousePositionAbsoluteEvent& e)
    {
        static bool errMsgDelivered = false;
        if(!errMsgDelivered)
        {
            fprintf(stderr, "Absolute position events not supported for Linux yet.\n");
            errMsgDelivered = true;
        }
        return;

        EmitInput(InputFd, EV_ABS, ABS_X, e.X);
        EmitInput(InputFd, EV_ABS, ABS_Y, e.Y);
        EmitInput(InputFd, EV_SYN, SYN_REPORT, 0);
    }
}