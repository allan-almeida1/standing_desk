#include "Desk.hpp"

Desk::Desk(uint8_t pwml_pin1, uint8_t pwml_pin2, uint8_t pwmr_pin1,
           uint8_t pwmr_pin2, void (*digital_write_func)(uint8_t, uint8_t),
           int (*digital_read_func)(uint8_t),
           void (*analog_write_func)(uint8_t, int), IDisplay &display,
           IButtons &buttons, IEncoder &left_encoder, IEncoder &right_encoder)
    : m_display(display), m_buttons(buttons), m_left_encoder(left_encoder),
      m_right_encoder(right_encoder)
{
    m_pwml_pin1 = pwml_pin1;
    m_pwml_pin2 = pwml_pin2;
    m_pwmr_pin1 = pwmr_pin1;
    m_pwmr_pin2 = pwmr_pin2;
    m_digital_write_func = digital_write_func;
    m_digital_read_func = digital_read_func;
    m_analog_write_func = analog_write_func;
}

Desk::~Desk() {}

void Desk::displayNumber(int16_t number) { m_display.displayNumber(number); }

void Desk::handleUpButton(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                          Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleUpButton(press_cb, release_cb, short_press_cb,
                             long_press_cb, held_cb);
}

void Desk::handleDownButton(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                            Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleDownButton(press_cb, release_cb, short_press_cb,
                               long_press_cb, held_cb);
}

void Desk::handleMemButton(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                           Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleMemButton(press_cb, release_cb, short_press_cb,
                              long_press_cb, held_cb);
}

void Desk::handleButton1(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                         Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleButton1(press_cb, release_cb, short_press_cb, long_press_cb,
                            held_cb);
}

void Desk::handleButton2(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                         Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleButton2(press_cb, release_cb, short_press_cb, long_press_cb,
                            held_cb);
}

void Desk::handleButton3(Btcb press_cb, Btcb release_cb, Btcb short_press_cb,
                         Btcb long_press_cb, Btcb held_cb)
{
    m_buttons.handleButton3(press_cb, release_cb, short_press_cb, long_press_cb,
                            held_cb);
}
