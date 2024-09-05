#pragma once

#include <map>
#include <SFML/Graphics.hpp>

struct LevelData {

	// coordinate of block (first pair)  and coordinate of texture rectangle(second pair)
    std::map<std::pair<int, int>, std::pair<int, int>> blocks;
};