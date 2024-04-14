#include <Arduino.h>
#include "MUFFINS_ADC_Voltage.h"

ADC_Voltage battery_voltage;

ADC_Voltage::Config battery_voltage_config = {
    .pin = 26,                
    .adc_resolution = 4095,
    .reference_voltage = 3.3,
    .R1_value = 51000,
    .R2_value = 24000,
};

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1000);
  }

  analogReadResolution(12);
  battery_voltage.begin(battery_voltage_config);
}

void loop()
{
  battery_voltage.read();
  Serial.println("Voltage: " + String(data.voltage) + " V");
  delay(100);
}
