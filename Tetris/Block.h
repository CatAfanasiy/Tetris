#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
enum blocks{I_block, L_block, J_block, O_block, S_block, Z_block, T_block};
class Block
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f tiles[4];
	GameField * pt;
	float dx, dy;
	int dir, BlockType;
	bool isBlockStopped, isRotate;
public:
	Block(sf::String file, float X, float Y, float H, float W, GameField*pt);
	void setDX(float dx);
	void setDY(float dy);
	void setDir(int dir);
	void setBlockType(blocks type);
	int getBlockType()const;
	bool getIsBlockStopped()const;
	void setIsBlockStopped(bool state);
	bool isNeedRotate()const;
	void setIsRotate(bool ir);
	int getDir()const;
	float getDX()const;
	float getDY()const;
	sf::Sprite& getSprite();
	sf::Vector2f& operator[](int pos);
	void move();
	virtual void update() = 0;
	virtual void initStartState() = 0;
	void interactionWithField();
	void saveStoppedBlock();
	bool checkCollision(int x, int y);
	void drawBlock(sf::RenderTarget&window);
	virtual ~Block();
};
