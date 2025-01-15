#include "Snake.h"
#include <algorithm>

Snake::Snake() : shape(sf::Vector2f(32, 32))
{
    body.push_back(sf::Vector2f(0, 0));
    shape.setFillColor(sf::Color::Green);
}

const sf::Vector2f& Snake::getNextPosition(const sf::Vector2f& direction) 
{
    static sf::Vector2f nextPosition;
    nextPosition = body[0] + direction;
    return nextPosition;
}

bool Snake::canMove(const sf::Vector2f& position) const 
{
    return std::find(body.begin(), body.end(), position) == body.end();
}

void Snake::move(const sf::Vector2f& position) 
{
    for (int i = body.size() - 1; i > 0; --i) 
    {
        body[i] = body[i - 1];
    }
    body[0] = position;
}

void Snake::grow(const sf::Vector2f& position) 
{
    body.push_back(body[body.size() - 1]);
    move(position);
}

void Snake::draw(sf::RenderWindow& window)
{
    for (const sf::Vector2f& p : body)
    {
        sf::Vector2f position(p.x * shape.getSize().x, p.y * shape.getSize().y);
        shape.setPosition(position);
        window.draw(shape);
    }
}

const std::vector<sf::Vector2f>& Snake::getBody() const
{
    return body;
}
