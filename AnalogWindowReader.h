//
// Created by Jakub Bujny on 19/11/2019.
//

#ifndef ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H
#define ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))

#include <stdint.h>

class AnalogWindowReader {
private:
    uint8_t analogPin;
public:
    explicit AnalogWindowReader(uint8_t analogPin);

    void readSamplesIntoBuffer(uint8_t *buffer, int length);

};


#endif //ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H
