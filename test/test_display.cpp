#include "../include/Display7Seg.hpp"
#include "Types.hpp"
#include "include/mocks.hpp"
#include "include/unit-tests.hpp"

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

TEST_CASE(displayNumber)
{
    Display7Seg display(1, 2, 3, 4, &mockDigitalWrite);
    display.displayNumber(78);
    std::string result = readFromFile("digital_write.txt");
    ASSERT_EQUAL(result,
                 "4,0,1,0,2,1,2,0,1,0,2,1,2,0,1,0,2,1,2,0,1,1,2,1,2,0,"
                 "1,1,2,1,2,0,1,1,2,1,2,0,1,1,2,1,2,0,1,0,2,1,2,0,1,0,"
                 "2,1,2,0,1,0,2,1,2,0,1,0,2,1,2,0,1,0,2,1,2,0,3,1,3,0,");
}