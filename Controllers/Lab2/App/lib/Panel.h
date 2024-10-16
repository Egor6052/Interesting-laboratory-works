#pragma once
#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../lib/Controller1.h"


class Panel {
	// private:

	public:
    void displayTemperature(float temperature, sf::RenderWindow& window, sf::Font& font);
};

#endif