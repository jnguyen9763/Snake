#include "stdafx.h"
#include <cstdlib>
#include "Snake.h"
using namespace sf;

Snake::Snake(Board &board)
{
	int dim = board.getDim();
	head = Vector2f(rand() % dim, rand() % dim);
	body.push(head);
	board.getPixel(head).setFillColor(Color::Green);
}

Vector2f Snake::getPosition()
{
	return head;
}

void Snake::move(Board &board, Move dir, bool growing) 
{
	movePix(dir, head);
	board.getPixel(head).setFillColor(Color::Green);
	body.push(head);
	if (!growing) {
		Vector2f tail = body.front();
		board.getPixel(tail).setFillColor(Color::Black);
		body.pop();
	}
}

void Snake::movePix(Move dir, Vector2f &position)
{
	switch (dir) {
	case UP:
		position.y--;
		break;
	case DOWN:
		position.y++;
		break;
	case RIGHT:
		position.x++;
		break;
	case LEFT:
		position.x--;
		break;
	}
}

bool Snake::checkBounds(Board &board, Move dir)
{
	Vector2f temp = head;
	movePix(dir, temp);
	if (dir == UP && head.y == 0 ||
		dir == DOWN && head.y == board.getDim() - 1 ||
		dir == RIGHT && head.x == board.getDim() - 1 ||
		dir == LEFT && head.x == 0 ||
		board.getPixel(temp).getFillColor() == Color::Green) {
		return false;
	}
	else {
		return true;
	}
}

void Snake::die(Board &board)
{
	while (!body.empty()) {
		board.getPixel(body.front()).setFillColor(Color(0, 100, 0));
		body.pop();
	}
}


