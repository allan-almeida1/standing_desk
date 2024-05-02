#include "Desk.hpp"

Desk::Desk(uint8_t pwml_pin1, uint8_t pwml_pin2, uint8_t pwmr_pin1,
           uint8_t pwmr_pin2, uint8_t speed_sensor_l_pin,
           uint8_t speed_sensor_r_pin,
           void (*digital_write_func)(uint8_t, uint8_t),
           int (*digital_read_func)(uint8_t),
           void (*analog_write_func)(uint8_t, int), IDisplay &display,
           IButtons &buttons)
    : m_display(display), m_buttons(buttons)
{
    m_pwml_pin1 = pwml_pin1;
    m_pwml_pin2 = pwml_pin2;
    m_pwmr_pin1 = pwmr_pin1;
    m_pwmr_pin2 = pwmr_pin2;
    m_speed_sensor_l_pin = speed_sensor_l_pin;
    m_speed_sensor_r_pin = speed_sensor_r_pin;
    m_digital_write_func = digital_write_func;
    m_digital_read_func = digital_read_func;
    m_analog_write_func = analog_write_func;
}

Desk::~Desk() {}

void Desk::displayNumber(int16_t number) { m_display.displayNumber(number); }