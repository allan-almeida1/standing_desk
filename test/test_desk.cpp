#include "Desk.hpp"
#include "Display7Seg.hpp"
#include "include/mocks.hpp"
#include "include/unit-tests.hpp"

TEST_CASE(desk_displayNumber)
{
    Display7Seg display(7, 8, 9, 10, &mockDigitalWrite);
    TactileButtons buttons(1, 2, 3, 4, 5, 6, &mockDigitalReadFalse,
                           &mockMillis);
    Desk desk(11, 12, 13, 14, 15, 16, &mockDigitalWrite, &mockDigitalReadFalse,
              &mockAnalogWrite, display, buttons);
    // desk.displayNumber(110);
}