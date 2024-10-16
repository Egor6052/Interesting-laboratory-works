#pragma once
#ifndef CONECTION_H
#define CONECTION_H

class Conection {
private:
	int server_sock;
public:

	Conection();
	float receiveData();
	
};

#endif