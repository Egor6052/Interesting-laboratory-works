#include <iostream>
#include <string>
#include "../lib/Controller1.h"

Controller1::Controller1() {
    this->name = "Controler 1";
    this->response = 0;
}

Controller1::~Controller1() {}

void Controller1::processSignal(int signal) {
    std::cout << "Controller1 обробляє сигнал: " << signal << std::endl;
    if (signal <= 0){
    	std::cout << "Кнопка не нажата!" << std::endl;
    	this->response = 0;
    } if (signal > 24){
    	std::cout << "Занадто високий рівень напруги! Можливо аварія!" << std::endl;
    	this->response = 0;
    } else {
    	this->response = 1;
    	std::cout << "Кнопка нажата!" << std::endl;
    }
}

void Controller1::receiveFromController2(int signal) {
    std::cout << "Controller1 отримав сигнал: " << signal << std::endl;
    processSignal(signal);
}

int Controller1::sendToController2() {

    // this->response = signal;
    std::cout << "Controller1 відправляє сигнал до Controller2: " << response << std::endl;
    std::cout << "Передача сигналу на Контролер2...\n" << std::endl;
    return response;
}

void Controller1::Print() {
    std::cout << "Name: " << name << std::endl;
}
