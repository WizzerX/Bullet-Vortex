#pragma once
#include<SFML/Graphics.hpp>

class maploader :public sf::Drawable, public sf::Transformable {
public:
	bool loadfromfile(const std::string& file, const std::string& tilesimagepath);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override{
        states.transform *= getTransform();
        states.texture = &tilesetTexture;
        target.draw(vertices, states);
    }
    sf::VertexArray vertices;
    sf::Texture tilesetTexture;
    sf::Vector2u tilesize;


   
};
