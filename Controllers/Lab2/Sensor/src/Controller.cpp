#include "../lib/Controller.h"
#include "../lib/Sensor.h"
#include "../lib/Conection.h"

Controller::Controller(){
	parameter = 0.0f;
}
	
float Controller::getParameters(float valueParam){
	parameter = valueParam;
	return parameter;
}
void Controller::PrintParam(){
	std::cout << parameter;
}

void Controller::process() {
    Conection connection;
    connection.sendData(parameter);
}
