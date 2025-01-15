#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Snake 
{
    std::vector<sf::Vector2f> body;
    sf::RectangleShape shape;

public:
    Snake();
    const sf::Vector2f& getNextPosition(const sf::Vector2f& direction);
    bool canMove(const sf::Vector2f& position) const;
    void move(const sf::Vector2f& position);
    void grow(const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    const std::vector<sf::Vector2f>& getBody() const;
};
