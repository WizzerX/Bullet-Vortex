#pragma once
#include<SFML/Graphics.hpp>

class Player {

public:
	Player();
	sf::CircleShape shape;

	void draw(sf::RenderWindow& window);

private:

	

	sf::Texture playertexture;
	
	
};