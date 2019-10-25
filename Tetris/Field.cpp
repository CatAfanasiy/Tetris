#include "Field.h"
void GameField::drawBackground(sf::RenderTarget&window)
{
	sprite.setTextureRect(sf::IntRect(0,0, 24, 24));
	for(size_t i = 0; i < HEIGHT; i++)
	{
		for(size_t j = 0; j < WIDTH; j++)
		{
			sprite.setPosition(j * 24, i * 24);
			window.draw(sprite);
		}
	}
	sprite.setTextureRect(sf::IntRect(192, 0, 24, 24));
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = WIDTH; j < WIDTH + 5; j++)
		{
			sprite.setPosition(j * 24, i * 24);
			window.draw(sprite);
		}
	}
}

bool GameField::isGameOver()
{
	for (size_t i = 0; i < WIDTH; i++)
	{
		if (GameField::arr[0][i] != ' ')
			return true;
	}
	return false;
}

GameField::GameField()
{
	for(size_t i = 0; i < 20; i++)
	{
		GameField::arr[i] = "          ";
	}
}

GameField::GameField(sf::String file, float X, float Y, float H, float W):GameField()
{
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(X, Y, H, W));
}

void GameField::fillGameField(sf::String file, float X, float Y, float H, float W)
{
	GameField::GameField();
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(X, Y, H, W));
}

void GameField::drawGameField(sf::RenderTarget &window)
{
	bool f = false;
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			if (GameField::arr[i][j] == 'i')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 'j')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(48, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 'l')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(72, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 'o')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(96, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 's')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(120, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 't')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(144, 0, 24, 24));
			}
			if (GameField::arr[i][j] == 'z')
			{
				f = true;
				sprite.setTexture(texture);
				sprite.setTextureRect(sf::IntRect(168, 0, 24, 24));
			}
			if (f)
			{
				sprite.setPosition(j * 24, i * 24);
				window.draw(sprite);
				f = false;
			}
		}
	}
}

bool GameField::isFilledRow(short row)
{
	for (size_t j = 0; j < WIDTH; j++)
	{
		if (GameField::arr[row][j] == ' ')
			return false;
	}
	return true;
}

void GameField::cleanRow(int row)
{
	for (size_t i = row; i > 0; i--)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			std::swap(GameField::arr[i][j], GameField::arr[i - 1][j]);
		}
	}
}

int GameField::delFilledRows()
{
	int counter = 0;
	for (size_t i = 0; i < HEIGHT; i++)
	{
		if (isFilledRow(i))
		{
			counter++;
			for (size_t j = 0; j < WIDTH; j++)
			{
				GameField::arr[i][j] = ' ';
			}
			cleanRow(i);
		}
	}
	return counter;
}

GameField::~GameField()
{
}

std::string GameField::arr[HEIGHT] = {
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          ",
			"          "
};