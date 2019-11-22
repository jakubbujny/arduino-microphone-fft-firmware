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

void SerialCommunication::sendArray(int *array, int length) {
    String output = "b,";

    for(int i = 0; i < length; i++) {
        output += String(array[i]) + ",";
    }
    Serial.write(output.c_str());
    Serial.write("\n");
}
