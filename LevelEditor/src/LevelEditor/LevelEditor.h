#pragma once

#include <SFML/Graphics.hpp>

#include "ChosenSprite.h"
#include "../engine/ResourceManager.h"
#include "../gameElements/TextLabel.h"

class LevelEditor {
public:
	LevelEditor(int width, int height, std::string pathToExecutable);
	void run();

private:
	void handleInput(sf::Event);

	sf::VideoMode m_videoMode;
	sf::RenderWindow m_window;
	ResourceManager m_resourceManager;
	TextLabel m_helpMessage;
	ChosenSprite m_currentSpriteType;
	sf::Sprite m_currentSprite;
	int m_blockSpriteNumber;
};