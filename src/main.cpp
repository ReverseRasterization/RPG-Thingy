#include <iostream>

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "RPG");

    sf::RectangleShape square({120.f, 120.f});
    square.setOrigin({60.f,60.f});
    square.setPosition({400, 400});

    sf::View camera(sf::FloatRect({0,0}, {800, 800}));
    camera.setCenter({400, 400});
    

    bool mouse_active = false;
    sf::Vector2i prev_mouse_position;

    while (window.isOpen()) { 
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>()) {
                mouse_active = true;
                prev_mouse_position = sf::Mouse::getPosition(window);
            } 

            if (event->is<sf::Event::MouseButtonReleased>()) {
                mouse_active = false;
            }

            if (event->is<sf::Event::Resized>()) {
                camera.setSize(static_cast<sf::Vector2f>(window.getSize()));
            }

            if (event->is<sf::Event::MouseMoved>()) {
                if (mouse_active) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    sf::Vector2f offset = {static_cast<float>(mouse_pos.x - prev_mouse_position.x)*-1.f, static_cast<float>(mouse_pos.y - prev_mouse_position.y)*-1.f};
                    prev_mouse_position = mouse_pos;
                    // std::cout << "\nOffset: (" << offset.x << ", " << offset.y << ")";
                    camera.move(offset);
                }
            }
        }

        // std::cout << "\nView Center: (" << camera.getCenter().x << ", " << camera.getCenter().y << ")"; 

        // std::cout << "\nSquare Scale: (" << square.getScale().x << ", " << square.getScale().y << ')';

        window.clear();
        window.setView(camera);
        window.draw(square);
        window.display();
    }
    return 0;
}