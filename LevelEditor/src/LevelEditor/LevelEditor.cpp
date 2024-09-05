#include "LevelEditor.h"

#include "iostream"
#include "GameSettings.h"
#include "TextureCoords.h"
#include "LevelData.h"


#include <set>
#include <memory>


LevelEditor::LevelEditor(int width, int height, std::string pathToExecutable)
	: m_videoMode(width, height),
	m_window(m_videoMode, "SFML works!"),
	m_resourceManager(pathToExecutable)
{

}

void LevelEditor::run()
{

	LevelData level;
	std::set<std::shared_ptr<sf::Sprite>> blockSprites;
	while (m_window.isOpen())
	{
		// todo: Тут надо будет все красиво оформить и кайфарик будет

		auto block = std::make_shared<sf::Sprite>();
		block->setTexture(m_resourceManager.getTexture("blocks.png"));
		block->setScale(SCALE_FACTOR, SCALE_FACTOR);
		block->setTextureRect({ BLOCK_LEFT, BLOCK_TOP, BLOCK_WIDTH, BLOCK_HEIGHT });

		sf::Vector2i pos = sf::Mouse::getPosition(m_window);
		pos.x = int((float)pos.x / SCREEN_WIDTH * (SCREEN_WIDTH / float(BLOCK_WIDTH * SCALE_FACTOR))) * BLOCK_WIDTH * SCALE_FACTOR;
		pos.y = int((float)pos.y / SCREEN_HEIGHT * (SCREEN_HEIGHT / float(BLOCK_HEIGHT * SCALE_FACTOR))) * BLOCK_HEIGHT * SCALE_FACTOR;
		block->setPosition(sf::Vector2f(pos));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			std::cout << pos.x << "\t" << pos.y << "\n";
			level.blocks[{pos.x, pos.y}] = { 0,0 };
			blockSprites.insert(block);
		}




		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		m_window.clear();
		m_window.draw(*block);
		for (auto sprite : blockSprites) {
			m_window.draw(*sprite);
		}
		m_window.display();
	}

	m_resourceManager.saveLevelData(level, "firstLevel");
}
