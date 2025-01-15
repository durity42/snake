#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"

class Game 
{
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;
    Snake snake;
    Food food;
    sf::Vector2f snakeDirection;
    float time_between_move;
    float current_timer_between_move;
    bool gameover;

public:
    Game();
    void run();
};
