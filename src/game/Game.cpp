#include "Game.h"

#include <iostream>

Game::Game(int width, int height) : m_videoMode(width, height), m_window(m_videoMode, "SFML works!"), m_player(100,100, 200)
{
}

void Game::run()
{
    sf::Clock clock;
    
    while (m_window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds(); /// Time from last frame

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_player.update(deltaTime);

        m_window.clear();
        m_player.render(m_window);
        m_window.display();
    }
}
