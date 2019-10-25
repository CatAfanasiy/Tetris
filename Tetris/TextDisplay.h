#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class TextDisplay
{
	sf::Font font;
	sf::Text text, text1;
public:
	TextDisplay();
	void displayText(sf::RenderTarget &window);
	void displayText1(sf::RenderTarget &window);
	void setText1(const std::string str);
	void setTextPos(int x, int y);
	void setText1Pos(int x, int y);
	~TextDisplay();
};

