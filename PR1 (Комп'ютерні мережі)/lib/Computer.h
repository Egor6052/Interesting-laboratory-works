#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

class Computer {
private:
	std::string namePC;
	std::string addresLocalNetwork;
	std::string IP;
	std::string MAC;
	std::string technologyLocalNetworc;
	std::string NetworkAdress;
	std::string NetworkMask;
	std::string gatewayAdress;
	std::string interface;
	std::string metrics;
	
public:
	Computer();
	~Computer();

	// void setNamePC(std::string value);
	// void setAddresLocalNetwork(std::string value);
	// void setIP(std::string value);
	// void setMAC(std::string value);
	// void setTechnologyLocalNetwork(std::string value);
	// void setNetworkAdress(std::string value);
	// void setNetworkMask(std::string value);
	// void setGatewayAdress(std::string value);
	// void setInterface(std::string value);
	// void setMetrics(std::string value);
	
	std::string getNamePC();
	std::string getAddresLocalNetwork();
	std::string getIP();
	std::string getMAC();
	std::string getTechnologyLocalNetwork();
	std::string getNetworkAdress();
	std::string getNetworkMask();
	std::string getGatewayAdress();
	std::string getInterface();
	std::string getMetrics();

	// void setPing(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);
	// void setTraceroute(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);
	// void setNslookup(std::string valueAddress1, std::string valueAddress2, std::string valueAddress3);

	void ping();
	void traceroute();
	void nslookup();

	static void error(const char* valueError);

	void Print();
};

#endif