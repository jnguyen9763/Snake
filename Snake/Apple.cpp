#include "stdafx.h"
#include "Apple.h"
#include <cstdlib>
using namespace sf;

Apple::Apple(Board &board)
{
	position = Vector2f(0, 0);
	changePosition(board);
}

Vector2f Apple::getPosition()
{
	return position;
}

void Apple::changePosition(Board &board)
{
	int dim = board.getDim();
	position = Vector2f(rand() % dim, rand() % dim);
	if (board.getPixel(position).getFillColor() != Color::Black) {
		changePosition(board);
	}
	board.getPixel(position).setFillColor(Color::Red);
}