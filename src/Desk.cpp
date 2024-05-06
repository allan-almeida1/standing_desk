#include "Desk.hpp"

Desk::Desk(IController &controller, IDisplay &display, IButtons &buttons,
           IEncoder &left_encoder, IEncoder &right_encoder)
    : m_controller(controller), m_display(display), m_buttons(buttons),
      m_left_encoder(left_encoder), m_right_encoder(right_encoder)
{
}

Desk::~Desk() {}

void Desk::displayNumber(int16_t number) { m_display.displayNumber(number); }

void Desk::handleButtonEvent(ButtonIndex button, Btcb press_cb, Btcb release_cb,
                             Btcb short_press_cb, Btcb long_press_cb,
                             Btcb held_cb)
{
    m_buttons.handleButtonEvent(button, press_cb, release_cb, short_press_cb,
                                long_press_cb, held_cb);
}

void Desk::rotateMotor(uint8_t pin, int value, int direction)
{
    m_controller.rotateMotor(pin, value, direction);
}

void Desk::stopMotor(uint8_t pin) { m_controller.stopMotor(pin); }