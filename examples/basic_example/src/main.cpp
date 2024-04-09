#include <Arduino.h>
#include "MUFFINS_ADC_Voltage.h"

ADC_Voltage battery_voltage;

ADC_Voltage::Config battery_voltage_config = {
  .pin = A0,
  .adc_resolution = 1024,
  .reference_voltage = 5.0,
  .R1_value = 10000,
  .R2_value = 10000
};

ADC_Voltage::Data data;

void setup()
{
  Serial.begin(9600);
  while(!Serial)
  {
    delay(1000);
  }
  
  battery_voltage.begin(battery_voltage_config);
}

void loop()
{
  battery_voltage.read(data);
  Serial.println("Voltage: " + String(data.voltage) + " V");
  delay(100);
}
