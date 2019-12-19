//
// Created by Jakub Bujny on 20/11/2019.
//

#ifndef ARDUINO_MICROPHONE_SERIALCOMMUNICATION_H
#define ARDUINO_MICROPHONE_SERIALCOMMUNICATION_H


class SerialCommunication {
private:
    static SerialCommunication* instance;
    SerialCommunication();
public:
    static SerialCommunication* getInstance();
    void sendArray(uint8_t * array, int length);
};


#endif //ARDUINO_MICROPHONE_SERIALCOMMUNICATION_H
