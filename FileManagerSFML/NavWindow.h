#pragma once
#include "Element.h"
#include <SFML/Graphics.hpp>
#include <vector>
class NavWindow
{
	Element* activeElement = nullptr;
	std::vector<Element> elements;
	sf::Vector2f position;
	sf::RectangleShape frame;
	sf::Vector2f size;
	sf::Color colorBack;
	sf::Text entryBox;
	sf::Font font;
	sf::RectangleShape pathField;
	sf::String playerInput = "C:\\";

public:
	NavWindow(sf::Vector2f position, sf::Color colorBack);
	void removeElement();
	void addElement(Element);
	void render(sf::RenderWindow& window);
	sf::RectangleShape pathFieldGet();
	void playerInputAdd(sf::String symb);
	void playerInputAdd();
};

