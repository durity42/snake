#include "Game.h"
#include <ctime>

Game::Game() : window(sf::VideoMode(800, 600), "Snake"), snake(), food(snake.getBody()), snakeDirection(0, 0), time_between_move(0.5f), current_timer_between_move(0.f), gameover(false)
{
    sf::View v = window.getDefaultView();
    v.setCenter(0, 0);
    window.setView(v);
}

void Game::run() 
{
    while (window.isOpen()) 
    {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        if (!gameover) 
        {
            update(deltaTime);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.scancode == sf::Keyboard::Scancode::Q) 
            { 
                snakeDirection = sf::Vector2f(-1, 0);
            }
            if (event.key.scancode == sf::Keyboard::Scancode::D)
            { 
                snakeDirection = sf::Vector2f(1, 0);
            }
            if (event.key.scancode == sf::Keyboard::Scancode::Z)
            { 
                snakeDirection = sf::Vector2f(0, -1);
            }
            if (event.key.scancode == sf::Keyboard::Scancode::S)
            { 
                snakeDirection = sf::Vector2f(0, 1);
            }
        }
    }
}

void Game::update(float deltaTime) 
{
    if (current_timer_between_move <= 0) 
    {
        if (snakeDirection.x != 0 || snakeDirection.y != 0) 
        {
            sf::Vector2f nextPosition = snake.getNextPosition(snakeDirection);
            if (snake.canMove(nextPosition)) 
            {
                if (nextPosition == food.getPosition()) 
                {
                    food.generatePosition(snake.getBody());
                    snake.grow(nextPosition);
                }
                else 
                {
                    snake.move(nextPosition);
                }
            }
            else
            {
                gameover = true;
            }
        }
        current_timer_between_move += (time_between_move - 0.01f * snake.getBody().size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snake.getBody().size());
    }
    else 
    {
        current_timer_between_move -= deltaTime;
    }
}

void Game::render() 
{
    window.clear(sf::Color::Black);
    snake.draw(window);
    food.draw(window);
    window.display();
}
