#include "LevelEditor.h"

#include "GameSettings.h"
#include "TextureCoords.h"
#include "LevelData.h"
#include "../gameElements/TextLabel.h"

#include <iostream>
#include <set>
#include <memory>



LevelEditor::LevelEditor(int width, int height, std::string pathToExecutable)
	: m_videoMode(width, height),
	m_window(m_videoMode, "SFML works!"),
	m_resourceManager(pathToExecutable),
	m_helpMessage("h - help", "Handjet-Black.ttf", m_resourceManager, 30U),
	m_blockSpriteNumber(0)
{
	m_window.setFramerateLimit(60);
	m_currentSpriteType = ChosenSprite::BLOCK;
	m_currentSprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	m_currentSprite.setTexture(m_resourceManager.getTexture("blocks.png"));
	m_currentSprite.setTextureRect({ BLOCK_LEFT, BLOCK_TOP, BLOCK_WIDTH, BLOCK_HEIGHT });

}

void LevelEditor::run()
{

	LevelData level;
	while (m_window.isOpen())
	{	
		// todo: Тут надо будет все красиво оформить и кайфарик будет



		sf::Vector2i pos = sf::Mouse::getPosition(m_window);
		pos.x = int((float)pos.x / SCREEN_WIDTH * (SCREEN_WIDTH / float(BLOCK_WIDTH * SCALE_FACTOR))) * BLOCK_WIDTH * SCALE_FACTOR;
		pos.y = int((float)pos.y / SCREEN_HEIGHT * (SCREEN_HEIGHT / float(BLOCK_HEIGHT * SCALE_FACTOR))) * BLOCK_HEIGHT * SCALE_FACTOR;
		m_currentSprite.setPosition(sf::Vector2f(pos));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
			if (0 < mousePos.x && mousePos.x < SCREEN_WIDTH && 0 < mousePos.y && mousePos.y < SCREEN_HEIGHT) {
				std::cout << level.blocksSprites.size() << "\n";
				sf::Sprite block = m_currentSprite;
				level.blocksSprites[{pos.x, pos.y}] = block;
			}
		}




		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			handleInput(event);
		}






		m_window.clear();
		/*for (const auto& pair : level.blocks) {
			m_currentSprite.setPosition(pair.first.first, pair.first.second);
			m_currentSprite.setTextureRect({pair.second.first, pair.second.second, BLOCK_WIDTH, BLOCK_HEIGHT});
			m_window.draw(m_currentSprite);
		}*/
		for (const auto& pair : level.blocksSprites) {
			m_window.draw(pair.second);
		}
		m_window.draw(m_currentSprite);	
		m_helpMessage.render(m_window);
		m_window.display();
	}

	m_resourceManager.saveLevelData(level, "firstLevel");
}

void LevelEditor::handleInput(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		m_helpMessage.setText("1 - block \n2 - pipe \n3 - enemy");
	}
	else {
		m_helpMessage.setText("h - help");
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::Num1) {
		m_currentSpriteType = ChosenSprite::BLOCK;
		m_blockSpriteNumber++;
		m_currentSprite.setTextureRect({ BLOCK_LEFT + BLOCK_WIDTH * (m_blockSpriteNumber % NUMBER_OF_BLOCKS), BLOCK_TOP, BLOCK_WIDTH, BLOCK_HEIGHT });
	}
}
