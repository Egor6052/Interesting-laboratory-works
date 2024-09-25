#pragma once
#ifndef CONTROLLER1_H
#define CONTROLLER1_H

#include <iostream>
#include <string>

class Controller1 {
	private:
		std::string name;

	public:
		Controller1();
		~Controller1();

		void Print();
};

#endif