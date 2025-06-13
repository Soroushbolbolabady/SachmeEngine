#include <SFML/Graphics.hpp>
#include <cstdlib>
using namespace std;



bool isInsideWindow(const sf::Vector2f& position, const sf::Vector2u& windowSize, const sf::Vector2f& shapeSize) {
    return position.x >= 0 && position.x + shapeSize.x < windowSize.x &&
           position.y >= 0 && position.y + shapeSize.y < windowSize.y;
}






int main()
{

    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Fucking Sachme Engine! You are not gonna belive it!!!");
    sf::RectangleShape shape(sf::Vector2f(100,100));
    float shapePosition[2] = {static_cast<float>(rand() % 1921), static_cast<float>(rand() % 1081)};


    shape.setPosition({shapePosition[0], shapePosition[1]});
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        sf::Vector2f lastPositon = shape.getPosition();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
          
          shape.move({-1.f , 0.f});
        
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
          shape.move({1.f, 0.f});
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
          shape.move({0.f, -1.f});
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
          shape.move({0.f, 1.f});
        }
        
        sf::Vector2f pos = shape.getPosition();
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2f shapeSize = shape.getSize();
        if(!isInsideWindow(pos, windowSize, shapeSize)){
          shape.setPosition(lastPositon);

        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
