#include "ina219lib.hpp"
#include <math.h>

USE SERIALIZE AND DESERIALIZE

INA219::I2cBuf 
INA219::pack_register(U8 register_address, U16 register_value)
{
	I2cBuf buf;
	buf.data[0] = register_address;
	buf.data[1] = register_value >> 8;
	buf.data[2] = register_value & 0xFF;
	return buf;
}

INA219::I2cBuf
INA219::configure(int voltage_range, int gain, int bus_adc, int shunt_adc)
{
	int len = sizeof(__BUS_RANGE) / sizeof(__BUS_RANGE[0]);
	if (voltage_range > len-1) {
//		perror("Invalid voltage range, must be one of: RANGE_16V, RANGE_32");
	}
	_voltage_range = voltage_range;
	_gain = gain;

	calibrate(__BUS_RANGE[voltage_range], __GAIN_VOLTS[gain], _max_expected_amps);
	U16 calibration = (voltage_range << __BRNG | _gain << __PG0 | bus_adc << __BADC1 | shunt_adc << __SADC1 | __CONT_SH_BUS);
	return pack_register(__REG_CONFIG, calibration);
}

INA219::I2cBuf
INA219::calibrate(int bus_volts_max, float shunt_volts_max, float max_expected_amps)
{
	float max_possible_amps = shunt_volts_max / _shunt_ohms;
	_current_lsb = determine_current_lsb(max_expected_amps, max_possible_amps);
	_power_lsb = _current_lsb * 20.0;
	U16 calibration = (U16) trunc(__CALIBRATION_FACTOR / (_current_lsb * _shunt_ohms));
	return pack_register(__REG_CALIBRATION, calibration);
}

float
INA219::determine_current_lsb(float max_expected_amps, float max_possible_amps)
{
	float current_lsb;

	float nearest = roundf(max_possible_amps * 1000.0) / 1000.0;
	if (max_expected_amps > nearest) {
		char buffer[65];
		// sprintf(buffer, "Expected current %f A is greater than max possible current %f A", max_expected_amps, max_possible_amps);
		// perror(buffer);
	}

	if (max_expected_amps < max_possible_amps) {
		current_lsb = max_expected_amps / __CURRENT_LSB_FACTOR;
	} else {
		current_lsb = max_possible_amps / __CURRENT_LSB_FACTOR;
	}
	
	if (current_lsb < _min_device_current_lsb) {
		current_lsb = _min_device_current_lsb;
	}
	return current_lsb;
}

float
INA219::voltage()
{
	U16 value = read_register(__REG_BUSVOLTAGE) >> 3;
    return float(value) * __BUS_MILLIVOLTS_LSB / 1000.0;
}

float
INA219::shunt_voltage()
{
	U16 shunt_voltage = read_register(__REG_SHUNTVOLTAGE);
	return __SHUNT_MILLIVOLTS_LSB * (int16_t)shunt_voltage;
}

float
INA219::supply_voltage()
{
	return voltage() + (shunt_voltage() / 1000.0);
}

float
INA219::current()
{
	U16 current_raw = read_register(__REG_CURRENT);
	int16_t current = (int16_t)current_raw;
	if (current > 32767) current -= 65536;
	return  current * _current_lsb * 1000.0;
}

float
INA219::power()
{
	U16 power_raw = read_register(__REG_POWER);
	int16_t power = (int16_t)power_raw;
	return power * _power_lsb * 1000.0;
}
