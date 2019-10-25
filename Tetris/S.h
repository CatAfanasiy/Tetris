#pragma once
#include "Block.h"
class S :public Block
{
	int rotateCounter;
public:
	S(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void update()override;
	void initStartState()override;
	void rotate();
	~S();
};

