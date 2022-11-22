#ifndef utils_various_esp32_
#define utils_various_esp32_

#include <Arduino.h>
#include <ESP32AnalogRead.h>

#define pwm_porcentage 0
#define pwm_dutyCycle 1

// Class for making an pwm write
class pwm
{
public:
	pwm(int pin, int frequency, int adc_resolution, int channel, int porcentageORdutyCycle);
	void w(int valor);
	void write(int valor);

private:
	int ch, pOp, dutyc, pow_res;
};

// NTC sensor class using AnalogRead library
class ntc_cal
{
public:
	ntc_cal(int pin, float vcc, int resistor, int analog_resolution, int kelvin, int resistance_25c);
	float r(String reading);
	float read(String reading);

private:
	float p, v, r1, ar, k, r25c;
	ESP32AnalogRead NTCreading;
};
#endif
