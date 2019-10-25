#pragma once
#include "Block.h"
class O :public Block
{
public:
	O(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void update()override;
	void initStartState()override;
	~O();
};

