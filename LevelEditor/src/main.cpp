#include "LevelEditor/LevelEditor.h"
#include "GameSettings.h"

int main(int agrc, char** argv)
{
    LevelEditor levelEditor(SCREEN_WIDTH, SCREEN_HEIGHT, argv[0]);
    levelEditor.run();
}