#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include "Board.h"
#include "Apple.h"

enum Move {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	STILL,
	DEAD
};

class Snake {
public:
	Snake(Board &board);
	sf::Vector2f getPosition();
	void move(Board &board, Move dir, bool growing);
	bool checkBounds(Board &board, Move dir);
	void die(Board &board);

private:
	sf::Vector2f head;
	std::queue<sf::Vector2f> body;

	void movePix(Move dir, sf::Vector2f &position);
};