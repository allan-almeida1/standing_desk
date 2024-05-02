#include "Desk.hpp"
#include "Display7Seg.hpp"
#include <Arduino.h>

Display7Seg display(2, 3, 4, 5, &digitalWrite);
Desk desk(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, &digitalWrite,
          &digitalRead, &analogWrite, display);

void setup() { TCCR1B = (TCCR1B & 0b11111000) | 0x04; }

void loop() {}
