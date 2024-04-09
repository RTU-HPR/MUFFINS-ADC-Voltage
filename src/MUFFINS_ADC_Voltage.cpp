#include "MUFFINS_ADC_Voltage.h"

ADC_Voltage::ADC_Voltage(String component_name, void (*info_function)(String), void (*error_function)(String)) : Component_Base(component_name, info_function, error_function)
{
  return;
}

ADC_Voltage::~ADC_Voltage()
{
  return;
}

bool ADC_Voltage::begin(const Config &config)
{
  // Check config values
  if (config.R1_value <= 0)
  {
    error("Invalid R1 value");
    return false;
  }

  if (config.R2_value <= 0)
  {
    error("Invalid R2 value");
    return false;
  }

  if (config.reference_voltage <= 0)
  {
    error("Invalid reference voltage");
    return false;
  }

  if (config.adc_resolution <= 0)
  {
    error("Invalid ADC resolution");
    return false;
  }
  
  // Copy the passed config to local config
  _config = config;

  // Calculate the conversion factor
  // C_F = ((R1 + R2) * REF_VOL) / (R2 * ADC_RES)
  _conversion_factor = config.R1_value + config.R2_value;
  _conversion_factor *= (float)config.reference_voltage;
  _conversion_factor /= (float)config.R2_value;
  _conversion_factor /= (float)config.adc_resolution;

  info("Conversion factor: " + String(_conversion_factor, 4));
  info("Initialized");

  return true;
}

bool ADC_Voltage::read(Data &data)
{
  // Read the voltage
  // U = ADC * C_F
  data.voltage = analogRead(_pin) * _conversion_factor;
  return true;
}
