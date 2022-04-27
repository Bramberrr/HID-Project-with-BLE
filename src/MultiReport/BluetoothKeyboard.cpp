#include "BluetoothKeyboard.h"

static const uint8_t _hidMultiReportDescriptorKeyboard[] PROGMEM = {
    //  Keyboard
    0x05, 0x01,                      /* USAGE_PAGE (Generic Desktop)	  47 */
    0x09, 0x06,                      /* USAGE (Keyboard) */
    0xa1, 0x01,                      /* COLLECTION (Application) */
    0x85, HID_REPORTID_KEYBOARD,	 /*   REPORT_ID TODO order important? */
    0x05, 0x07,                      /*   USAGE_PAGE (Keyboard) */

    /* Keyboard Modifiers (shift, alt, ...) */
    0x19, 0xe0,                      /*   USAGE_MINIMUM (Keyboard LeftControl) */
    0x29, 0xe7,                      /*   USAGE_MAXIMUM (Keyboard Right GUI) */
    0x15, 0x00,                      /*   LOGICAL_MINIMUM (0) */
    0x25, 0x01,                      /*   LOGICAL_MAXIMUM (1) */
    0x75, 0x01,                      /*   REPORT_SIZE (1) */
	0x95, 0x08,                      /*   REPORT_COUNT (8) */
    0x81, 0x02,                      /*   INPUT (Data,Var,Abs) */

    /* Reserved byte, used for consumer reports, only works with linux */
	0x05, 0x0C,             		 /*   Usage Page (Consumer) */
    0x95, 0x01,                      /*   REPORT_COUNT (1) */
    0x75, 0x08,                      /*   REPORT_SIZE (8) */
    0x15, 0x00,                      /*   LOGICAL_MINIMUM (0) */
    0x26, 0xFF, 0x00,                /*   LOGICAL_MAXIMUM (255) */
    0x19, 0x00,                      /*   USAGE_MINIMUM (0) */
    0x29, 0xFF,                      /*   USAGE_MAXIMUM (255) */
    0x81, 0x00,                      /*   INPUT (Data,Ary,Abs) */

    /* 6 Keyboard keys */
    0x05, 0x07,                      /*   USAGE_PAGE (Keyboard) */
    0x95, 0x06,                      /*   REPORT_COUNT (6) */
    0x75, 0x08,                      /*   REPORT_SIZE (8) */
    0x15, 0x00,                      /*   LOGICAL_MINIMUM (0) */
    0x26, 0xE7, 0x00,                /*   LOGICAL_MAXIMUM (231) */
    0x19, 0x00,                      /*   USAGE_MINIMUM (Reserved (no event indicated)) */
    0x29, 0xE7,                      /*   USAGE_MAXIMUM (Keyboard Right GUI) */
    0x81, 0x00,                      /*   INPUT (Data,Ary,Abs) */

    /* End */
    0xc0                            /* END_COLLECTION */
};

BluetoothKeyboard_::BluetoothKeyboard_(uint8_t receivePin, uint8_t transmitPin, long speed) 
{
	bluetoothHost = new SoftwareSerial(receivePin, transmitPin);
    bluetoothHost->begin(speed);
    static HIDSubDescriptor node(_hidMultiReportDescriptorKeyboard, sizeof(_hidMultiReportDescriptorKeyboard));
	HID().AppendDescriptor(&node);
}


int BluetoothKeyboard_::send(void)
{
	byte send_buf[] = {
        0x0C, 0x00, 0xA1, 0x01,
        _keyReport.keys[0],
        // _keyReport.keys[1],
        0x00,
        _keyReport.keys[2],
        _keyReport.keys[3],
        _keyReport.keys[4],
        _keyReport.keys[5],
        _keyReport.keys[6],
        _keyReport.keys[7]
    };
    bluetoothHost->write(send_buf, 12);
    
}


// BluetoothKeyboard_ BluetoothKeyboard;