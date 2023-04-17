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
	pwm(uint8_t pin, int frequency, uint8_t resolution, uint8_t channel, bool porcentageORdutyCycle);
	void write(int valor) { w(valor); };
	void w(int valor);

private:
	int ch, pOp, dutyc, pow_res;
};

// NTC sensor class using AnalogRead library
class ntc_cal
{
public:
	ntc_cal(uint8_t pin, float vcc, uint32_t resistor, uint8_t analog_resolution, uint16_t kelvin, uint32_t resistance_25c);
	int16_t read(String reading) { return r(reading); };
	int16_t r(String reading);

private:
	uint8_t p, ar;
	uint16_t k;
	uint32_t r1, r25c;
	float v;
	ESP32AnalogRead NTCreading;
};

// Class for making an analogread
class arRdiverCalc
{
public:
	arRdiverCalc(uint8_t pin, uint8_t analog_resolution, uint16_t mVoltage, uint32_t r1, uint32_t r2);
	// Make a resistor divider voltage calculation;
	float read() { return r(); };
	// Make a resistor divider voltage calculation;
	float r();

private:
	uint8_t resolution;
	uint16_t mVolt;
	float resistor_r1_r2;
	ESP32AnalogRead Vreading;
};

// Class for making an analogread
class IsenseCalcEsp
{
public:
	IsenseCalcEsp(uint8_t pin, uint8_t analog_resolution, uint16_t mVoltage, float shuntResistance);
	// Make a resistor divider voltage calculation;
	uint32_t read() { return r(); };
	// Make a resistor divider voltage calculation;
	uint32_t r();

private:
	uint8_t resolution;
	uint16_t mVolt;
	float shuntR;
	ESP32AnalogRead Vreading;
};
#endif
