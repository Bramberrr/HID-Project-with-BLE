#pragma once

#include <Arduino.h>
#include "HID.h"
#include "HID-Settings.h"
#include "../HID-APIs/DefaultKeyboardAPI.h"
#include <SoftwareSerial.h>


class BluetoothKeyboard_ : public DefaultKeyboardAPI
{
public:
    BluetoothKeyboard_(uint8_t receivePin, uint8_t transmitPin, long speed);

    virtual inline int send(void) final;
private:
    SoftwareSerial* bluetoothHost;
};
// extern BluetoothKeyboard_ BluetoothKeyboard;
