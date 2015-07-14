#include "BallObject.h"

BallObject::BallObject()
{
	//Load ball
	ball.Load("data/ball.png");

	//Set position
	ball.setPosition({WIDTH / 2 - ball.getLocalBounds().width / 2, 
		HEIGHT / 2 - ball.getLocalBounds().height / 2});

	//Initial movement
	ball.velocity.x = -4.f;
	ball.velocity.y = -4.f;
}


BallObject::~BallObject()
{
}

void BallObject::Draw(sf::RenderWindow &window)
{
	//Draw ball
	window.draw(ball);
}

void BallObject::Update(sf::RenderWindow &window)
{
	//Update
	ball.move(ball.velocity);

	//Check top and bottom
	if (ball.getPosition().y < 0 || ball.getPosition().y + ball.getLocalBounds().height > HEIGHT)
	{
		borderPosition.x = ball.getPosition().x;
		borderPosition.y = ball.getPosition().y;

		ball.velocity.y *= -1.f;

		border = true;
	}
}