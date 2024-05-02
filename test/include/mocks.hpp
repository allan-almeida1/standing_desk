/**
 * @brief Mocks for unit tests
 * @file mocks.hpp
 * @author Allan Almeida
 * @date 2024-05-01
 */

#ifndef MOCKS_HPP
#define MOCKS_HPP

#include "Types.hpp"
#include "fileio.hpp"
#include <chrono>
#include <iostream>

void mockDigitalWrite(uint8_t pin, uint8_t value)
{
    std::cout << "Mocked digitalWrite(" << (int)pin << ", " << (int)value << ")"
              << std::endl;
    writeToFile("digital_write.txt",
                std::to_string(pin) + "," + std::to_string(value) + ",");
}

void mockAnalogWrite(uint8_t pin, int value)
{
    std::cout << "Mocked analogWrite(" << (int)pin << ", " << (int)value << ")"
              << std::endl;
}

int mockDigitalReadFalse(uint8_t pin)
{
    std::cout << "Mocked digitalRead(" << (int)pin << ") = 0" << std::endl;
    return 0;
}

int mockDigitalReadTrue(uint8_t pin)
{
    std::cout << "Mocked digitalRead(" << (int)pin << ") = 1" << std::endl;
    return 1;
}

int mockDigitalReadToggle(uint8_t pin)
{
    static bool state = false;
    state = !state;
    std::cout << "Mocked digitalRead(" << (int)pin << ") = " << state
              << std::endl;
    return state;
}

int mockDigitalReadToggle2(uint8_t pin)
{
    static bool state = false;
    static int count = 0;
    if (count % 2 == 0)
    {
        state = !state;
    }
    count++;
    std::cout << "Mocked digitalRead(" << (int)pin << ") = " << state
              << std::endl;
    return state;
}

unsigned long mockMillis()
{
    auto now = std::chrono::high_resolution_clock::now();
    unsigned long millis =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch())
            .count();
    return millis;
}

void mockButtonPressed()
{
    std::cout << "-------- BUTTON PRESSED --------" << std::endl;
    writeToFile("button_pressed.txt", "BUTTON PRESSED\n");
}

#endif // MOCKS_HPP