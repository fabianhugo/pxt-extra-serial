#include "pxt.h"
#if MICROBIT_CODAL
    #include "NRF52Serial.h"
    #define MICROBIT_USB_SERIAL_WAKE 1
#endif

#define MICROBIT_SERIAL_READ_BUFFER_LENGTH 64

enum ExtraSerialPin {
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2,
    P3 = MICROBIT_ID_IO_P3,
    C8 = MICROBIT_ID_IO_P8,
    C9 = MICROBIT_ID_IO_P9,
    C12 = MICROBIT_ID_IO_P12,
    C13 = MICROBIT_ID_IO_P13,
    C14 = MICROBIT_ID_IO_P14,
    C15 = MICROBIT_ID_IO_P15,
    A1_RX = MICROBIT_ID_IO_A1_RX,
    A1_TX = MICROBIT_ID_IO_A1_TX,
    A0_SCL = MICROBIT_ID_IO_A0_SCL,
    A1_SCL = MICROBIT_ID_IO_A0_SDA
    
};

enum ExtraBaudRate {
  //% block=115200
  BaudRate115200 = 115200,
  //% block=57600
  BaudRate57600 = 57600,
  //% block=38400
  BaudRate38400 = 38400,
  //% block=31250
  BaudRate31250 = 31250,
  //% block=28800
  BaudRate28800 = 28800,
  //% block=19200
  BaudRate19200 = 19200,
  //% block=14400
  BaudRate14400 = 14400,
  //% block=9600
  BaudRate9600 = 9600,
  //% block=4800
  BaudRate4800 = 4800,
  //% block=2400
  BaudRate2400 = 2400,
  //% block=1200
  BaudRate1200 = 1200
};

namespace extraserial {
#if MICROBIT_CODAL
    NRF52Serial * extraSerial = NULL;
    void checkSerialPort() {
        if( extraSerial != NULL )
            return;
        
        extraSerial = new NRF52Serial( uBit.io.P0, uBit.io.P1, NRF_UARTE1 );
        // own event bus ID, otherwise our events collide with uBit.serial (DEVICE_ID_SERIAL)
        extraSerial->id = CodalComponent::generateDynamicID();
        extraSerial->setBaud( 9600 );
    }
#endif

    // note that at least one // followed by % is needed per declaration!

    //%
    String readUntil(String delimiter) {
        #if MICROBIT_CODAL
            checkSerialPort();
            return PSTR(extraSerial->readUntil(MSTR(delimiter)));
        #else
            return mkString("", 0);
        #endif
    }

    //%
    void onDataReceived(String delimiters, Action body) {
        #if MICROBIT_CODAL
            checkSerialPort();
            extraSerial->eventOn(MSTR(delimiters));
            registerWithDal(extraSerial->id, MICROBIT_SERIAL_EVT_DELIM_MATCH, body);
            // lazy initialization of serial buffers
            extraSerial->read(MicroBitSerialMode::ASYNC);
        #endif
    }

    //%
    String readString() {
        #if MICROBIT_CODAL
            checkSerialPort();
            int n = extraSerial->getRxBufferSize();
            if (n == 0)
                return mkString("", 0);
            return PSTR(extraSerial->read(n, MicroBitSerialMode::ASYNC));
        #else
            return mkString("", 0);
        #endif
    }



    //%
    void writeString(String text) {
        #if MICROBIT_CODAL
            checkSerialPort();
            if (!text)
                return;

            extraSerial->send(MSTR(text));
        #endif
    }

    //%
    void writeBuffer(Buffer buffer) {
        #if MICROBIT_CODAL
            checkSerialPort();
            if (!buffer)
                return;

            extraSerial->send(buffer->data, buffer->length);
        #endif
    }

    //%
    Buffer readBuffer(int length) {
        #if MICROBIT_CODAL
            checkSerialPort();
            auto mode = SYNC_SLEEP;
            if (length <= 0) {
                length = extraSerial->getRxBufferSize();
                mode = ASYNC;
            }

            auto buf = mkBuffer(NULL, length);
            auto res = buf;
            registerGCObj(buf); // make sure buffer is pinned, while we wait for data
            int read = extraSerial->read(buf->data, buf->length, mode);
            if (read != length) {
                res = mkBuffer(buf->data, read);
            }
            unregisterGCObj(buf);

            return res;
        #else
            return mkBuffer(NULL, length);
        #endif
    }

    //% 
    bool tryResolvePin(ExtraSerialPin p, PinName& name) {
        auto pin = getPin(p); 
        if (NULL != pin) {
            name = (PinName)pin->name;
            return true;
        }
        return false;
    }

    //%
    void redirect(ExtraSerialPin tx, ExtraSerialPin rx, ExtraBaudRate rate) {
        #if MICROBIT_CODAL
            checkSerialPort();
            if (getPin(tx) && getPin(rx)) {
                extraSerial->redirect(*getPin(tx), *getPin(rx));
            }
            extraSerial->setBaud(rate);
        #endif
    }

    //%
    void setBaudRate(ExtraBaudRate rate) {
        #if MICROBIT_CODAL
            checkSerialPort();
            extraSerial->setBaud(rate);
        #endif
    }

    //%
    void setRxBufferSize(uint8_t size) {
        #if MICROBIT_CODAL
            checkSerialPort();
            extraSerial->setRxBufferSize(size);
        #endif
    }

    //%
    void setTxBufferSize(uint8_t size) {
        #if MICROBIT_CODAL
            checkSerialPort();
            extraSerial->setTxBufferSize(size);
        #endif
    }
}