#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class Food
{
    sf::Vector2f position;
    sf::RectangleShape shape;
    std::mt19937 gen;

public:
    Food(const std::vector<sf::Vector2f>& snakeBody);
    const sf::Vector2f& getPosition() const;
    void generatePosition(const std::vector<sf::Vector2f>& snakeBody);
    void draw(sf::RenderWindow& window) const;
};
