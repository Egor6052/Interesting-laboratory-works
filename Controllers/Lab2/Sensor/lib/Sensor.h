#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

class Sensor {
private:
   float temperature;

public:
	Sensor();
	~Sensor();

	void setTemperature(float temperature);
	float getTemperature();

	void sendToController();
};

#endif