#ifndef CONTROLLER1_H
#define CONTROLLER1_H

#include <string>

class Controller1 {
public:
    Controller1();
    ~Controller1();

    void processSignal(int signal);
    void receiveFromController2(int signal);
    int sendToController2();
    void Print();

private:
    std::string name;
};

#endif
