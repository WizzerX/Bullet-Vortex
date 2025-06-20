#include<SFML/Graphics.hpp>
#include "../includex/Game.hpp"
#include "../includex/Player.hpp"

Game::Game() {
	window.create(sf::VideoMode({ 1080,720 }), "GameRunning!");
	isRunning = true;
}

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
	Player player;
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
	}




}


	



