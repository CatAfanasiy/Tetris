#include "TextDisplay.h"



TextDisplay::TextDisplay()
{
	font.loadFromFile("resorces/14745.ttf");
	text.setFont(font);
	text.setString("Score");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text1.setFont(font);
	text1.setCharacterSize(24);
	text1.setFillColor(sf::Color::White);
}

void TextDisplay::displayText(sf::RenderTarget & window)
{
	window.draw(text);
}

void TextDisplay::displayText1(sf::RenderTarget & window)
{
	window.draw(text1);
}

void TextDisplay::setText1(const std::string str)
{
	text.setString(str);
}

void TextDisplay::setTextPos(int x, int y)
{
	text.setPosition(x, y);
}

void TextDisplay::setText1Pos(int x, int y)
{
	text1.setPosition(x, y);
}


TextDisplay::~TextDisplay()
{
}
