#pragma once

#include "Map.h"
#include "Doodle.h"
#include "Platform.h"

class Engine
{
public:
	Engine();
	~Engine();

	//Functions
	void run();

	const bool& isGameRunning();

	void pollEvents();
	void doodleLanding();
	void platformSpawn();
	void update();
	void render();

private:
	sf::RenderWindow mWindow;
	bool gameOver;

	//Delta time
	sf::Clock mClock;
	float dt;

	//Entities
	Map map;
	Doodle doodle;
	Platform platforms[20];
};