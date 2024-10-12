#include "../lib/Sensor.h"
#include <cstdlib>

Sensor::Sensor() {
	temperature = 0.0f;
}
Sensor::~Sensor(){ }

void Sensor::setTemperature(float temperature) {
	std::cout << "t = " << std::endl;
	std::cin >> temperature;
}
float Sensor::getTemperature() {
	return temperature;
}

void Sensor::sendToController(){
	Controller controller;
	controller.getParameters(Sensor::getTemperature());
}
