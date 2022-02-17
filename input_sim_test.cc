#include "input_sim.h"
#include <chrono>
#include <thread>

#include <math.h>
#define PI 3.14159265

void keyboard_test()
{
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_LeftMeta});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_LeftMeta});
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_D});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_D});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_L});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_L});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_Space});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_Space});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_Y});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_Y});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_M});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_M});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_3});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_3});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_2});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_2});

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::KEY_Escape});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::KEY_Escape});
}

void mouse_test()
{
    Coast::SendInput(Coast::MousePositionAbsoluteEvent{50, 50});
    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    Coast::SendInput(Coast::MouseButtonEvent{true, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::MouseButtonEvent{false, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Coast::SendInput(Coast::MouseButtonEvent{true, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    for(int i = 0; i < 360; i++) {
        const int offset = 300;
        const int radius = 200;
        double rads = ((double)i)/(180.0 / PI);
        int x = offset + ((int)(sin(rads) * radius));
        int y = offset + ((int)(cos(rads) * radius));

        Coast::SendInput(Coast::MousePositionAbsoluteEvent{x, y});
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }

    Coast::SendInput(Coast::MouseButtonEvent{false, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    Coast::SendInput(Coast::MouseButtonEvent{true, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));

    for (int i = 0; i < 20; i++)
    {
        Coast::SendInput(Coast::MousePositionOffsetEvent{20, 0});
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        Coast::SendInput(Coast::MousePositionOffsetEvent{0, 20});
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    Coast::SendInput(Coast::MouseButtonEvent{false, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
}

int main(int argc, char* argv[]) {

    keyboard_test();
    mouse_test();

    return 0;
}