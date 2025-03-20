#include "map.h"

Map::Map(sf::Vector2i starting_position, unsigned tile_size, unsigned map_width, unsigned map_height) {
    m_verticies.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_verticies.resize(map_width*map_height*6);

    for (unsigned int i = 0; i < map_width; i++) {
        for (unsigned int j = 0; j < map_height; j++) {
            sf::Vertex* triangles = &m_verticies[(i + j * map_width) * 6];

            sf::Vector2f basePosition = {starting_position.x + (tile_size * i), starting_position.y + (tile_size * j)};

            triangles[0].position = basePosition; // top left
            triangles[1].position = {basePosition.x, basePosition.y + tile_size}; // bottom left
            triangles[2].position = {basePosition.x + tile_size, basePosition.y + tile_size}; // bottom right

            triangles[3].position = basePosition; // top left
            triangles[4].position = {basePosition.x + tile_size, basePosition.y}; // top right
            triangles[5].position = {basePosition.x + tile_size, basePosition.y + tile_size}; // bottom right

            triangles[0].color = sf::Color::Red;
            triangles[1].color = sf::Color::Green;
            triangles[2].color = sf::Color::Blue;
            
            triangles[3].color = sf::Color::Blue;
            triangles[4].color = sf::Color::Green;
            triangles[5].color = sf::Color::Red;

        }
    }


}