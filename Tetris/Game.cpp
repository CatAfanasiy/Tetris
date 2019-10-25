#include "Game.h"

Game::Game()
{
	isRunning = true;
	score = 0;
	CurrentBlock = rand() % 7;
	blocks[0] = new I("resources/images/i-block.png", 0, 0, 24, 24, &field);
	blocks[1] = new L("resources/images/l-block.png", 0, 0, 24, 24, &field);
	blocks[2] = new J("resources/images/j-block.png", 0, 0, 24, 24, &field);
	blocks[3] = new O("resources/images/o-block.png", 0, 0, 24, 24, &field);
	blocks[4] = new S("resources/images/s-block.png", 0, 0, 24, 24, &field);
	blocks[5] = new Z("resources/images/z-block.png", 0, 0, 24, 24, &field);
	blocks[6] = new T("resources/images/t-block.png", 0, 0, 24, 24, &field);
	field.fillGameField("resources/images/backgrounds.png", 0, 0, 24, 24);
}

bool Game::getIsRunning() const
{
	return isRunning;
}

void Game::handleEvent(const sf::Event & event)
{
	switch (event.type) 
	{
	case sf::Event::Closed:
		isRunning = false;
		break;
	case sf::Event::KeyPressed:
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Left:
			blocks[CurrentBlock]->setDir(0);
			break;
		case sf::Keyboard::Right:
			blocks[CurrentBlock]->setDir(1);
			break;
		case sf::Keyboard::Down:
			blocks[CurrentBlock]->setDir(2);
			break;
		case sf::Keyboard::Up:
			blocks[CurrentBlock]->setDir(3);
			break;
		default:
			break;
		}
	}
}


void Game::render(sf::RenderTarget & rt)
{
	field.drawBackground(rt);
	field.drawGameField(rt);
	blocks[CurrentBlock]->drawBlock(rt);
}

void Game::update()
{
	blocks[CurrentBlock]->update();
	if (blocks[CurrentBlock]->getIsBlockStopped())
	{
		blocks[CurrentBlock]->initStartState();
		CurrentBlock = rand() % 7;
	}
	switch (field.delFilledRows())
	{
	case 1:
		Game::score += 100;
		break;
	case 2:
		Game::score += 250;
		break;
	case 3:
		Game::score += 350;
		break;
	case 4:
		Game::score += 500;
	default:
		break;
	}
	if (field.isGameOver())
		Game::isRunning = false;
}

Game::~Game()
{
}
