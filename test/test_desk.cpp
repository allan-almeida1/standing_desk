#include "Desk.hpp"
#include "Display7Seg.hpp"
#include "MotorEncoder.hpp"
#include "TactileButtons.hpp"
#include "include/mocks.hpp"
#include "include/unit-tests.hpp"

TEST_CASE(desk_displayNumber)
{
    Display7Seg display(7, 8, 9, 10, &mockDigitalWrite);
    TactileButtons buttons(1, 2, 3, 4, 5, 6, &mockDigitalReadFalse,
                           &mockMillis);
    MotorEncoder left_encoder(3, 20);
    MotorEncoder right_encoder(2, 20);
    Desk desk(11, 12, 13, 14, &mockDigitalWrite, &mockDigitalReadFalse,
              &mockAnalogWrite, display, buttons, left_encoder, right_encoder);
    // desk.displayNumber(110);
}