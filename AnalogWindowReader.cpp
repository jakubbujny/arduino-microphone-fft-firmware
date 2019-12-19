//
// Created by Jakub Bujny on 19/11/2019.
//

#include <USBAPI.h>
#include "AnalogWindowReader.h"




void AnalogWindowReader::readSamplesIntoBuffer(uint8_t *buffer, int length) {

    for(int i = 0; i < length; i++) {
        sbi(ADCSRA, ADSC);
        while (bit_is_set(ADCSRA, ADSC));
        buffer[i] = ADCL;
        int t = ADCH;
    }
}

AnalogWindowReader::AnalogWindowReader(uint8_t analogPin) {
    this->analogPin = analogPin;
    analogRead(this->analogPin);
}
