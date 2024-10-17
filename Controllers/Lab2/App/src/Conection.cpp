#include "../lib/Conection.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

Conection::Conection() {
    server_sock = 0;
}

float Conection::receiveData() {
    // Створення серверного сокета лише один раз
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        std::cerr << "Помилка при створенні сокету" << std::endl;
        return -1;
    }

    // Встановлення параметра SO_REUSEADDR та SO_REUSEPORT
    int opt = 1;
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        std::cerr << "Помилка при встановленні опції SO_REUSEADDR" << std::endl;
        close(server_sock);
        return -1;
    }

    #ifdef SO_REUSEPORT
    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::cerr << "Помилка при встановленні опції SO_REUSEPORT" << std::endl;
        close(server_sock);
        return -1;
    }
    #endif

    // Налаштування адреси сервера
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Помилка при прив'язці сокету" << std::endl;
        close(server_sock);
        return -1;
    }

    // Переключаємо сокет у режим прослуховування
    if (listen(server_sock, 1) < 0) {
        std::cerr << "Помилка при прослуховуванні сокету" << std::endl;
        close(server_sock);
        return -1;
    }

    std::cout << "Очікування підключення..." << std::endl;

    // Основний цикл для прийому клієнтів
    while (true) {
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);
        int client_sock = accept(server_sock, (sockaddr*)&client, &clientSize);

        if (client_sock == -1) {
            std::cerr << "Помилка при прийомі підключення" << std::endl;
            continue;
        }

        float temperature;
        ssize_t bytes_received = recv(client_sock, &temperature, sizeof(temperature), 0);
        if (bytes_received < 0) {
            std::cerr << "Помилка при отриманні даних" << std::endl;
        } else {
            std::cout << "Отримана температура: " << temperature << " C" << std::endl;
        }

        close(client_sock);
        return temperature;
    }

    close(server_sock);
    return 0;
}
