#include <Arduino.h>
#include "AnalogWindowReader.h"
#include "SerialCommunication.h"

AnalogWindowReader reader(A1);
const int BUFFER_LENGTH = 300;
int buffer[BUFFER_LENGTH] = {};
SerialCommunication* serial = SerialCommunication::getInstance();
void setup() {
    Serial.begin(115200);
}

void loop() {
    reader.readSamplesIntoBuffer(buffer, BUFFER_LENGTH);
    serial->sendArray(buffer, BUFFER_LENGTH);
    delay(1000);
}
