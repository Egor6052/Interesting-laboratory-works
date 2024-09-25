#pragma once
#ifndef CONTROLLER1_H
#define CONTROLLER1_H

#include <iostream>
#include <string>

class Controller1 {
	private:
		std::string name;

		 void processSignal(const std::string& signal);


	public:
		Controller1();
		~Controller1();


		void receiveFromController2(const std::string& signal);

	    std::string sendToController2();

		void Print();
};

#endif