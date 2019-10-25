#pragma once
#include "Block.h"
class Z :public Block
{
	int rotateCounter;
public:
	Z(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void update()override;
	void initStartState()override;
	void rotate();
	~Z();
};

