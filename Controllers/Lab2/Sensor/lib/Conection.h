#pragma once
#ifndef CONECTION_H
#define CONECTION_H

#include <iostream>

class Conection {
private:
	int sock;
public:

	Conection();
	void sendData(float temperature);
};

#endif