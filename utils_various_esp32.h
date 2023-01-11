#ifndef utils_various_esp32_
#define utils_various_esp32_

#include <Arduino.h>
#include <ESP32AnalogRead.h>

#define pwm_porcentage 0
#define pwm_dutyCycle 1

// Define an int on PSRAM
#define PSRAMInt (int *)ps_malloc(sizeof(int))
// Define an float on PSRAM
#define PSRAMFloat (float *)ps_malloc(sizeof(float))
// Define an char on PSRAM with the size (bytes) you want - Ex: char *cereal = PSRAMChar(10); - you can save an word with 10 characters max ("Applejacks")
#define PSRAMChar(size) (char *)ps_calloc(1, size)
// Define an int array on PSRAM with the size of elements you want - Ex: int *intArray = PSRAMIntArray(10)
#define PSRAMIntArray(n_elements) (int *)ps_malloc(n_elements * sizeof(int))
// Define an float array on PSRAM with the size of elements you want - Ex: float *intArray = PSRAMIntArray(10)
#define PSRAMFloatArray(n_elements) (float *)ps_malloc(n_elements * sizeof(float))
// Define an char array on PSRAM with the size of elements you want - Ex: char *intArray = PSRAMIntArray(10)
#define PSRAMCharArray(n_elements) (char *)ps_malloc(n_elements * sizeof(char))

// Class for making an pwm write
class pwm
{
public:
	pwm(int pin, int frequency, int adc_resolution, int channel, int porcentageORdutyCycle);
	void write(int valor) { w(valor); };
	void w(int valor);

private:
	int ch, pOp, dutyc, pow_res;
};

// NTC sensor class using AnalogRead library
class ntc_cal
{
public:
	ntc_cal(int pin, float vcc, int resistor, int analog_resolution, int kelvin, int resistance_25c);
	float read(String reading) { return r(reading); };
	float r(String reading);

private:
	float p, v, r1, ar, k, r25c;
	ESP32AnalogRead NTCreading;
};

// Class for making an analogread
class arRdiverCalc
{
public:
	arRdiverCalc(int pin, int analog_resolution, int mVoltage, int r1, int r2);
	// Make a resistor divider voltage calculation;
	float read() { return r(); };
	// Make a resistor divider voltage calculation;
	float r();

private:
	int resolution, mVolt;
	float resistor_r1_r2;
	ESP32AnalogRead Vreading;
};
#endif
