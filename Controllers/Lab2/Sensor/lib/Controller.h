#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class Controller {
private:
	float parameter;
public:

	Controller();

	float getParameters(float valueParam);
	void PrintParam();

	void process();
};

#endif