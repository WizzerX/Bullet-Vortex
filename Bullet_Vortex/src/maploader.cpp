#pragma once
#include "../includex/maploader.hpp"
#include "../includex/nlohmann/json.hpp"
#include <fstream>
#include <iostream>


using json = nlohmann::json;

bool maploader::loadfromfile(const std::string& file, const std::string& tilesimagepath)
{
    std::ifstream input(file);
    if (!input.is_open()) {
        std::cout << "error in loading the file!\n";
        return false;
    }
    json mapdata;
    input >> mapdata;

   // std::cout << mapdata.dump(4);

    int mapWidth = mapdata["width"];
    int mapHeight = mapdata["height"];
    tilesize.x = mapdata["tilewidth"];
    tilesize.y = mapdata["tileheight"];


    if (!tilesetTexture.loadFromFile("Assets/Map/testmap.png")) {
        std::cout << "error in load the tile set map\n";
        return false;
    }
    vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    vertices.resize(mapWidth * mapHeight * 6);  // 4 vertices per tile

    int tilesPerRow = tilesetTexture.getSize().x / tilesize.x;
   
    std::cout <<tilesPerRow;

    // 6. Get the tile layer data
    const auto& layer = mapdata["layers"][0];
    const auto& tileData = layer["data"];
    for (const auto& layer : mapdata["layers"]) {
        for (int i = 0; i < mapWidth * mapHeight; ++i) {
            int tileIndex = tileData[i].get<int>() - 1;  // Tiled starts from 1

            if (tileIndex < 0) continue; // Skip empty tiles

            int tu = tileIndex % tilesPerRow; // x tile
            int tv = tileIndex / tilesPerRow; // y tile

            int x = i % mapWidth;
            int y = i / mapWidth;

            sf::Vertex* tri = &vertices[i * 6];

            // First triangle
            tri[0].position = sf::Vector2f(x * tilesize.x, y * tilesize.y);
            tri[1].position = sf::Vector2f((x + 1) * tilesize.x, y * tilesize.y);
            tri[2].position = sf::Vector2f((x + 1) * tilesize.x, (y + 1) * tilesize.y);

            // Second triangle
            tri[3].position = sf::Vector2f(x * tilesize.x, y * tilesize.y);
            tri[4].position = sf::Vector2f((x + 1) * tilesize.x, (y + 1) * tilesize.y);
            tri[5].position = sf::Vector2f(x * tilesize.x, (y + 1) * tilesize.y);

            // Texture coordinates (same logic as positions)
            tri[0].texCoords = sf::Vector2f(tu * tilesize.x, tv * tilesize.y);
            tri[1].texCoords = sf::Vector2f((tu + 1) * tilesize.x, tv * tilesize.y);
            tri[2].texCoords = sf::Vector2f((tu + 1) * tilesize.x, (tv + 1) * tilesize.y);

            tri[3].texCoords = sf::Vector2f(tu * tilesize.x, tv * tilesize.y);
            tri[4].texCoords = sf::Vector2f((tu + 1) * tilesize.x, (tv + 1) * tilesize.y);
            tri[5].texCoords = sf::Vector2f(tu * tilesize.x, (tv + 1) * tilesize.y);
        }
    }
    return true;
}
