#pragma once
#ifndef CONTROLLER1_H
#define CONTROLLER1_H

#include <iostream>
#include <string>

class Controller2 {
	private:
		std::string name;

	public:
		Controller2();
		~Controller2();

		void Print();
};

#endif