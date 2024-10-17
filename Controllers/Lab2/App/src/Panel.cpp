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

    // Малюємо кольорову частину шкали
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

    // // Відсоткове значення
    // int percentage = static_cast<int>(tempPercentage * 100);
    // sf::Text percentageText;
    // percentageText.setFont(font);
    // percentageText.setString(std::to_string(percentage) + "%");
    // percentageText.setCharacterSize(20);
    // percentageText.setFillColor(sf::Color::White);
    // percentageText.setPosition(50 + scaleWidth + 10, 100);

    // Відображення всіх елементів
    window.draw(scale);
    window.draw(tempBar);
    window.draw(tempText);
    // window.draw(percentageText);
    window.display();
}
