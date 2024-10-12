#include "../lib/Sensor.h"
#include "../lib/Controller.h"

Sensor::Sensor() {
	temperature = 0.0f;
}
Sensor::~Sensor() { }

void Sensor::setTemperature() {
	float temp;
	std::cout << "t = ";
	std::cin >> temp;
	this->temperature = temp;
}

float Sensor::getTemperature() {
	return temperature;
}

void Sensor::sendToController(Controller& controller) {
    controller.setParameters(getTemperature());
}
