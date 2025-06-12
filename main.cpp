#include <SFML/Graphics.hpp>
#include <cstdlib>
using namespace std;









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
        
        window.clear();
        window.draw(shape);
        window.display();
    }
}
