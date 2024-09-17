#include <SFML/Graphics.hpp>

#include "game/Game.h"

#include "GameSettings.h"

int main(int argc, char** argv)
{
    Game game(SCREEN_WIDTH,SCREEN_HEIGHT, argv[0]);
    game.run();
    return 0;
}