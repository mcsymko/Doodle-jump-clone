#pragma once

#include "Map.h"
#include "Doodle.h"
#include "Platform.h"
#include "Enemy.h"

class Engine
{
public:
	Engine();
	~Engine();

	//Functions
	void run();

	const bool& isGameRunning();

	void doodleLanding();
	void platformSpawn();
	void enemySpawn();
	void Timer();
	void Timer2();

	void pollEvents();
	void update();
	void render();

private:
	sf::RenderWindow mWindow;
	bool gameOver;

	//Timer
	sf::Clock mClock;
	float timer;
	float delay;

	//Timer2
	sf::Clock mClock2;
	float timer2;
	float delay2;

	//Entities
	Map map;
	Doodle doodle;
	Platform platforms[20];
	Enemy enemy;

	bool enemySpawned;
};