#include "T.h"


T::T(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 1);
	Block::operator[](1) = sf::Vector2f(5, 1);
	Block::operator[](2) = sf::Vector2f(5, 0);
	Block::operator[](3) = sf::Vector2f(6, 1);
	rotateCounter = 0;
	Block::setBlockType(T_block);
}

void T::rotate()
{
	if (rotateCounter > 3)
	{
		rotateCounter = 0;
		sf::Vector2f tmp = Block::operator[](2);
		Block::operator[](2) = Block::operator[](3);
		Block::operator[](3) = tmp;
		tmp = Block::operator[](3);
		Block::operator[](3) = Block::operator[](0);
		Block::operator[](0) = tmp;
	}
	switch (rotateCounter)
	{
	case 0:
		Block::operator[](0).x++;
		Block::operator[](0).y++;
		break;
	case 1:
		Block::operator[](2).x--;
		Block::operator[](2).y++;
		break;
	case 2:
		Block::operator[](3).x--;
		Block::operator[](3).y--;
		break;
	case 3:
		Block::operator[](0).x++;
		Block::operator[](0).y--;
		break;
	}
	rotateCounter++;
}

void T::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 1);
	Block::operator[](1) = sf::Vector2f(5, 1);
	Block::operator[](2) = sf::Vector2f(5, 0);
	Block::operator[](3) = sf::Vector2f(6, 1);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void T::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

T::~T()
{
}
