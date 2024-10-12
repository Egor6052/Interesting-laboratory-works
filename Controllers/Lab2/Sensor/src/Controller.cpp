#include "../lib/Controller.h"
#include "../lib/Sensor.h"
#include "../lib/Conection.h"

Controller::Controller() {
	parameter = 0.0f;
}

void Controller::setParameters(float valueParam) {
	this->parameter = valueParam;
}

float Controller::getParameters() {
	std::cout << "Parameter: " << parameter << std::endl;
	return parameter;
}

void Controller::process() {
    Conection connection;
    connection.sendData(parameter);
}
