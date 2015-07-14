#include "Gameplayer.h"
#include "Menu.h"

void GamePlayer::Initialize(sf::RenderWindow &window)
{
	//Initialize
	//BallObject();
}

void GamePlayer::Draw(sf::RenderWindow &window)
{
	//Draw
	ballObject.Draw(window);
	paddleObject.Draw(window);
}

void GamePlayer::Update(sf::RenderWindow &window)
{
	//Update

	ballObject.Update(window);
	paddleObject.Update(window);

	if (ballObject.ball.CheckCollision(paddleObject.paddle1))
	{
		accelerate(paddleObject.paddle1);
		ballObject.ball.velocity.x *= -1.01f;
		ballObject.ball.velocity.y *= 1.01f;
	}

	if (ballObject.ball.CheckCollision(paddleObject.paddle2))
	{
		accelerate(paddleObject.paddle2);
		ballObject.ball.velocity.x *= -1.01f;
		ballObject.ball.velocity.y *= 1.01f;
	}
}

void GamePlayer::HandleEvents(sf::RenderWindow &window, sf::Event &event)
{
	//Event handler

	//modify later
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		engine.SetState(new Menu());
}

void GamePlayer::accelerate(GameObject paddle)
{
	ballObject.ball.velocity.y = (ballObject.ball.getGlobalBounds().top
		+ ballObject.ball.getGlobalBounds().height / 2
		- paddle.getGlobalBounds().top
		- paddle.getGlobalBounds().height / 2) / 20;
}