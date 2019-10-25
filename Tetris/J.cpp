#include "J.h"


J::J(sf::String file, float X, float Y, float H, float W, GameField*pt):Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 2);
	Block::operator[](1) = sf::Vector2f(4, 1);
	Block::operator[](2) = sf::Vector2f(4, 0);
	Block::operator[](3) = sf::Vector2f(5, 0);
	rotateCounter = 0;
	Block::setBlockType(J_block);
}

void J::rotate()
{
	if (rotateCounter > 3)
		rotateCounter = 0;
	switch (rotateCounter)
	{
	case 0:
		Block::operator[](0).x--;
		Block::operator[](0).y--;
		Block::operator[](2).x++;
		Block::operator[](2).y++;
		Block::operator[](3).y += 2;
		break;
	case 1:
		Block::operator[](0).x++;
		Block::operator[](0).y--;
		Block::operator[](2).x--;
		Block::operator[](2).y++;
		Block::operator[](3).x -= 2;
		break;
	case 2:
		Block::operator[](0).x++;
		Block::operator[](0).y++;
		Block::operator[](2).x--;
		Block::operator[](2).y--;
		Block::operator[](3).y -= 2;
		break;
	case 3:
		Block::operator[](0).x--;
		Block::operator[](0).y++;
		Block::operator[](2).x++;
		Block::operator[](2).y--;
		Block::operator[](3).x += 2;
		break;
	}
	rotateCounter++;
}

void J::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 2);
	Block::operator[](1) = sf::Vector2f(4, 1);
	Block::operator[](2) = sf::Vector2f(4, 0);
	Block::operator[](3) = sf::Vector2f(5, 0);
	Block::setIsBlockStopped(false);
	rotateCounter = 0;
}

void J::update()
{
	move();
	if (Block::isNeedRotate())
		rotate();
	Block::setIsRotate(false);
	Block::interactionWithField();
}

J::~J()
{
}
