#include "stdafx.h"
#include "Board.h"
#include "Apple.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

const int boardSize = 700;
const int pixelSize = 28;
const int lenIncrement = 5;
const chrono::duration<int, milli> timespan(50);

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(boardSize, boardSize), "Snake");
	Font font;
	Text score;
	Board board(boardSize, pixelSize);
	Snake snake(board);
	Apple apple(board);
	Move currDir = STILL;
	Move tempDir = STILL;
	int totalLen = 1;
	int growLen = 0;
	bool growing = false;

	font.loadFromFile("Fonts/OCRAEXT.ttf");
	score.setFont(font);
	score.setCharacterSize(boardSize / 10);
	score.setFillColor(Color::White);
	score.setOutlineColor(Color::Black);
	score.setOutlineThickness(2);
	score.setPosition(Vector2f(boardSize / 2, boardSize / 3));

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (currDir != DEAD) {
				if (Keyboard::isKeyPressed(Keyboard::Up) && (currDir != DOWN || totalLen == 1)) {
					tempDir = UP;
				}
				if (Keyboard::isKeyPressed(Keyboard::Down) && (currDir != UP || totalLen == 1)) {
					tempDir = DOWN;
				}
				if (Keyboard::isKeyPressed(Keyboard::Right) && (currDir != LEFT || totalLen == 1)) {
					tempDir = RIGHT;
				}
				if (Keyboard::isKeyPressed(Keyboard::Left) && (currDir != RIGHT || totalLen == 1)) {
					tempDir = LEFT;
				}
			}
		}

		if (currDir != DEAD) {
			currDir = tempDir;
			if (snake.checkBounds(board, currDir)) {
				snake.move(board, currDir, growing);
				this_thread::sleep_for(timespan);
			}
			else if (currDir != STILL) {
				currDir = DEAD;
				snake.die(board);
				string message = "Score: " + to_string(totalLen);
				score.setString(message);
				score.setOrigin(Vector2f(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 2));
			}
		}

		if (growLen != 0) {
			growLen--;
			growing = true;
		} 
		else {
			growing = false;
		}

		if (snake.getPosition() == apple.getPosition()) {
			apple.changePosition(board);
			growLen = lenIncrement;
			totalLen += lenIncrement;
		}

		window.clear();
		board.draw(window);
		if (currDir == DEAD) {
			window.draw(score);
		}
		window.display();
	}
	return 0;
}

