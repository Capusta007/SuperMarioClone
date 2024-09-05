#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/ResourceManager.h"

class LevelEditor {
public:
	LevelEditor(int width, int height, std::string pathToExecutable);
	void run();

private:
	sf::VideoMode m_videoMode;
	sf::RenderWindow m_window;
	ResourceManager m_resourceManager;
};