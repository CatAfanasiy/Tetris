#pragma once
#include "Block.h"

class J :public Block
{
	int rotateCounter;
public:
	J(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void rotate();
	void initStartState()override;
	void update()override;
	~J();
};

