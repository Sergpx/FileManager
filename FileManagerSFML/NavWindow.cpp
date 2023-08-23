#include "NavWindow.h"
#include "Config.h"

NavWindow::NavWindow(sf::Vector2f position, sf::Color colorBack):
	frame(sf::Vector2f(FRAME_W, FRAME_H)),
	pathField(sf::Vector2f(FRAME_W, 26))

{

	this->position = position;
	this->colorBack = colorBack;
	frame.setPosition(position);
	frame.setFillColor(colorBack);
	pathField.setPosition(position);
	pathField.setFillColor(sf::Color::Color(25, 25, 25, 100));
	font.loadFromFile("arial.ttf");
	entryBox.setFont(font);
	entryBox.setPosition(position);
	entryBox.setFillColor(sf::Color::White);
	entryBox.setCharacterSize(24);
	entryBox.setString("C:\\");

}

void NavWindow::removeElement()
{

}

void NavWindow::addElement(Element)
{

}

void NavWindow::render(sf::RenderWindow& window)
{
	window.draw(frame);
	window.draw(pathField);
	window.draw(entryBox);
}


sf::RectangleShape NavWindow::pathFieldGet() {

	return pathField;

}

void NavWindow::playerInputAdd(sf::String symb)
{
	playerInput += symb;
	entryBox.setString(playerInput);
}

void NavWindow::playerInputAdd() {
	playerInput.erase(playerInput.getSize() - 1);
	entryBox.setString(playerInput);
}
