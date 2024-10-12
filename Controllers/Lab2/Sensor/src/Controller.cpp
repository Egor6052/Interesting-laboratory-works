#include "../lib/Controller.h"
#include "Sensor.h"
#include "Conection.h"

Controller::Controller(){
	parameter = 0.0f;
}
	
float Controller::getParameters(float valueParam){
	parameter = valueParam;
}

void Controller::process() {
    Conection connection;
    connection.sendData(parameter);
}
