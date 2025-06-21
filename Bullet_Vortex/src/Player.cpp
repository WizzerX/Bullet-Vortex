#pragma once
#include "../includex/Player.hpp"
#include<SFML/Graphics.hpp>




Player::Player()
{
	shape.setRadius(90.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(500.f, 500.f));



}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(shape);



}

void Player::MoveForward()
{
	sf::Vector2f currentpos = shape.getPosition();
	 float currentposx = currentpos.x;
	 float currentposy = currentpos.y;
	 currentpos = sf::Vector2f(currentposx, currentposy -= 2);
	 shape.setPosition(currentpos);

	

}

void Player::MoveRight()
{
	sf::Vector2f currentpos = shape.getPosition();
	float currentposx = currentpos.x;
	float currentposy = currentpos.y;
	currentpos = sf::Vector2f(currentposx += 2, currentposy);
	shape.setPosition(currentpos);


}

void Player::MoveLeft()
{
	sf::Vector2f currentpos = shape.getPosition();
	float currentposx = currentpos.x;
	float currentposy = currentpos.y;
	currentpos = sf::Vector2f(currentposx -= 2, currentposy);
	shape.setPosition(currentpos);


}

void Player::MoveBack()
{
	sf::Vector2f currentpos = shape.getPosition();
	float currentposx = currentpos.x;
	float currentposy = currentpos.y;
	currentpos = sf::Vector2f(currentposx, currentposy +=2);
	shape.setPosition(currentpos);


}
