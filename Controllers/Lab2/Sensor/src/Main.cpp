#include "../lib/Controller.h"
#include "../lib/Sensor.h"

int main() {
	Controller controller;
	Sensor sensor;
	
	  while (true) {
        sensor.setTemperature();
        sensor.sendToController(controller);
        controller.process();
        controller.getParameters();
    }
	return 0;
}
