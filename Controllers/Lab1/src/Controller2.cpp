    #include <iostream>
    #include <string>
    #include "../lib/SensorPanel.h"
    #include "../lib/Controller2.h"
    #include "../lib/Controller1.h"

    Controller2::Controller2(){
    	this->name = "Controler 2";
        this->response = 0;
    }

    Controller2::~Controller2(){}


    void Controller2::receiveFromPanel(int signal, Controller1& controller1) {
        std::cout << "Controller2 отримав сигнал від панелі: " << signal << std::endl;
        std::cout << "Передача на Контролер1...\n" << std::endl;
        controller1.receiveFromController2(signal);
        this->response = controller1.sendToController2();
        sendToPanel(response);
    }



    void Controller2::sendToPanel(int signal) {
        std::cout << "Controller2 передає сигнал на панель: " << signal << std::endl;
        SensorPanel panel;
        panel.blinkLight(signal);
    }

    void Controller2::Print(){
    	std::cout << "Name: " << name << std::endl;
    }