#include "L.h"


L::L(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(5, 1);
	Block::operator[](3) = sf::Vector2f(5, 2);
	rotateCounter = 0;
	Block::setBlockType(L_block);
}

void L::rotate()
{
	if (rotateCounter > 3)
	{
		rotateCounter = 0;
	}
	switch (rotateCounter)
	{
	case 0:
		Block::operator[](0).x += 2;
		Block::operator[](1).x++;
		Block::operator[](1).y++;
		Block::operator[](3).x--;
		Block::operator[](3).y--;
		break;
	case 1:
		Block::operator[](0).y += 2;
		Block::operator[](1).x--;
		Block::operator[](1).y++;
		Block::operator[](3).x += 1;
		Block::operator[](3).y--;
		break;
	case 2:
		Block::operator[](0).x -= 2;
		Block::operator[](1).x--;
		Block::operator[](1).y--;
		Block::operator[](3).x++;
		Block::operator[](3).y++;
		break;
	case 3:
		Block::operator[](0).y -= 2;
		Block::operator[](1).x++;
		Block::operator[](1).y--;
		Block::operator[](3).x--;
		Block::operator[](3).y++;
		break;
	}
	rotateCounter++;
}

void L::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(5, 1);
	Block::operator[](3) = sf::Vector2f(5, 2);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void L::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

L::~L()
{
}
