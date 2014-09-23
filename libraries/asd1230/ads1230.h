#ifndef __ads1230_H__
#define __ads1230_H__

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class ads1230
{
	public:
		ads1230(int32_t  dout, int32_t sclk, int32_t  pdwn);
		int32_t getRawSensor();
		void wakeUp();
		void powerDown();
		void offsetCalibration();
	private:
		int32_t _raw;
		int32_t _dout;
		int32_t _sclk;
		int32_t _pdwn;
};

#endif