#include "Food.h"
#include <algorithm>
#include <ctime>

Food::Food(const std::vector<sf::Vector2f>& snakeBody) : shape(sf::Vector2f(32, 32)) 
{
    gen.seed(static_cast<unsigned int>(time(nullptr)));
    generatePosition(snakeBody);
    shape.setFillColor(sf::Color::Red);
}

const sf::Vector2f& Food::getPosition() const
{
    return position;
}

void Food::generatePosition(const std::vector<sf::Vector2f>& snakeBody)
{
    bool found;
    do 
    {
        found = false;
        sf::Vector2f tmpPosition(static_cast<int>(gen() % 23) - 12, static_cast<int>(gen() % 17) - 8);
        if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) 
        {
            found = true;
        }
        position = tmpPosition;
    } while (found);
    shape.setPosition(position * shape.getSize().x);
}

void Food::draw(sf::RenderWindow& window) const
{
    window.draw(shape);
}
