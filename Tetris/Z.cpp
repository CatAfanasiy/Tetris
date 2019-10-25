#include "Z.h"



Z::Z(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(5, 1);
	Block::operator[](3) = sf::Vector2f(6, 1);
	rotateCounter = 0;
	Block::setBlockType(Z_block);
}

void Z::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

void Z::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(5, 1);
	Block::operator[](3) = sf::Vector2f(6, 1);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void Z::rotate()
{
	if (rotateCounter > 1)
		rotateCounter = 0;
	if (rotateCounter == 0)
	{
		Block::operator[](0).x++;
		Block::operator[](1).y++;
		Block::operator[](2).x--;
		Block::operator[](3).y++;
		Block::operator[](3).x -= 2;
	}
	else
	{
		Block::operator[](0).x--;
		Block::operator[](1).y--;
		Block::operator[](2).x++;
		Block::operator[](3).y--;
		Block::operator[](3).x += 2;
	}
	rotateCounter++;
}

Z::~Z()
{
}
