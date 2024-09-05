#include "Game.h"

#include <iostream>
#include "TextLabel.h"
#include "Block.h"

#include "LevelData.h"

#include "TextureCoords.h"



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
	LevelData levelData;

	m_resourceManager.loadLevelData(levelData, "firstLevel");


	std::vector<Block> blocks;

	// todo: Потом перенесешь это в менеджер ресурсов и сделаешь класс для уровня (надо наверное, чтобы уровень возвращался из loadLevelData)
	for (const auto& pair : levelData.blocks) {
		Block block(pair.first.first, pair.first.second, m_resourceManager);
		block.setSpriteRect({ pair.second.first, pair.second.second, BLOCK_WIDTH, BLOCK_HEIGHT });
		blocks.push_back(block);
        std::cout << "Key: (" << pair.first.first << ", " << pair.first.second << ") "
                  << "Value: (" << pair.second.first << ", " << pair.second.second << ")\n";
    }

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
		for (auto block : blocks) {
			block.update();
		}

		m_window.clear();
		m_player.render(m_window);
		for (auto block : blocks) {
			block.render(m_window);
		}
		text.render(m_window);
		m_window.display();
	}
}
