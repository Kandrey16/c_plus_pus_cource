#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

int main()
{
    // Parse file

    std::ifstream infile("input.txt");

    std::vector<sf::Shape *> figures;

    std::string kind, fill;
    while (infile >> kind)
    {
        sf::Shape *shape;

        if (kind == "rect")
        {
            float width, height;
            infile >> width >> height;

            shape = new sf::RectangleShape(sf::Vector2f(width, height));
        }
        else if (kind == "circle")
        {
            float radius;
            infile >> radius;

            shape = new sf::CircleShape(radius);
        }
        else if (kind == "point")
        {
            shape = new sf::CircleShape(4.f);
        }

        infile >> fill;

        if (fill == "green")
        {
            shape->setFillColor(sf::Color::Green);
        }
        else if (fill == "yellow")
        {
            shape->setFillColor(sf::Color::Yellow);
        }
        else if (fill == "gray")
        {
        }
        else
        {
            shape->setFillColor(sf::Color::Transparent);
            shape->setOutlineColor(sf::Color::Red);
            shape->setOutlineThickness(3.f);
        }

        int x, y;
        infile >> x >> y;

        shape->setPosition(x, y);

        figures.push_back(shape);
    }

    sf::RenderWindow window(sf::VideoMode(400, 400), "Task 05-06");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto figure : figures)
        {
            window.draw(*figure);
        }

        window.display();
    }

    return 0;
}
