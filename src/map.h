#pragma once

#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable {
    private:

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            states.transform *= getTransform();

            target.draw(m_verticies, states);
        }

        sf::VertexArray m_verticies;

    public:
        Map(sf::Vector2i starting_position, unsigned tile_size, unsigned map_width, unsigned map_height);
        
};