#include "O.h"



O::O(sf::String file, float X, float Y, float H, float W, GameField*pt) :Block::Block(file, X, Y, H, W, pt)
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(4, 1);
	Block::operator[](3) = sf::Vector2f(5, 1);
	Block::setBlockType(O_block);
}

void O::update()
{
	move();
	Block::interactionWithField();
}

void O::initStartState()
{
	Block::operator[](0) = sf::Vector2f(4, 0);
	Block::operator[](1) = sf::Vector2f(5, 0);
	Block::operator[](2) = sf::Vector2f(4, 1);
	Block::operator[](3) = sf::Vector2f(5, 1);
	Block::setIsBlockStopped(false);
}

O::~O()
{
}
