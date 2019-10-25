#pragma once
#include "Block.h"
class L :public Block
{
	int rotateCounter;
public:
	L(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void rotate();
	void initStartState()override;
	void update()override;
	~L();
};

