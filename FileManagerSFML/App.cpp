#include "App.h"

App::App():
	window(sf::VideoMode(WINDOW_W, WINDOW_H), "File manager"),
	navLeft(leftFrameCoord, sf::Color::Color(255, 150, 255)),
	navRight(rightFrameCoord, sf::Color::Color(255, 150, 255))
{
}

void App::run()
{
	while (window.isOpen()) {
		processEvent();
		update();
		render();
	}

}

void App::render()
{

	window.clear();
	navLeft.render(window);
	navRight.render(window);
	window.display();

}

void App::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::MouseButtonReleased) {
			sf::Vector2f localPosition(event.mouseButton.x, event.mouseButton.y);
			if (navLeft.pathFieldGet().getGlobalBounds().contains(localPosition)) {
				flag = 1;
			}
			else if (navRight.pathFieldGet().getGlobalBounds().contains(localPosition)) {
				flag = 2;
			}
			else flag = 0;
			
		}
		
		if (event.type == sf::Event::TextEntered && (flag == 1 or flag == 2)) {
			{
				if (event.text.unicode < 128)
				{
					if (flag == 1) {
						navLeft.playerInputAdd(event.text.unicode);
					}
					else if (flag == 2) {
						navRight.playerInputAdd(event.text.unicode);
					}
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (flag == 1 or flag == 2)) {
			if (flag == 1) {
				navLeft.playerInputAdd();
			}
			else if (flag == 2) {
				navRight.playerInputAdd();
			}
		}
	}

}

void App::update()
{

	

}

void App::moveElement()
{
}

void App::copyElement()
{
}

void App::removeElement()
{
}
