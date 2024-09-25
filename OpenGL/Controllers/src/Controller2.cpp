#include <iostream>
#include <string>
#include "../lib/Controller2.h"
#include "../lib/Controller1.h"

Controller2::Controller2(){
	name = "Controler 2";
}

Controller2::~Controller2(){}


void Controller2::receiveFromPanel(const std::string& signal, Controller1& controller1) {
    std::cout << "Controller2 отримав сигнал від панелі: " << signal << std::endl;
    controller1.receiveFromController2(signal);  // Виклик методу Controller1
    std::string response = controller1.sendToController2();
    sendToPanel(response);  // Відправляємо сигнал на панель
}

void Controller2::sendToPanel(const std::string& signal) {
    std::cout << "Controller2 передає сигнал панелі: " << signal << std::endl;
    // Логіка для передачі сигналу на панель
}

void Controller2::Print(){
	std::cout << "Name: " << name << std::endl;
}