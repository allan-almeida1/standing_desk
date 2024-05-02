#include "../include/Display.hpp"
#include "include/unit-tests.hpp"
#include <vector>

TEST_CASE(splitDigits)
{
    int number = 123;
    int digits[3];
    splitDigits(number, digits);
    ASSERT_EQUAL(digits[0], 1);
    ASSERT_EQUAL(digits[1], 2);
    ASSERT_EQUAL(digits[2], 3);

    number = 79;
    splitDigits(number, digits);
    ASSERT_EQUAL(digits[0], 0);
    ASSERT_EQUAL(digits[1], 7);
    ASSERT_EQUAL(digits[2], 9);

    number = 5;
    splitDigits(number, digits);
    ASSERT_EQUAL(digits[0], 0);
    ASSERT_EQUAL(digits[1], 0);
    ASSERT_EQUAL(digits[2], 5);
}

TEST_CASE(convertToBits)
{
    int digits[3] = {4, 3, 5};
    unsigned int bits = convertToBits(digits);
    ASSERT_EQUAL(bits, 0b0000010000110101);

    int number = 89;
    splitDigits(number, digits);
    bits = convertToBits(digits);
    ASSERT_EQUAL(bits, 0b0000000010001001);

    number = 5;
    splitDigits(number, digits);
    bits = convertToBits(digits);
    ASSERT_EQUAL(bits, 0b0000000000000101);
}

void mockDigitalWrite(uint8_t pin, uint8_t value)
{
    std::cout << "Pin: " << (int)pin << " Value: " << (int)value << std::endl;
}

TEST_CASE(displayNumber)
{
    uint8_t data_pin = 1;
    uint8_t shift_clk_pin = 2;
    uint8_t latch_clk_pin = 3;
    uint8_t en_disp1_pin = 4;

    Display display(data_pin, shift_clk_pin, latch_clk_pin, en_disp1_pin,
                    &mockDigitalWrite);

    display.displayNumber(395);
}