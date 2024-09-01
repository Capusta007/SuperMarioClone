#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
	Player();
	void update();
	void render(sf::RenderWindow& window);

private:
	sf::RectangleShape m_playerShape;
};