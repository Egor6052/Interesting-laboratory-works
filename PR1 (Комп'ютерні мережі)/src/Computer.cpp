#include <iostream>
#include <string>

#include "../lib/Computer.h"

Computer::Computer(){
	namePC = "-";
	addresLocalNetwork = "-";
	IP = "-";
	MAC = "-";
	technologyLocalNetworc = "-";
	NetworkAdress = "-";
	NetworkMask = "-";
	gatewayAdress = "-";
	interface = "-";
	metrics = "-";
}

Computer::~Computer(){ }


void Computer::error(const char* valueError){
	std::cerr << valueError << "\n";
	exit(1);
}

