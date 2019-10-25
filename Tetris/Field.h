#pragma once
#include <SFML/Graphics.hpp>
#include <string>
const unsigned short HEIGHT = 20;
const unsigned short WIDTH = 10;
class GameField
{
	sf::Texture texture;
	sf::Sprite sprite;
public:
	static std::string arr[HEIGHT];
	GameField();
	GameField(sf::String file, float X, float Y, float H, float W);
	void fillGameField(sf::String file, float X, float Y, float H, float W);
	void drawGameField(sf::RenderTarget &window);
	bool isFilledRow(short row);
	void cleanRow(int row);
	int delFilledRows();
	void drawBackground(sf::RenderTarget&window);
	bool isGameOver();
	~GameField();
};