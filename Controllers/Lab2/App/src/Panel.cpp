#include "../lib/Panel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Panel::displayTemperature(float temperature, sf::RenderWindow& window, sf::Font& font) {
    window.clear(sf::Color(30, 30, 30));

    // Налаштування тексту температури
    sf::Text tempText;
    tempText.setFont(font);
    tempText.setString(std::to_string(static_cast<int>(temperature)) + " C");
    tempText.setCharacterSize(30);
    tempText.setFillColor(sf::Color::White);
    tempText.setPosition(150, 30);

    const float maxTemperature = 100.0f;

    // Шкала температури
    float scaleWidth = 300;
    float scaleHeight = 30;
    sf::RectangleShape scale(sf::Vector2f(scaleWidth, scaleHeight));
    scale.setPosition(50, 100);
    scale.setFillColor(sf::Color(80, 80, 80));

    // Кольорова частина шкали
    float tempPercentage = temperature / maxTemperature; // Процентне співвідношення
    sf::RectangleShape tempBar(sf::Vector2f(scaleWidth * tempPercentage, scaleHeight));

    // Розрахунок кольору залежно від температури (градуювальна шкала)
    sf::Color color;
    if (temperature < 20) {
        color = sf::Color(0, 150, 255);
    } else if (temperature < 35) {
        color = sf::Color(255, 180, 0);
    } else {
        color = sf::Color(255, 50, 50);
    }
    tempBar.setFillColor(color);
    tempBar.setPosition(50, 100);

    // Лампочка
    sf::CircleShape lamp(20);
    lamp.setPosition(150, 220);
    sf::Color lampColor = sf::Color::Transparent;
    bool isLampOn = false;

    // Кнопка
    sf::RectangleShape button(sf::Vector2f(100, 40));
    button.setPosition(100, 170);
    button.setFillColor(sf::Color(100, 100, 100));
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(2);

    // Обробка натиску миші
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        if (button.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            isLampOn = !isLampOn;
        }
    }

    // Встановлюємо колір лампочки в залежності від стану
    if (isLampOn) {
        lampColor = sf::Color::Yellow;
    } else {
        lampColor = sf::Color::Transparent;
    }
    lamp.setFillColor(lampColor);

    // Відображення всіх елементів
    window.draw(scale);
    window.draw(tempBar);
    window.draw(tempText);
    window.draw(button);
    window.draw(lamp);
    window.display();
}
