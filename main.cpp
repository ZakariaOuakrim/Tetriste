#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(50.f);
    sf::RectangleShape shape2(sf::Vector2f(50.f, 50.f));
    sf::CircleShape triangle(80, 3);

    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Red);
    shape2.setPosition(200.f,200.f);
    shape2.rotate(45);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(triangle);
        window.display();
    }

    return 0;
}