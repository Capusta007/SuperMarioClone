#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "../engine/ResourceManager.h"

class Game {
	
public:
	Game(int width, int height,const std::string& pathToExecutable);
	void run();

private:
	sf::VideoMode m_videoMode;
	sf::RenderWindow m_window;
	ResourceManager m_resourceManager;
	Player m_player;
};