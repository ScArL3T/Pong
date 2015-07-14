#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "Globals.h"
#include "PaddlePlayer.h"

class BallObject : public GameObject
{
public:
	BallObject();
	~BallObject();
	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);

	sf::Vector2f borderPosition;
	GameObject   ball;
	bool		 border;
};

#endif