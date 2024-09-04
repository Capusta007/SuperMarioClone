#include "Animation.h"
#include <iostream>

Animation::Animation()
	: m_frames(),
	m_currentFrame(0),
	m_isPlayed(false),
	m_sprite(nullptr),
	m_elapsedTime(0),
	m_timeOfOneFrame(0)
{

}

void Animation::start(float timeOfOneFrame)
{
	if (m_isPlayed) return;

	m_isPlayed = true;
	m_currentFrame = 0;
	m_elapsedTime = timeOfOneFrame;
	m_timeOfOneFrame = timeOfOneFrame;
}

void Animation::stop()
{
	m_isPlayed = false;
}

void Animation::addFrame(sf::IntRect frameRect)
{
	m_frames.push_back(frameRect);
}

void Animation::setSprite(sf::Sprite* sprite)
{
	m_sprite = sprite;
}

void Animation::update(float deltaTime)
{
	if (!m_isPlayed || !m_sprite) {
		return;
	}
	m_elapsedTime += deltaTime;

	if (m_elapsedTime >= m_timeOfOneFrame) {
		m_elapsedTime -= m_timeOfOneFrame;
		m_currentFrame++;
		m_currentFrame %= m_frames.size();
		m_sprite->setTextureRect(m_frames[m_currentFrame]);
	}
}
