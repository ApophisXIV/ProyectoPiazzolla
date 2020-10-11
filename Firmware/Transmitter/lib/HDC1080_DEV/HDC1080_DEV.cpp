
#include "HDC1080_DEV.h"

HDC1080_DEV::HDC1080_DEV()
{
}

void HDC1080_DEV::begin(uint8_t address) {
	_address = address;
	Wire.begin();

	setResolution(HDC1080_RESOLUTION_14BIT, HDC1080_RESOLUTION_14BIT);
}

void HDC1080_DEV::setResolution(HDC1080_MeasurementResolution humidity, HDC1080_MeasurementResolution temperature) {
	HDC1080_Registers reg;
	reg.HumidityMeasurementResolution = 0;
	reg.TemperatureMeasurementResolution = 0;

	if (temperature == HDC1080_RESOLUTION_11BIT)
		reg.TemperatureMeasurementResolution = 0x01;

	switch (humidity)
	{
		case HDC1080_RESOLUTION_8BIT:
			reg.HumidityMeasurementResolution = 0x02;
			break;
		case HDC1080_RESOLUTION_11BIT:
			reg.HumidityMeasurementResolution = 0x01;
			break;
		default:
			break;
	}

	writeRegister(reg);
}

HDC1080_SerialNumber HDC1080_DEV::readSerialNumber() {
	HDC1080_SerialNumber sernum;
	sernum.serialFirst = readData(HDC1080_SERIAL_ID_FIRST);
	sernum.serialMid = readData(HDC1080_SERIAL_ID_MID);
	sernum.serialLast = readData(HDC1080_SERIAL_ID_LAST);
	return sernum;
}

HDC1080_Registers HDC1080_DEV::readRegister() {
	HDC1080_Registers reg;
	reg.rawData = (readData(HDC1080_CONFIGURATION) >> 8);
	return reg;
}

void HDC1080_DEV::writeRegister(HDC1080_Registers reg) {
	Wire.beginTransmission(_address);
	Wire.write(HDC1080_CONFIGURATION);
	Wire.write(reg.rawData);
	Wire.write(0x00);
	Wire.endTransmission();
	delay(10);
}

void HDC1080_DEV::heatUp(uint8_t seconds) {
	HDC1080_Registers reg = readRegister();
	reg.Heater = 1;
	reg.ModeOfAcquisition = 1;
	writeRegister(reg);

	uint8_t buf[4];
	for (int i = 1; i < (seconds*66); i++) {
		Wire.beginTransmission(_address);
		Wire.write(0x00);
		Wire.endTransmission();
		delay(20);
		Wire.requestFrom(_address, (uint8_t)4);
		Wire.readBytes(buf, (size_t)4);
	}
	reg.Heater = 0;
	reg.ModeOfAcquisition = 0;
	writeRegister(reg);
}


double HDC1080_DEV::readT() {
	return readTemperature();
}

double HDC1080_DEV::readTemperature() {
	uint16_t rawT = readData(HDC1080_TEMPERATURE);
	return (rawT / pow(2, 16)) * 165.0 - 40.0;
}

double HDC1080_DEV::readH() {
	return readHumidity();
}

double HDC1080_DEV::readHumidity() {
	uint16_t rawH = readData(HDC1080_HUMIDITY);
	return (rawH / pow(2, 16)) * 100.0;
}

uint16_t HDC1080_DEV::readManufacturerId() {
	return readData(HDC1080_MANUFACTURER_ID);
}

uint16_t HDC1080_DEV::readDeviceId() {
	return readData(HDC1080_DEVICE_ID);
}

uint16_t HDC1080_DEV::readData(uint8_t pointer) {
	Wire.beginTransmission(_address);
	Wire.write(pointer);
	Wire.endTransmission();
	
	delay(9);
	Wire.requestFrom(_address, (uint8_t)2);

	byte msb = Wire.read();
	byte lsb = Wire.read();

	return msb << 8 | lsb;
}



