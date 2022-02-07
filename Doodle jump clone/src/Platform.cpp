#include "pch.h"
#include "Platform.h"

Platform::Platform()
{
	x = rand() % 400;
	y = rand() % 533;

	texture.loadFromFile("Textures/platform.png");
	platform.setTexture(texture);
}

//Getters
int& Platform::getPlatformX()
{
	return x;
}

int& Platform::getPlatformY()
{
	return y;
}

//Setters
void Platform::setX(int X)
{
	x = X;
}

void Platform::setY(int Y)
{
	y = Y;
}

//Functions
void Platform::update()
{
	platform.setPosition(x, y);
}

void Platform::render(sf::RenderTarget& target)
{
	target.draw(platform);
}
