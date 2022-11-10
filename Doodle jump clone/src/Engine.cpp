#include "pch.h"
#include "Engine.h"

//Constructor
Engine::Engine()
	: gameOver(false), timer(), enemySpawned(false), delay2(), timer2()
{
	mWindow.create(sf::VideoMode(400, 533), "Doodle jump clone", sf::Style::Close);
	mWindow.setFramerateLimit(60);
	std::cout << "[GAME]: Window created successfully!" << "\n";

	delay = rand() % 10 + 15;
}

//Destructor
Engine::~Engine()
{
	std::cout << "[GAME]: Game over!" << "\n";
}

//Functions
void Engine::run()
{
	while (!isGameRunning())
	{
		update();
		render();
	}
}

const bool& Engine::isGameRunning()
{
	if (doodle.isDoodleDead())
	{
		gameOver = true;
	}

	if (enemySpawned && doodle.getBounds().intersects(enemy.getBounds()))
	{
		gameOver = true;
	}

	return gameOver;
}

void Engine::pollEvents()
{
	sf::Event ev;
	
	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameOver = true;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameOver = true;
	}
}

void Engine::doodleLanding()
{
	//Doodle's landing on platforms realization
	for (int i = 0; i < 10; i++)
	{
		if ((doodle.getDoodleX() + 50 > platforms[i].getPlatformX())
			&& (doodle.getDoodleX() + 20 < platforms[i].getPlatformX() + 68)
			&& doodle.getDoodleY() + 43 > platforms[i].getPlatformY() && (doodle.getDoodleY() + 43 < platforms[i].getPlatformY() + 14) && (doodle.getdoodleDY() > 0))
		{
			doodle.setDY(-10);
		}
	}
}

void Engine::platformSpawn()
{
	if (doodle.getDoodleY() < doodle.getDoodleH())
	{
		for (int i = 0; i < 10; i++)
		{
			doodle.setY(doodle.getDoodleH());
			platforms[i].setY(platforms[i].getPlatformY() - doodle.getdoodleDY());

			if (platforms[i].getPlatformY() > 533)
			{
				platforms[i].setY(0);
				platforms[i].setX(rand() % 400);
			}
		}
		enemy.setEnemyY(enemy.getEnemyY() - doodle.getdoodleDY());
		if (enemy.getEnemyY() > 533)
		{
			Timer2();
		}
	}
}

void Engine::enemySpawn()
{
	enemy.setEnemyX(rand() % 400);
	enemy.setEnemyY(0);
}

void Engine::Timer()
{
	float time = mClock.getElapsedTime().asSeconds();
	mClock.restart();
	timer += time;
	if (timer > delay)
	{
		timer = 0;
		enemySpawn();
		enemySpawned = true;
	}
}

void Engine::Timer2()
{
	delay2 = rand() % 10 + 15;
	float time2 = mClock.getElapsedTime().asSeconds();
	mClock2.restart();
	timer2 += time2;
	if (timer2 > delay2)
	{
		timer2 = 0;
		enemySpawn();
	}
}

void Engine::update()
{
	pollEvents();
	Timer();
	for (int i = 0; i < 10; i++)
	{
		platforms[i].update();
	}
	doodle.update();
	enemy.update();
	platformSpawn();
	doodleLanding();

	doodle.checkDoodlePosition();
	doodle.setPosition(sf::Vector2f(doodle.getDoodleX(), doodle.getDoodleY()));
	
}

void Engine::render()
{
	mWindow.clear();
	map.render(mWindow);
	doodle.render(mWindow);
	for (int i = 0; i < 10; i++)
	{
		platforms[i].render(mWindow);
	}
	platforms->render(mWindow);
	if (enemySpawned)
	{
		enemy.render(mWindow);
	}
	/*std::cout << doodle.getDoodleX() << ", " << doodle.getDoodleY() << ", " << doodle.getDoodleH() << std::endl;*/
	mWindow.display();
}