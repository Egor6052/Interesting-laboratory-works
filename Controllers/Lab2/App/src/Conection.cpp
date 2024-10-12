#include "../lib/Conection.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

Conection::Conection() {
    server_sock = 0;
}

int Conection::receiveData() {
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        std::cerr << "Помилка при створенні сокету" << std::endl;
        return -1;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Помилка при встановленні опції сокету" << std::endl;
        close(server_sock);
        return -1;
    }

    if (bind(server_sock, (sockaddr*)&server, sizeof(server)) == -1) {
        std::cerr << "Помилка при прив'язці сокету" << std::endl;
        close(server_sock);
        return -1;
    }

    listen(server_sock, 1);
    std::cout << "Очікування підключення..." << std::endl;

    while (true) {
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);
        int client_sock = accept(server_sock, (sockaddr*)&client, &clientSize);

        if (client_sock == -1) {
            std::cerr << "Помилка при прийомі підключення" << std::endl;
            continue;
        }

        int temperature;
        recv(client_sock, &temperature, sizeof(temperature), 0);

        std::cout << "Отримана температура: " << temperature << " C" << std::endl;

        close(client_sock);
    }

    close(server_sock);
    return 0;
}
