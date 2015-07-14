#include "PaddlePlayer.h"

PaddlePlayer::PaddlePlayer()
{
	//Load pads
	paddle1.Load("data/paddle1.png");
	paddle2.Load("data/paddle2.png");
	
	//Set position of the pads
	paddle1.setPosition({ 0, HEIGHT / 2 - paddle1.getLocalBounds().height / 2 });
	paddle2.setPosition({ WIDTH - paddle2.getLocalBounds().width, 
		HEIGHT / 2 - paddle2.getLocalBounds().height / 2 });

	//paddle1.velocity.y = 0.f;
	//paddle2.velocity.y = 0.f;
}


PaddlePlayer::~PaddlePlayer()
{
}

void PaddlePlayer::Draw(sf::RenderWindow &window)
{
	//Draw paddles
	window.draw(paddle1);
	window.draw(paddle2);
}

void PaddlePlayer::Update(sf::RenderWindow &window)
{
	//Input for the first paddle.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
		&& paddle1.getPosition().y > 0)
	{
		paddle1.move({ 0, -5 });
		paddle1.velocity.y = -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
		&& paddle1.getPosition().y + paddle1.getLocalBounds().height < HEIGHT)
	{
		paddle1.move({ 0, 5 });
		paddle1.velocity.y = 1.f;
	}
	else paddle1.velocity.y = 0.f;

	//Input for the second paddle.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)
		&& paddle2.getPosition().y > 0)
	{
		paddle2.move({ 0, -5 });
		paddle2.velocity.y = -1.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)
		&& paddle2.getPosition().y + paddle2.getLocalBounds().height < HEIGHT)
	{
		paddle2.move({ 0, 5 });
		paddle2.velocity.y = 1.f;
	}
	else paddle2.velocity.y = 0.f;
}