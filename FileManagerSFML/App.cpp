#include "App.h"

App::App():
	window(sf::VideoMode(800, 600), "SFML window")
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
	window.display();

}

void App::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

}

void App::update()
{

}
