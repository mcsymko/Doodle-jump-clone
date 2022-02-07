#pragma once

#include "Platform.h"

class Platform
{
public:
	Platform();

	//Getters
	int& getPlatformX();
	int& getPlatformY();

	//Setters
	void setX(int X);
	void setY(int Y);

	//Functions
	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture texture;
	sf::Sprite platform;

	int x, y;
};

