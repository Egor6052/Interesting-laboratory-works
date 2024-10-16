#include "../lib/Controller1.h"
#include "../lib/Conection.h"
#include "../lib/Panel.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>  // Додано для використання std::cerr

Controller1::Controller1() {
    temperature = 0;
}

void Controller1::process() {
    Conection connection;
    Panel panel;

    // Створюємо вікно SFML для відображення температури
    sf::RenderWindow window(sf::VideoMode(400, 300), "Моніторинг температури");

    // Завантажуємо шрифт
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cerr << "Помилка при завантаженні шрифту\n";
        return;
    }

    // Окремий потік для отримання даних про температуру
    std::thread dataThread([&]() {
        while (window.isOpen()) {
            temperature = connection.receiveData();
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Оновлення кожну секунду
        }
    });

    // Основний цикл SFML
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Виклик методу для відображення температури з трьома аргументами
        panel.displayTemperature(temperature, window, font);
    }

    // Очікуємо завершення потоку з даними
    if (dataThread.joinable()) {
        dataThread.join();
    }
}
