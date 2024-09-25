    #include <iostream>
    #include <string>
    #include "../lib/Controller2.h"
    #include "../lib/Controller1.h"

    Controller2::Controller2(){
    	name = "Controler 2";
    }

    Controller2::~Controller2(){}


    void Controller2::receiveFromPanel(int signal, Controller1& controller1) {
        std::cout << "Controller2 отримав сигнал від панелі: " << signal << std::endl;
        controller1.receiveFromController2(signal);
        int response = controller1.sendToController2(); // Змінено на int
        sendToPanel(response);
    }



    void Controller2::sendToPanel(int signal) {
        std::cout << "Controller2 передає сигнал панелі: " << signal << std::endl;
    }

    void Controller2::Print(){
    	std::cout << "Name: " << name << std::endl;
    }