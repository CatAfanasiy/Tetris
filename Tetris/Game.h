#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Field.h"
#include "Block.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "I.h"
#include "S.h"
#include "T.h"
#include "Z.h"
class Game
{
	bool isRunning;
	int score, CurrentBlock;
	Block *blocks[7];
	GameField field;
public:
	Game();
	bool getIsRunning()const;
	void handleEvent(const sf::Event&event);
	void render(sf::RenderTarget &rt);
	void update();
	~Game();
};

