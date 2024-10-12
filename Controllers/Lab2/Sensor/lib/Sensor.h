#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

class Sensor {
private:
   float temperature;

public:
	Sensor();
	~Sensor();

	void setTemperature();
	float getTemperature();

	void sendToController();
};

#endif