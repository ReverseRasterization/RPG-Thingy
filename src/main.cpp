#include <iostream>

#include "map.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "RPG");

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
            if (event->is<sf::Event::MouseWheelScrolled>()) { 
                if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>()) {

                    if (mouseWheelScrolled->delta == -1) {
                        camera.zoom(1.2);
                    }else {
                        camera.zoom(.8);
                    }
                    
                }
            }
            if (event->is<sf::Event::Resized>()) {
                camera.setSize(static_cast<sf::Vector2f>(window.getSize()));
            }
            if (event->is<sf::Event::MouseMoved>()) {
                if (mouse_active) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    sf::Vector2f offset = {static_cast<float>(mouse_pos.x - prev_mouse_position.x)*-1.f, static_cast<float>(mouse_pos.y - prev_mouse_position.y)*-1.f};
                    prev_mouse_position = mouse_pos;
                    camera.move(offset);
                }
            }
        }

        Map nMap = Map({100, 100}, 50, 2, 2);

        window.clear();
        window.setView(camera);
        window.draw(nMap);
        window.display();
    }
    return 0;
}