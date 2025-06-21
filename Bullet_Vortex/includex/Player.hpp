#pragma once
#include<SFML/Graphics.hpp>

class Player {

public:
	Player();
	sf::CircleShape shape;

	void draw(sf::RenderWindow& window);
	void MoveForward();
	void MoveRight();
	void MoveLeft();
	void MoveBack();
	

private:

	

	sf::Texture playertexture;
	
	
};