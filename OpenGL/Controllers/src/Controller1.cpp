#include <iostream>
#include <string>
#include "../lib/Controller1.h"

Controller1::Controller1(){
	name = "Controler 1";
}

Controller1::~Controller1(){}


void Controller1::processSignal(const std::string& signal) {
    std::cout << "Controller1 обробляє сигнал: " << signal << std::endl;
    // Логіка обробки сигналу
}

void Controller1::receiveFromController2(const std::string& signal) {
    std::cout << "Controller1 отримав сигнал: " << signal << std::endl;
    processSignal(signal);
}

std::string Controller1::sendToController2() {
    std::string response = "Сигнал від Controller1";
    std::cout << "Controller1 відправляє сигнал до Controller2: " << response << std::endl;
    return response;
}



void Controller1::Print(){
	std::cout << "Name: " << name << std::endl;
}