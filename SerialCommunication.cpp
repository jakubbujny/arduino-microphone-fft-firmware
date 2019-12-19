//
// Created by Jakub Bujny on 20/11/2019.
//

#include <HardwareSerial.h>
#include "SerialCommunication.h"

SerialCommunication* SerialCommunication::instance;

SerialCommunication* SerialCommunication::getInstance() {
    if(instance == 0) {
        instance = new SerialCommunication();
    }
    return instance;
}

SerialCommunication::SerialCommunication() {
    Serial.begin(115200);
}

void SerialCommunication::sendArray(uint8_t *array, int length) {
    Serial.write(array, length);
    Serial.println();
}
