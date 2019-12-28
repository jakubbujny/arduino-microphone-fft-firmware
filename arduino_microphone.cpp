#include <Arduino.h>
#include "AnalogWindowReader.h"
#include "SerialCommunication.h"


#define  BUFFER_LENGTH  500

AnalogWindowReader reader(A5);
uint8_t buffer[BUFFER_LENGTH];
SerialCommunication* serial = SerialCommunication::getInstance();
void setup() {
    Serial.begin(115200);
}

void loop() {
    reader.readSamplesIntoBuffer(buffer, BUFFER_LENGTH);
    serial->sendArray(buffer, BUFFER_LENGTH);
}
