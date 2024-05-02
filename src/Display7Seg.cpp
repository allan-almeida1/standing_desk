#include "Display7Seg.hpp"

Display7Seg::Display7Seg(uint8_t data_pin, uint8_t shift_clk_pin,
                         uint8_t latch_clk_pin, uint8_t en_disp1_pin,
                         void (*digital_write_func)(uint8_t, uint8_t))
{
    m_data_pin = data_pin;
    m_shitf_clk_pin = shift_clk_pin;
    m_latch_clk_pin = latch_clk_pin;
    m_en_disp1_pin = en_disp1_pin;
    m_digital_write_func = digital_write_func;
}

Display7Seg::~Display7Seg() {}

void Display7Seg::displayNumber(int16_t number)
{
    int digits[3];
    splitDigits(number, digits);
    uint16_t bits = convertToBits(digits);

    // Turn on or off the first digit
    uint16_t first_digit_value = (bits >> 8) & 0xF;
    if (first_digit_value == 0)
    {
        m_digital_write_func(m_en_disp1_pin, 0);
    }
    else
    {
        m_digital_write_func(m_en_disp1_pin, 1);
    }

    // Send the bits to the shift register
    for (int16_t i = 0; i < 12; i++)
    {
        m_digital_write_func(m_data_pin, (uint8_t)(bits & 0b00000001));
        m_digital_write_func(m_shitf_clk_pin, 1);
        m_digital_write_func(m_shitf_clk_pin, 0);
        bits >>= 1;
    }
    m_digital_write_func(m_latch_clk_pin, 1);
    m_digital_write_func(m_latch_clk_pin, 0);
}

void splitDigits(int16_t number, int *digits)
{
    int16_t first_digit = number / 100;
    int16_t second_digit = (number % 100) / 10;
    int16_t third_digit = number % 10;
    digits[0] = first_digit;
    digits[1] = second_digit;
    digits[2] = third_digit;
}

uint16_t convertToBits(int *digits)
{
    uint16_t output = 0b0000000000000000;
    output = output | (digits[0] << 8) | (digits[1] << 4) | (digits[2]);
    return output;
}
