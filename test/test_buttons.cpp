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
    buttons.upPressed(&mockButtonPressed); // 1
    auto now = mockMillis();
    while (mockMillis() - now < 100)
    {
        // Wait for debounce
    }
    // SHOULD DETECT PRESS HERE
    buttons.upPressed(&mockButtonPressed); // 0

    // SHOULD NOT DETECT PRESS HERE
    for (int i = 0; i < 30; i++)
    {
        buttons.upPressed(&mockButtonPressed);
    }

    buttons.upPressed(&mockButtonPressed); // 0
    now = mockMillis();
    while (mockMillis() - now < 52)
    {
        // Wait for debounce
    }
    // SHOULD DETECT PRESS HERE
    buttons.upPressed(&mockButtonPressed); // 0
    std::string result = readFromFile("button_pressed.txt");
    ASSERT_EQUAL(result, "BUTTON PRESSEDBUTTON PRESSED");
}