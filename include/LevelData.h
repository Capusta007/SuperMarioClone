#pragma once

#include <map>
#include <SFML/Graphics.hpp>

struct Vector2iComparator {
	bool operator()(const sf::Vector2i& lhs, const sf::Vector2i& rhs) const {
		return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y);
	}
};

struct LevelData {

	// coordinate of block (first pair)  and coordinate of texture rectangle(second pair)
    std::map<sf::Vector2i, sf::Sprite, Vector2iComparator> blocksSprites;
};