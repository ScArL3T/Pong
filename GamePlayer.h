#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include "States.h"
#include "PaddlePlayer.h"
#include "BallObject.h"
#include <math.h>

class GamePlayer: public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void HandleEvents(sf::RenderWindow &window, sf::Event &event);
private:
	void accelerate(GameObject paddle);

	PaddlePlayer paddleObject;
	BallObject	 ballObject;

	float	     x_side, y_side, angle, hypot_side, use_angle;
	sf::Vector2f ballInPaddle1, ballInPaddle2;
};

#endif

