#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

class Controller {
private:
	float parameter;
public:

	Controller();

	void setParameters(float valueParam);
	float getParameters();
	void PrintParam();

	void process();
};

#endif