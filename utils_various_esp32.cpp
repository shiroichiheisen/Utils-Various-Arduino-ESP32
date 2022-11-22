#include "utils_various_esp32.h"

pwm::pwm(int pin, int frequency, int adc_resolution, int channel, int porcentageORdutyCycle)
{
  pow_res = pow(2, adc_resolution);
  pOp = porcentageORdutyCycle;
  ch = channel;
  ledcSetup(channel, frequency, adc_resolution);
  ledcAttachPin(pin, channel);
}

void pwm::w(int valor)
{
  if (pwm_porcentage)
    dutyc = map(valor, 0, 100, 0, pow_res);
  else
    dutyc = valor;
  ledcWrite(ch, dutyc);
}

void pwm::write(int valor)
{
  if (pOp)
    dutyc = map(valor, 0, 100, 0, pow_res);
  else
    dutyc = map(valor, 0, pow_res, 0, pow_res);
  ledcWrite(ch, dutyc);
}

ntc_cal::ntc_cal(int pin, float vcc, int resistor, int analog_resolution, int kelvin, int resistance_25c)
{
  // p = pin;
  v = vcc;
  r1 = resistor;
  ar = analog_resolution;
  k = kelvin;
  r25c = resistance_25c;
  NTCreading.attach(pin);
}

float ntc_cal::r(String reading)
{
  float RT, VR, ln, TX, T0, VRT;
  int choose = 0;
  T0 = 25 + 273.15;

  VRT = NTCreading.readRaw();
  VRT = (v / (pow(2, ar) - 1)) * VRT;
  VR = v - VRT;
  RT = VRT / (VR / r1);

  ln = log(RT / r25c);
  TX = (1 / ((ln / k) + (1 / T0)));

  TX = TX - 273.15;

  if (reading == "c")
    choose = TX;
  if (reading == "f")
    choose = ((TX * 1.8) + 32);
  if (reading == "k")
    choose = TX + 273.15;

  return choose;
}
float ntc_cal::read(String reading)
{
  float RT, VR, ln, TX, T0, VRT;
  int choose = 0;
  T0 = 25 + 273.15;

  VRT = NTCreading.readRaw();
  VRT = (v / (pow(2, ar) - 1)) * VRT;
  VR = v - VRT;
  RT = VRT / (VR / r1);

  ln = log(RT / r25c);
  TX = (1 / ((ln / k) + (1 / T0)));

  TX = TX - 273.15;

  if (reading == "c")
    choose = TX;
  if (reading == "f")
    choose = ((TX * 1.8) + 32);
  if (reading == "k")
    choose = TX + 273.15;

  return choose;
}