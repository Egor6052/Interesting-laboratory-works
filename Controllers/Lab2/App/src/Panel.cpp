#include "../lib/Panel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Panel::displayTemperature(float temperature, sf::RenderWindow& window, sf::Font& font) {
    window.clear(sf::Color::White); // Очищуємо вікно

    // Налаштування тексту температури
    sf::Text text;
    text.setFont(font);
    text.setString("Температура: " + std::to_string(temperature) + " C");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 100); // Встановлюємо позицію тексту

    // Рамка для тексту
    sf::FloatRect textBounds = text.getGlobalBounds();
    sf::RectangleShape frame(sf::Vector2f(textBounds.width + 20, textBounds.height + 20));
    frame.setFillColor(sf::Color::Transparent);
    frame.setOutlineColor(sf::Color::Black);
    frame.setOutlineThickness(2);
    frame.setPosition(text.getPosition().x - 10, text.getPosition().y - 10); // Встановлюємо позицію рамки на основі тексту

    // Шкала температури
    float scaleWidth = 300;
    float scaleHeight = 20;
    sf::RectangleShape scale(sf::Vector2f(scaleWidth, scaleHeight));
    scale.setPosition(50, 100); // Позиція шкали
    scale.setFillColor(sf::Color(200, 200, 200)); // Світло-сіра шкала

    // Розрахунок кольору залежно від температури
    sf::Color color;
    if (temperature < 20) {
        color = sf::Color(0, 255, 0);
    } else if (temperature < 30) {
        int red = (temperature - 20) * 255 / 10;
        color = sf::Color(red, 255 - red, 0);
    } else {
        color = sf::Color(255, 0, 0);
    }

    // Малюємо кольорову частину шкали
    sf::RectangleShape tempBar(sf::Vector2f((scaleWidth * temperature / 50), scaleHeight)); // Припустимо, максимум 50°C
    tempBar.setFillColor(color);
    tempBar.setPosition(50, 200); // Позиція бару температури

    // Відображення всіх елементів
    window.draw(scale);   // Малюємо шкалу
    window.draw(tempBar); // Малюємо бар температури
    window.draw(frame);   // Малюємо рамку
    window.draw(text);    // Малюємо текст
    window.display();      // Оновлюємо вікно
}
