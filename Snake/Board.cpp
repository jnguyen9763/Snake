#include "stdafx.h"
#include "Board.h"
#include "Apple.h"
using namespace sf;

Board::Board(int dimension, int pixelSize)
{
	dim = dimension / pixelSize;
	board = new RectangleShape*[dim];

	// initialize board
	for (int row = 0; row < dim; row++) {
		board[row] = new RectangleShape[dim];
	}

	for (int row = 0; row < dim; row++) {
		for (int col = 0; col < dim; col++) {
			board[row][col].setSize(Vector2f(pixelSize, pixelSize));
			board[row][col].setPosition(Vector2f(row * pixelSize, col * pixelSize));
			board[row][col].setFillColor(Color::Black);
			board[row][col].setOutlineColor(Color::Black);
			board[row][col].setOutlineThickness(2);
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < dim; i++) {
		delete[] board[i];
	}
	delete[] board;
}

void Board::draw(RenderWindow &window)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			window.draw(board[i][j]);
		}
	}
}

int Board::getDim()
{
	return dim;
}

RectangleShape &Board::getPixel(Vector2f position)
{
	return board[(int) position.x][(int) position.y];
}