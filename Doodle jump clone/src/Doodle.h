#pragma once

class Doodle
{
public:
	Doodle();
	
	//Getters
	int& getDoodleX();
	int& getDoodleY();
	int& getDoodleH();
	float& getdoodleDY();
	const sf::FloatRect getBounds() const;
	const bool& isDoodleDead();

	//Setters
	void setDY(float newDY);
	void setY(int Y);
	void setPosition(const sf::Vector2f& position);

	//Functions
	void checkDoodlePosition();
	void updateMovement();

	//Main update & render functions
	void update();
	void render(sf::RenderTarget& target);

private:
	sf::Texture texture;
	sf::Sprite doodle;

	bool endofgame;

	//Doodle's coordinates and speed
	int x, y, h;
	float dx, dy;
};