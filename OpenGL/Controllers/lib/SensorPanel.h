#pragma once
#ifndef SENSORPANEL_H
#define SENSORPANEL_H

#include <iostream>
#include <string>

#include "Controller1.h"
#include "Controller2.h"


class SensorPanel {
private:
	int signal;

public:
    void pressButton(Controller2& controller2, Controller1& controller1);

    void blinkLight();
};

#endif