#pragma once

#include <SFML/Graphics.hpp>

class Game {
	
public:
	Game();
	void run();

private:
	sf::VideoMode m_videoMode;
	sf::RenderWindow m_window;
};