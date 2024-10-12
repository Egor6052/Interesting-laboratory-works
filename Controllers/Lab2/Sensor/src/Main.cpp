#include "../lib/Controller.h"
#include "../lib/Sensor.h"

int main() {
	Sensor sensor;
	sensor.setTemperature();

    Controller controller;
    controller.process();

    controller.PrintParam();
    return 0;
}
