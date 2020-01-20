#include <Arduino.h>
#include "AnalogWindowReader.h"
#include "SerialCommunication.h"


#define  BUFFER_LENGTH  250

AnalogWindowReader reader(A5);
uint8_t buffer[BUFFER_LENGTH];
SerialCommunication* serial = SerialCommunication::getInstance();
void setup() {
    Serial.begin(115200);
}

void loop() {
    unsigned long start = micros();
    reader.readSamplesIntoBuffer(buffer, BUFFER_LENGTH);
    unsigned long end = micros();
    unsigned long delta = end - start;
    Serial.println(delta);

    serial->sendArray(buffer, BUFFER_LENGTH);
}
