#pragma once
#include<SFML/Graphics.hpp>

class maploader :public sf::Drawable, public sf::Transform {
public:
	bool loadfromfile(const std::string& file, const std::string& tilesimagepath);
private:




};
