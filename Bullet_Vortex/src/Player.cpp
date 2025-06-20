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
