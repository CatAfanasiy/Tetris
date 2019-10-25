#include "I.h"


I::I(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(6, 0);
	Block::operator[](3) = sf::Vector2f(7, 0);
	rotateCounter = 0;
	Block::setBlockType(I_block);
}

void I::rotate()
{
	if (rotateCounter > 1)
		rotateCounter = 0;
	if (rotateCounter == 0)
	{
		Block::operator[](1).x--;
		Block::operator[](1).y++;
		Block::operator[](2).x -= 2;
		Block::operator[](2).y += 2;
		Block::operator[](3).x -= 3;
		Block::operator[](3).y += 3;
	}
	else
	{
		Block::operator[](1).x++;
		Block::operator[](1).y--;
		Block::operator[](2).x += 2;
		Block::operator[](2).y -= 2;
		Block::operator[](3).x += 3;
		Block::operator[](3).y -= 3;
	}
	rotateCounter++;
}

void I::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(6, 0);
	Block::operator[](3) = sf::Vector2f(7, 0);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void I::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

I::~I()
{
}
