#include "../lib/Conection.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

Conection::Conection(){
	sock = 0;
}

void Conection::sendData(float temperature) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Помилка при створенні сокету" << std::endl;
        return;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (sockaddr*)&server, sizeof(server)) == -1) {
        std::cerr << "Помилка при підключенні" << std::endl;
        close(sock);
        return;
    }

    send(sock, &temperature, sizeof(temperature), 0);
    close(sock);
}
