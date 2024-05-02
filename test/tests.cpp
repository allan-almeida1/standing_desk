#include "include/unit-tests.hpp"
#include "test_buttons.cpp"
#include "test_desk.cpp"
#include "test_display.cpp"

int main()
{
    RUN_ALL_TESTS();
    REMOVE_TEST_FILES();
    return 0;
}