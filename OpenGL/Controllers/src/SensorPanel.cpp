#include <iostream>
#include <string>
#include "../lib/SensorPanel.h"

void SensorPanel::pressButton(Controller2& controller2, Controller1& controller1) {
    std::string signal = "Натиснута кнопка";
    std::cout << "Сенсорна панель: " << signal << std::endl;
    controller2.receiveFromPanel(signal, controller1);
}

void SensorPanel::blinkLight() {
    std::cout << "Лампочка блимає на панелі!" << std::endl;
}
