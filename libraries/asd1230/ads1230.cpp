#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "ads1230.h"


ads1230::ads1230(int32_t dout, int32_t sclk, int32_t pdwn)
{
	pinMode(dout, INPUT);
	pinMode(sclk, OUTPUT);
	pinMode(pdwn, OUTPUT);
	_dout = dout;
	_sclk = sclk;
	_pdwn = pdwn;
}

int32_t ads1230::getRawSensor()
{
     for(int8_t a = 0; a < 20; a++) {
        digitalWrite(_sclk, HIGH);
        delayMicroseconds(1);
        _raw <<= 1;
        _raw |= digitalRead(_dout);
        delayMicroseconds(1);
        digitalWrite(_sclk, LOW);
        delayMicroseconds(2);
     }
     _raw <<= 12;
    return _raw;
}


void ads1230::wakeUp()
{
	digitalWrite(_pdwn, HIGH);
}

void ads1230::powerDown()
{
	digitalWrite(_pdwn, LOW);
}

void ads1230::offsetCalibration()
{
     for(int8_t a = 0; a < 26; a++) {
        digitalWrite(_sclk, HIGH);
        delayMicroseconds(2);
        digitalWrite(_sclk, LOW);
        delayMicroseconds(2);
     }
}