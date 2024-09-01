#include <SFML/Graphics.hpp>

#include "game/Game.h"

int main(int argc, char** argv)
{
    Game game(1080,720, argv[0]);
    game.run();
    return 0;
}