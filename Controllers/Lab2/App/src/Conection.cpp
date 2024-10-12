#include "Conection.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

int Conection::receiveData() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        std::cerr << "Помилка при створенні сокету" << std::endl;
        return -1;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080); // Порт
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (sockaddr*)&server, sizeof(server)) == -1) {
        std::cerr << "Помилка при прив'язці сокету" << std::endl;
        close(server_sock);
        return -1;
    }

    listen(server_sock, 1);
    std::cout << "Очікування підключення..." << std::endl;

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    int client_sock = accept(server_sock, (sockaddr*)&client, &clientSize);

    if (client_sock == -1) {
        std::cerr << "Помилка при прийомі підключення" << std::endl;
        close(server_sock);
        return -1;
    }

    int temperature;
    recv(client_sock, &temperature, sizeof(temperature), 0);
    close(client_sock);
    close(server_sock);

    return temperature;
}
