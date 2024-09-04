#include "Game.h"

#include <iostream>
#include "TextLabel.h"
#include "Block.h"

Game::Game(int width, int height, const std::string& pathToExecutable)
	: m_videoMode(width, height),
	m_window(m_videoMode, "SFML works!"),
	m_resourceManager(pathToExecutable),
	m_player(0, 0, { 0,0 }, m_resourceManager)
{
	m_window.setFramerateLimit(100);
}

void Game::run()
{
	sf::Clock clock;
	TextLabel text("Score:", "Handjet-Black.ttf", m_resourceManager);
	Block block1(200, 500, m_resourceManager);
	Block block2(300, 400, m_resourceManager);

	std::vector<Block> blocks;
	blocks.push_back(block1);
	blocks.push_back(block2);

	while (m_window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds(); /// Time from last frame

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		m_player.update(deltaTime, blocks);
		block1.update();
		block2.update();

		m_window.clear();
		m_player.render(m_window);
		block1.render(m_window);
		block2.render(m_window);
		text.render(m_window);
		m_window.display();
	}
}
