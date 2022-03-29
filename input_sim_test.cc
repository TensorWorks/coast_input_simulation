#include "input_sim.h"
#include <chrono>
#include <thread>

#include <math.h>
#define PI 3.14159265

void keyboard_test()
{
    fprintf(stdout, "Starting Keyboard Test\n");

    // 0 ms
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_LeftMeta});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_LeftMeta});
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_D});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_D});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_L});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_L});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_Space});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_Space});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_Y});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_Y});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_S});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_T});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_E});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_M});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_M});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_3});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_3});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_2});
    std::this_thread::sleep_for(std::chrono::milliseconds(25)); 
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_2});
    // 1250 ms

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    Coast::SendInput(Coast::KeyEvent{true, Coast::KeyCodes::COAST_Escape});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::KeyEvent{false, Coast::KeyCodes::COAST_Escape});
    // 4275 ms
}

void mouse_test()
{
    fprintf(stdout, "Starting Mouse Absolute Position Test\n");

    // 0 ms
    Coast::SendInput(Coast::MousePositionAbsoluteEvent{50, 50});
    std::this_thread::sleep_for(std::chrono::milliseconds(5));

    Coast::SendInput(Coast::MouseButtonEvent{true, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    Coast::SendInput(Coast::MouseButtonEvent{false, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Coast::SendInput(Coast::MouseButtonEvent{true, Coast::MouseButtons::LEFT});
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
    // 1055 ms

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
    // 6480 ms

    fprintf(stdout, "Starting Mouse Relative Position Test\n");

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
    // 10530 ms
}

int main(int argc, char* argv[]) {

    if(!Coast::InitialiseInputSimulation())
        fprintf(stderr, "Test failed: Failed to initialise input simulation");

    keyboard_test();
    mouse_test();
    Coast::ReleaseInputSimulation();

    return 0;
}