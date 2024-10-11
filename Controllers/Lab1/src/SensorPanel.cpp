#include <iostream>
#include <string>
#include "../lib/SensorPanel.h"

SensorPanel::SensorPanel(){
	this->signal = 0;
}
SensorPanel::~SensorPanel(){}

void SensorPanel::pressButton(Controller2& controller2, Controller1& controller1) {
	std::cout << "---Ви на сенсорній панелі---\nВведіть сигнал на кнопку: " << std::endl;
	std::cin >> signal;
    // this->signal = 1;
    std::cout << "Сенсорна панель прийняла: " << signal << std::endl;
    std::cout << "Передача на контролер2...\n" << std::endl;
    controller2.receiveFromPanel(signal, controller1);
}

void SensorPanel::blinkLight(int signalFromControler2) {
	if (signalFromControler2 > 0){
		std::cout << "Лампочка блимає!" << std::endl;
	} else {
		std::cout << "Лампочка не блимає!" << std::endl;
	}
    
}
