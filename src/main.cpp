#include <Arduino.h>

#define BT0 A1
#define LED LED_BUILTIN

void setup()
{
    pinMode(A0, INPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    TCCR1B = (TCCR1B & 0b11111000) | 0x04;
}

void loop()
{
    if (!digitalRead(A0))
    {
        analogWrite(10, 180);
        digitalWrite(11, LOW);
    }
    else if (!digitalRead(A1))
    {
        analogWrite(11, 180);
        digitalWrite(10, LOW);
    }
    else
    {
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
    }
}
