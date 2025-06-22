#include<iostream>
#include "../includex/Game.hpp"
#include "../includex/Player.hpp"
#include "../includex/nlohmann/json.hpp"

using json = nlohmann::json;

int main() {
	Game game;
	
	json data{
		{"name","shivam"},
		{"age","22"	}

	};
	std::cout << "detalil"<< data["name"] << "\n";
	game.run();
	
}