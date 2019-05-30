#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Apple {
public:
	Apple(Board &board);
	sf::Vector2f getPosition();
	void changePosition(Board &board);

private:
	sf::Vector2f position;
};