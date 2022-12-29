# Utils Various Arduino for Esp32

Library with various functions for the Arduino framework.

## ☕ Using this library

To use this library, you need to download, install the library, and include the following file in your project:

```
#include <utils_various.h>
```

Also download the [Esp32AnalogRead](https://github.com/madhephaestus/ESP32AnalogRead) to work with the library.

In this library, you have:

[pwm - Control the PWM on Esp32](https://github.com/shiroichiheisen/Utils-Various-Arduino-ESP32#pwm-function)

[ntc_cal - ntc Reading Calibrated on the ESP32](https://github.com/shiroichiheisen/Utils-Various-Arduino-ESP32#ntc_cal-function) 

[psram - PSRAM tools](https://github.com/shiroichiheisen/Utils-Various-Arduino-ESP32#psram-tools)
---

## pwm function:

The PWM function is a wrapper on the ledc PWM from the ESP32, this part only works with the ESP32, but with better code readability, to use declare the object with the pin, frequency of the PWM, resolution of the PWM, PWM channel and if you will use percentage or duty cycle:

```
pwm mosfet(int mosfetPin, int pwmFrequency, int pwmResolution, int pwmChannel, int porcentageORdutyCycle);
```

To change the PWM on the pin just call the object with the value you want to write:

```
mosfet.w(int pwmValue);
mosfet.write(int pwmValue);
```

---

## ntc_cal function:

Read an NTC with the [Analog Read library](https://github.com/madhephaestus/ESP32AnalogRead) with the following connection:

GND---NTC---PIN---RESISTOR---VCC

Declare the NTC object with the pin to read, VCC voltage on the resistor, analog read resolution, the NTC kelvin and NTC resistance at 25° celsius:

```
ntc_cal tempSensor(int sensorPin, float vcc, int resistor, int analog_resolution, int kelvin, int resistance_25c)
```

After declared, read the NTC with the celsius, fahrenheit or Kelvin temperature preference:

"c" for celsius

"f" for fahrenheit

"k" for kelvin

```
tempSensor.r(String temperatureSelection);
tempSensor.read(String temperatureSelection);
```

---

## psram tools:

Some tools to facilitate using the PSRAM on ESP32

```
// Define an int on PSRAM
int *intVar = PSRAMInt;

// Define an float on PSRAM
float *floatVar = PSRAMFloat;

// Define an char on PSRAM with the size (bytes) you want - Ex: char *cereal = PSRAMChar(10); - you can save an word with 10 characters max ("Applejacks")
char *charVar = PSRAMChar(n_elements);

// Define an int array on PSRAM with the size of elements you want - Ex: int *intArray = PSRAMIntArray(10)
int *intVarArray = PSRAMIntArray(n_elements);

// Define an float array on PSRAM with the size of elements you want - Ex: float *intArray = PSRAMIntArray(10)
float *floatArray = PSRAMFloatArray(n_elements);

// Define an char array on PSRAM with the size of elements you want - Ex: char *intArray = PSRAMIntArray(10)
char *charArray = PSRAMCharArray(n_elements);
```