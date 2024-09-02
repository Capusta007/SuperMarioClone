#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Animation {
public:

	Animation();
	void start(float timeOfOneFrame);
	void stop();
	void addFrame(sf::IntRect frameRect);
	void setSprite(sf::Sprite* sprite);
	void update(float deltaTime);
	bool isPlayed() { return m_isPlayed; }

private:
	std::vector<sf::IntRect> m_frames;
	unsigned int m_currentFrame;
	bool m_isPlayed;
	float m_timeOfOneFrame;
	float m_elapsedTime;
	sf::Sprite* m_sprite;
	


};