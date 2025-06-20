#pragma once
#include<SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();
	

private:
	void render();
	void update();
	void processEvent();
	sf::RenderWindow window;
	
	bool isRunning;
	
};