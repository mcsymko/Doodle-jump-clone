#include "pch.h"
#include "Doodle.h"

//Constructor
Doodle::Doodle()
	: x(100), y(100), h(200), dx(0), dy(0), endofgame(false)
{
	texture.loadFromFile("Textures/doodle.png");
	doodle.setTexture(texture);

	sf::FloatRect textRect = doodle.getLocalBounds();
	doodle.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
}

//Getters
int& Doodle::getDoodleX()
{
	return x;
}

int& Doodle::getDoodleY()
{
	return y;
}

int& Doodle::getDoodleH()
{
	return h;
}

float& Doodle::getdoodleDY()
{
	return dy;
}

const sf::FloatRect Doodle::getBounds() const
{
	return doodle.getGlobalBounds();
}

const bool& Doodle::isDoodleDead()
{
	return endofgame;
}

//Setters
void Doodle::setDY(float newDY)
{
	dy = newDY;
}

void Doodle::setY(int Y)
{
	y = Y;
}

void Doodle::setPosition(const sf::Vector2f& position)
{
	doodle.setPosition(position);
}

//Functions
void Doodle::checkDoodlePosition()
{
	if (y + 40 > 533)
	{
		endofgame = true;
	}

	float buf = 0;

	if (doodle.getGlobalBounds().left + 80 < 0)
	{
		buf = doodle.getPosition().y;
		x = 400;
		y = buf;
	}

	else if (doodle.getGlobalBounds().left - 30 > 400.f)
	{
		buf = doodle.getPosition().y;
		x = 0;
		y = buf;
	}

	buf = 0;
}

void Doodle::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		x += 3;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		x -= 3;
	}

	dy += 0.2f;
	y += dy;

	if (y > 500)
		dy =- 10;
}

void Doodle::update()
{
	updateMovement();
	checkDoodlePosition();
}

void Doodle::render(sf::RenderTarget& target)
{
	target.draw(doodle);
}