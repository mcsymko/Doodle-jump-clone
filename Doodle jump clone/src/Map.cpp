#include "pch.h"
#include "Map.h"

Map::Map()
{
	texture.loadFromFile("Textures/background.png");
	map.setTexture(texture);
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(map);
}
