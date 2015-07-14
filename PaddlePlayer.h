#ifndef PADDLEPLAYER_H
#define PADDLEPLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"
#include "Globals.h"

class PaddlePlayer: public GameObject
{
public:
	PaddlePlayer();
	~PaddlePlayer();
	void Draw(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);

	GameObject  paddle1, paddle2;
};

#endif