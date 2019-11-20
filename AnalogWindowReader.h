//
// Created by Jakub Bujny on 19/11/2019.
//

#ifndef ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H
#define ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H


#include <stdint.h>

class AnalogWindowReader {
private:
    uint8_t analogPin;
public:
    explicit AnalogWindowReader(uint8_t analogPin);

    void readSamplesIntoBuffer(int *buffer, int length);

};


#endif //ARDUINO_MICROPHONE_ANALOGWINDOWREADER_H
