 
#include "Controller1.h"
#include "Conection.h"
#include "Panel.h"

void Controller1::process() {
    Conection connection;
    Panel panel;

    int temperature = connection.receiveData();
    panel.displayTemperature(temperature);
}
