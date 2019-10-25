#pragma once
#include "Block.h"
class T :public Block
{
	int rotateCounter;
public:
	T(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void rotate();
	void initStartState()override;
	void update()override;
	~T();
};

