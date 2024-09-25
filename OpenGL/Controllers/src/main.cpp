
#include <iostream>
#include "../lib/Controller1.h"
#include "../lib/Controller2.h"
#include "../lib/SensorPanel.h"

int main(){

	Controller1 controller1;
    Controller2 controller2;
    SensorPanel panel;

    panel.pressButton(controller2, controller1);
	return 0;
}