#include <ads1230.h>

int ADS1230_DOUT = 3; //Pin for DRDY/DOUT of ADS1230
int ADS1230_SCLK = 4; //Pin for SCLK of ADS1230
int ADS1230_NPDWN = 5; //Pin for nPDWN of ADS1230

ads1230 ads(ADS1230_DOUT, ADS1230_SCLK, ADS1230_NPDWN);

void setup()
{
  Serial.begin  (9600);
  Serial.println(F("Adafruit Bluefruit Low Energy nRF8001 Print echo demo"));
  ads.wakeUp();
  delay(100);
  ads.offsetCalibration();
}
void loop() 
{
  ads.wakeUp(); 
  delay(100);
  Serial.println(ads.getRawSensor(), BIN);
  delay(1000);
}
