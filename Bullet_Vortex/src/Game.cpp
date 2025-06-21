#include<SFML/Graphics.hpp>
#include "../includex/Game.hpp"
#include "../includex/Player.hpp"
#include <iostream>

Game::Game() {
	window.create(sf::VideoMode({ 1080,720 }), "GameRunning!");
	isRunning = true;
}
Player player;
void Game::run()
{
	while (isRunning) {

		processEvent();
		update();
		render();
		

	}

}


void Game::render()
{
	

	

	window.clear();
	player.draw(window);
	
		//window.clear(sf::Color::Black);
		window.display();




}

void Game::update()
{




}

void Game::processEvent()
{
	while (std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
			isRunning = false;
		}
		if (event->is<sf::Event::KeyPressed>()) {
			const auto* key = event->getIf<sf::Event::KeyPressed>();

			if (key && key->code == sf::Keyboard::Key::W) {
				player.MoveForward();
				std::cout << "move_forward\n";
			}
			if (key && key->code == sf::Keyboard::Key::D) {
				player.MoveRight();
				std::cout << "right_forward\n";
			}
			if (key && key->code == sf::Keyboard::Key::A) {
				player.MoveLeft();
				std::cout << "left_forward\n";
			}
			if (key && key->code == sf::Keyboard::Key::S) {
				player.MoveBack();
				std::cout << "down_forward\n";
			}



		}
	}




}


	



