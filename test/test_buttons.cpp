#include "TactileButtons.hpp"
#include "Types.hpp"
#include "include/fileio.hpp"
#include "include/mocks.hpp"
#include "include/unit-tests.hpp"
#include <iostream>

TEST_CASE(debounceButton)
{
    TactileButtons buttons(1, 2, 3, 4, 5, 6, &mockDigitalReadToggle2,
                           &mockMillis);
    buttons.upPressed(&mockButtonPressed); // 1
    buttons.upPressed(&mockButtonPressed); // 1
    buttons.upPressed(&mockButtonPressed); // 0
    buttons.upPressed(&mockButtonPressed); // 0
    buttons.upPressed(&mockButtonPressed); // 1
    buttons.upPressed(&mockButtonPressed); // 1
    buttons.upPressed(&mockButtonPressed); // 0
    auto now = mockMillis();
    while (mockMillis() - now < 100)
    {
        // Wait for debounce
    }
    // SHOULD DETECT PRESS HERE
    buttons.upPressed(&mockButtonPressed); // 0
    std::string result = readFromFile("button_pressed.txt");
    ASSERT_EQUAL(result, "BUTTON PRESSED");
}