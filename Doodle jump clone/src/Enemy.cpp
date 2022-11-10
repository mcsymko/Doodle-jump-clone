#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
	: x(0), y(0)
{
	mTexture.loadFromFile("Textures/Enemy.png");
	mSprite.setTexture(mTexture);

	mSprite.setPosition(x, y);
}

int& Enemy::getEnemyX()
{
	return x;
}

int& Enemy::getEnemyY()
{
	return y;
}

const sf::FloatRect Enemy::getBounds() const
{
	return mSprite.getGlobalBounds();
}

void Enemy::setEnemyX(int X)
{
	x = X;
}

void Enemy::setEnemyY(int Y)
{
	y = Y;
}

void Enemy::update()
{
	mSprite.setPosition(x, y);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(mSprite);
}
