#include "../lib/Controller1.h"
#include "../lib/Conection.h"
#include "../lib/Panel.h"

Controller1::Controller1(){
	temperature = 0;
}

void Controller1::process() {
    Conection connection;
    Panel panel;

    temperature = connection.receiveData();
    panel.displayTemperature(temperature);
}
