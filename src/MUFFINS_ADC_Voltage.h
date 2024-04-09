/*
  This library is used for the to read voltage from a voltage divider circuit.
*/
#pragma once
#include "MUFFINS_Component_Base.h"

class ADC_Voltage : public Component_Base
{
public:
  struct Config
  {
    int pin;                 // Pin to read from
    int adc_resolution;      // ADC resolution
    float reference_voltage; // MCU voltage
    int R1_value;            // Resistor connected to positive
    int R2_value;            // Resistor connected to ground
  };

  /**
   * @brief Structure to hold battery data.
   */
  struct Data
  {
    float voltage;
  };

private:
  Config _config;
  float _conversion_factor;

public:
  /**
   * @brief Construct a new ADC Voltage reader instance
   */
  ADC_Voltage(String component_name = "Analog Voltage", void (*info_function)(String) = nullptr, void (*error_function)(String) = nullptr);

  /**
   * @brief Destroys the ADC Voltage sensor instance.
   */
  ~ADC_Voltage();

  /**
   * @brief Initializes the reader.
   *
   * @param config The configuration object containing the settings.
   * @return True if the initialization is successful, false otherwise.
   */
  bool begin(const Config &config);

  /**
   * @brief Reads the  voltage.
   *
   * @param data The data structure to store the read data in.
   * @return True if the data was successfully read, false otherwise.
   */
  bool read(Data &data);
};
