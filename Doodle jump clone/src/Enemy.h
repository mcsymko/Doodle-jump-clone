#pragma once

class Enemy
{
public:
	Enemy();

	 int& getEnemyX();
	 int& getEnemyY();
	const sf::FloatRect getBounds() const;

	void setEnemyX(int X);
	void setEnemyY(int Y);

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	
	int x, y;
};

