#include "Game.h"

#include <iostream>

Game::Game(int width, int height) : m_videoMode(width, height), m_window(m_videoMode, "SFML works!")
{
}

void Game::run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        m_window.clear();
        m_window.draw(shape);
        m_player.render(m_window);
        m_window.display();
    }
}
