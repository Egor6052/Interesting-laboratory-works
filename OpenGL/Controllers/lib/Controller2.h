#pragma once
#ifndef CONTROLLER2_H
#define CONTROLLER2_H

#include <iostream>
#include <string>
#include "Controller1.h"

class Controller2 {
	private:
		std::string name;

	public:
		Controller2();
		~Controller2();

		void receiveFromPanel(const std::string& signal, Controller1& controller1);
    	void sendToPanel(const std::string& signal);

		void Print();
};

#endif