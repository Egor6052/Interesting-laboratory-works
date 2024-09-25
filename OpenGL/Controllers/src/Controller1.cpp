#include <iostream>
#include <string>
#include "../lib/Controller1.h"

Controller1::Controller1() {
    name = "Controler 1";
}

Controller1::~Controller1() {}

void Controller1::processSignal(int signal) {
    std::cout << "Controller1 обробляє сигнал: " << signal << std::endl;
}

void Controller1::receiveFromController2(int signal) {
    std::cout << "Controller1 отримав сигнал: " << signal << std::endl;
    processSignal(signal);
}

int Controller1::sendToController2() {
    int response = 42; // Повертаємо ціле число
    std::cout << "Controller1 відправляє сигнал до Controller2: " << response << std::endl;
    return response;
}

void Controller1::Print() {
    std::cout << "Name: " << name << std::endl;
}
