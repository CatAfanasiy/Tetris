#include "Block.h"



Block::Block(sf::String file, float X, float Y, float H, float W, GameField*pt)
{
	this->pt = pt;
	dx = dy = 0;
	dir = -1;
	isBlockStopped = isRotate = false;
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(X, Y, H, W));
}

void Block::setDX(float dx)
{
	this->dx = dx;
}

void Block::setDY(float dy)
{
	this->dy = dy;
}

void Block::setDir(int dir)
{
	this->dir = dir;
}

void Block::setBlockType(blocks type)
{
	BlockType = type;
}

int Block::getBlockType() const
{
	return BlockType;
}

bool Block::getIsBlockStopped() const
{
	return isBlockStopped;
}

void Block::setIsBlockStopped(bool state)
{
	isBlockStopped = state;
}

bool Block::isNeedRotate() const
{
	return isRotate;
}

void Block::setIsRotate(bool ir)
{
	isRotate = ir;
}

int Block::getDir() const
{
	return dir;
}

float Block::getDX() const
{
	return dx;
}

float Block::getDY() const
{
	return dy;
}

sf::Sprite& Block::getSprite()
{
	return sprite;
}

sf::Vector2f & Block::operator[](int pos)
{
	return tiles[pos];
}

void Block::move()
{
	switch (Block::getDir())
	{
	case 0://left
		for (size_t i = 0; i < 4; i++)
		{
			Block::operator[](i).x--;
		}
		Block::setDX(-1);
		break;
	case 1://Right
		for (size_t i = 0; i < 4; i++)
		{
			Block::operator[](i).x++;
		}
		Block::setDX(1);
		break;
	case 2://Down
		for (size_t i = 0; i < 4; i++)
		{
			Block::operator[](i).y++;
		}
		Block::setDY(1);
		break;
	case 3://Up
		isRotate = true;
		break;
	default:
		break;
	}
	Block::setDir(2);
}

void Block::interactionWithField()
{
	bool f = false;
	if (Block::dx < 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (Block::tiles[i].x < 0 || checkCollision(Block::tiles[i].x, Block::tiles[i].y))
			{
				f = true;
				break;
			}
		}
		if (f)
		{
			for (size_t i = 0; i < 4; i++)
			{
				Block::tiles[i].x++;
			}
		}
	}
	if (Block::dx > 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (Block::tiles[i].x > WIDTH - 1 || checkCollision(Block::tiles[i].x, Block::tiles[i].y))
			{
				f = true;
				break;
			}
		}
		if (f)
		{
			for (size_t i = 0; i < 4; i++)
			{
				Block::tiles[i].x--;
			}
		}
	}
	if (Block::dy > 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (Block::tiles[i].y > HEIGHT - 1 || checkCollision(Block::tiles[i].x, Block::tiles[i].y))
			{
				f = true;
				isBlockStopped = true;
				break;
			}
		}
		if (f)
		{
			for (size_t i = 0; i < 4; i++)
			{
				Block::tiles[i].y--;
			}
		}
	}
	Block::dx = 0;
	Block::dy = 0;
	if (isBlockStopped)
		saveStoppedBlock();
}

void Block::saveStoppedBlock()
{
	for (size_t i = 0; i < 4; i++)
	{
		switch (BlockType)
		{
		case I_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 'i';
			break;
		case L_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 'l';
			break;
		case J_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 'j';
			break;
		case O_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 'o';
			break;
		case S_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 's';
			break;
		case Z_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 'z';
			break;
		case T_block:
			pt->arr[int(Block::tiles[i].y)][int(Block::tiles[i].x)] = 't';
			break;
		}
	}
}

bool Block::checkCollision(int x, int y)
{
	if (pt->arr[y][x] != ' ')
	{
		return  true;
	}
	return false;
}

void Block::drawBlock(sf::RenderTarget & window)
{
	for (size_t i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			for (size_t k = 0; k < 4; k++)
			{
				if (Block::tiles[k].x == j && Block::tiles[k].y == i)
				{
					Block::sprite.setPosition(j * 24, i * 24);
					window.draw(sprite);
				}
			}
		}
	}
}

Block::~Block()
{
}