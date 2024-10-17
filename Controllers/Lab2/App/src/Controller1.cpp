#include "../lib/Controller1.h"
#include "../lib/Conection.h"
#include "../lib/Panel.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <iostream>

Controller1::Controller1() {
    temperature = 0;
}

void Controller1::process() {
    Conection connection;
    Panel panel;

    sf::RenderWindow window(sf::VideoMode(400, 300), "Моніторинг температури");

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        std::cerr << "Помилка при завантаженні шрифту\n";
        return;
    }

    std::thread dataThread([&]() {
        while (window.isOpen()) {
            temperature = connection.receiveData();
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Оновлення кожну секунду
        }
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Відображення отриманих значень безпосередньо
        // std::cout << "Температура для відображення: " << temperature << std::endl; // Вивід на консоль
        panel.displayTemperature(temperature, window, font);

        // float testTemperature = 25;
        // panel.displayTemperature(testTemperature, window, font);

    }


    if (dataThread.joinable()) {
        dataThread.join();
    }
}
