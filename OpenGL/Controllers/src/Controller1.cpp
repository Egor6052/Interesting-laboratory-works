#include <iostream>
#include <string>
#include "../lib/Controller1.h"

Controller1::Controller1(){
	name = "Controler 1";
}

Controller1::~Controller1(){}

void Controller1::Print(){
	std::cout << "Name: " << name << std::endl;
}