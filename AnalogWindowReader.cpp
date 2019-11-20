//
// Created by Jakub Bujny on 19/11/2019.
//

#include <USBAPI.h>
#include "AnalogWindowReader.h"


void AnalogWindowReader::readSamplesIntoBuffer(int *buffer, int length) {
    for(int i = 0; i < length; i++) {
        buffer[i] = analogRead(this->analogPin);
    }
}

AnalogWindowReader::AnalogWindowReader(uint8_t analogPin) {
    this->analogPin = analogPin;
}
