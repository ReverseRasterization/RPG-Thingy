#include "map.h"
#include <iostream>

Map::Map(const std::filesystem::path& tileset_path, const int* tiles, sf::Vector2i starting_position, unsigned tile_size, unsigned map_width, unsigned map_height) {
    if (!m_tileset.loadFromFile(tileset_path)) {
        std::cerr << "Failed to load tileset";
    }

    m_verticies.setPrimitiveType(sf::PrimitiveType::Triangles);
    m_verticies.resize(map_width*map_height*6);

    for (unsigned int i = 0; i < map_width; i++) {
        for (unsigned int j = 0; j < map_height; j++) {
            sf::Vertex* triangles = &m_verticies[(i + j * map_width) * 6];

            sf::Vector2f basePosition = {starting_position.x + (tile_size * i), starting_position.y + (tile_size * j)};
            float texturePosition = 0 + (tiles[i+j * map_width] * 50);

            triangles[0].position = basePosition; // top left
            triangles[1].position = {basePosition.x, basePosition.y + tile_size}; // bottom left
            triangles[2].position = {basePosition.x + tile_size, basePosition.y + tile_size}; // bottom right

            triangles[3].position = basePosition; // top left
            triangles[4].position = {basePosition.x + tile_size, basePosition.y}; // top right
            triangles[5].position = {basePosition.x + tile_size, basePosition.y + tile_size}; // bottom right

            triangles[0].texCoords = sf::Vector2f(texturePosition, 0);
            triangles[1].texCoords = sf::Vector2f(texturePosition, 50);
            triangles[2].texCoords = sf::Vector2f(texturePosition + 50, 50);

            triangles[3].texCoords = sf::Vector2f(texturePosition, 0);
            triangles[4].texCoords = sf::Vector2f(texturePosition + 50, 0);
            triangles[5].texCoords = sf::Vector2f(texturePosition + 50, 50);
        }
    }


}