#pragma once
#include "Block.h"
class I :public Block
{
	int rotateCounter;
public:
	I(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void rotate();
	void initStartState()override;
	void update()override;
	~I();
};

