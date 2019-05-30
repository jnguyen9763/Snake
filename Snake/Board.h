#pragma once
#include <SFML/Graphics.hpp>

class Board {
public:
	Board(int dimension, int pixelSize);
	~Board();
	void draw(sf::RenderWindow &window);
	int getDim();
	sf::RectangleShape &getPixel(sf::Vector2f position);

private:
	sf::RectangleShape **board;
	int dim;
};
