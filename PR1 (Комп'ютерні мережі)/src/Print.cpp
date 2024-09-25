#include <iostream>
#include <string>
#include "../lib/Computer.h"


void Computer::Print(){
	std::cout << "Name PC: " << Computer::getNamePC()
	<< "Addres Local Network: " << Computer::getAddresLocalNetwork()
	<< "IP: " << Computer::getIP()
	<< "MAC: " << Computer::getMAC()
	<< "Technology Local Network: " << Computer::getTechnologyLocalNetwork()
	<< "Network Adress: " << Computer::getNetworkAdress()
	<< "Network Mask: " << Computer::getNetworkMask()
	<< "Gateway Adress: " << Computer::getGatewayAdress()
	<< "Interface: " << Computer::getInterface()
	<< "Metrics: " << Computer::getMetrics() 
	<< std::endl;


	// std::cout << "Ping: " << Computer::ping("google.com", "odessa.net", "op.edu.ua") << "\n"
			// << "Traceroute: " << Computer::traceroute("google.com", "odessa.net", "op.edu.ua") << "\n"
			// << "Nslookup: " << Computer::nslookup("google.com", "odessa.net", "op.edu.ua") << std::endl;
}