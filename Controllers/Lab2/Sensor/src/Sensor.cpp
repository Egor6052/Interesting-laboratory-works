#include "../lib/Sensor.h"
#include "../lib/Controller.h"
// #include <cstdlib>

Sensor::Sensor() {
	temperature = 0.0f;
}
Sensor::~Sensor(){ }

void Sensor::setTemperature() {
	std::cout << "t = ";
	std::cin >> temperature;
}

float Sensor::getTemperature() {
	return temperature;
}

void Sensor::sendToController(){
	Controller controller;
	controller.getParameters(getTemperature());
}
