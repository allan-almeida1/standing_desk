/**
 * @file Display.hpp
 * @brief Display class declaration
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "interface/IDisplay.hpp"
#include <Arduino.h>

/**
 * @brief 7-Segment Display class
 */
class Display7Seg final : public IDisplay
{
  public:
    Display7Seg(uint8_t data_pin, uint8_t shift_clk_pin, uint8_t latch_clk_pin,
                uint8_t en_disp1_pin);
    ~Display7Seg();

    /**
     * @brief Display a number
     *
     * @param number Numer to be displayed
     */
    void displayNumber(int16_t number) override;

  private:
    uint8_t m_data_pin;      // Data pin
    uint8_t m_shitf_clk_pin; // Shift clock pin
    uint8_t m_latch_clk_pin; // Latch clock pin
    uint8_t m_en_disp1_pin;  // Enable Display 1 pin
};

/**
 * @brief Split a number into its 3 digits
 *
 * @param number The number to be split
 * @param digits The array to store the digits
 */
void splitDigits(int16_t number, int *digits);

/**
 * @brief Convert 3 digits into 12 bits for display. Each digit
 * is converted into 4 bits. For example, the number 123 is converted
 * into 0001 0010 0011
 *
 * @param digits The array of digits
 *
 * @return 16-bit uint16_teger representing the 12 bits
 */
uint16_t convertToBits(int *digits);

#endif