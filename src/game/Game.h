#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class Game {
	
public:
	Game(int width, int height);
	void run();

private:
	sf::VideoMode m_videoMode;
	sf::RenderWindow m_window;
	Player m_player;
};