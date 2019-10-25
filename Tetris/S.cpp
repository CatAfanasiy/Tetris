#include "S.h"


S::S(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(3, 1);
	Block::operator[](1) = sf::Vector2f(4, 1);
	Block::operator[](2) = sf::Vector2f(4, 0);
	Block::operator[](3) = sf::Vector2f(5, 0);
	rotateCounter = 0;
	Block::setBlockType(S_block);
}

void S::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

void S::initStartState()
{
	Block::operator[](0) = sf::Vector2f(3, 1);
	Block::operator[](1) = sf::Vector2f(4, 1);
	Block::operator[](2) = sf::Vector2f(4, 0);
	Block::operator[](3) = sf::Vector2f(5, 0);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void S::rotate()
{
	if (rotateCounter > 1)
		rotateCounter = 0;
	if (rotateCounter == 0)
	{
		Block::operator[](0).y--;
		Block::operator[](1).x--;
		Block::operator[](2).y++;
		Block::operator[](3).y += 2;
		Block::operator[](3).x--;
	}
	else
	{
		Block::operator[](0).y++;
		Block::operator[](1).x++;
		Block::operator[](2).y--;
		Block::operator[](3).y -= 2;
		Block::operator[](3).x++;
	}
	rotateCounter++;
}

S::~S()
{
}
