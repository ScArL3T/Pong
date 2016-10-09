#include "Ball.hpp"
#include "Paddle.hpp"
#include <iostream>
Ball::Ball(sf::RenderWindow &window, Paddle &leftPaddle, Paddle &rightPaddle)
	: leftPaddle(leftPaddle)
	, rightPaddle(rightPaddle)
	, shape()
	, velocity(-250.f, -250.f)
	, cooldown(true)
	, cdTime()
{
	shape.setSize({ 20, 20 });
	shape.setOrigin(shape.getSize() / 2.f);
	shape.setPosition(static_cast<sf::Vector2f>(window.getSize()) / 2.f);
	shape.setFillColor(sf::Color::Red);

	initialPos = shape.getPosition();
}

void Ball::update(sf::Time dt)
{
	if (!cooldown)
	{
		shape.move(velocity.x * dt.asSeconds(), velocity.y * dt.asSeconds());

		// Top/bot collision
		if (shape.getPosition().y <= 86 || shape.getPosition().y + shape.getSize().y >= 534)
			velocity.y *= -1;

		// Paddles collision
		checkCollision();
	}
	else
	{
		cdTime += dt;
		if (cdTime > sf::seconds(1.5f))
		{
			cooldown = false;
			cdTime = sf::seconds(0.f);
		}
	}
}

void Ball::reset()
{
	shape.setPosition(initialPos);
	cooldown = true;
}

const sf::Vector2f &Ball::getPosition() const
{
	return shape.getPosition();
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(shape);
}

void Ball::checkCollision()
{
	// Left Paddle
	if (shape.getPosition().x - shape.getSize().x / 2 < leftPaddle.getPosition().x + leftPaddle.getSize().x / 2 &&
		shape.getPosition().x - shape.getSize().x / 2 > leftPaddle.getPosition().x &&
		shape.getPosition().y + shape.getSize().x / 2 >= leftPaddle.getPosition().y - leftPaddle.getSize().y / 2 &&
		shape.getPosition().y - shape.getSize().x / 2 <= leftPaddle.getPosition().y + leftPaddle.getSize().y / 2)
	{
		if (shape.getPosition().y > leftPaddle.getPosition().y)
			velocity.y *= -1;

		shape.setPosition(55.f, shape.getPosition().y);
		velocity.x *= -1;
	}
	else if (shape.getPosition().x - shape.getSize().x / 2 < leftPaddle.getPosition().x + leftPaddle.getSize().x / 2 &&
		shape.getPosition().x - shape.getSize().x / 2 <= leftPaddle.getPosition().x &&
		shape.getPosition().y + shape.getSize().x / 2 >= leftPaddle.getPosition().y - leftPaddle.getSize().y / 2 &&
		shape.getPosition().y - shape.getSize().x / 2 <= leftPaddle.getPosition().y + leftPaddle.getSize().y / 2)
	{
		if(shape.getPosition().y > leftPaddle.getPosition().y)
			shape.setPosition(shape.getPosition().x, leftPaddle.getPosition().y + leftPaddle.getSize().y / 2 + 10.f);
		else shape.setPosition(shape.getPosition().x, leftPaddle.getPosition().y - leftPaddle.getSize().y / 2 - 10.f);

		velocity.y *= -1;
	}

	// Right Paddle
	if (shape.getPosition().x + shape.getSize().x / 2 > rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 &&
		shape.getPosition().x + shape.getSize().x / 2 < rightPaddle.getPosition().x &&
		shape.getPosition().y + shape.getSize().x / 2 >= rightPaddle.getPosition().y - rightPaddle.getSize().y / 2 &&
		shape.getPosition().y - shape.getSize().x / 2 <= rightPaddle.getPosition().y + rightPaddle.getSize().y / 2)
	{
		if (shape.getPosition().y > rightPaddle.getPosition().y)
			velocity.y *= -1;

		shape.setPosition(745.f, shape.getPosition().y);
		velocity.x *= -1;
	}
	else if (shape.getPosition().x + shape.getSize().x / 2 > rightPaddle.getPosition().x - rightPaddle.getSize().x / 2 &&
		shape.getPosition().x + shape.getSize().x / 2 >= rightPaddle.getPosition().x &&
		shape.getPosition().y + shape.getSize().x / 2 >= rightPaddle.getPosition().y - rightPaddle.getSize().y / 2 &&
		shape.getPosition().y - shape.getSize().x / 2 <= rightPaddle.getPosition().y + rightPaddle.getSize().y / 2)
	{
		if (shape.getPosition().y > rightPaddle.getPosition().y)
			shape.setPosition(shape.getPosition().x, rightPaddle.getPosition().y + rightPaddle.getSize().y / 2 + 10.f);
		else shape.setPosition(shape.getPosition().x, rightPaddle.getPosition().y - rightPaddle.getSize().y / 2 - 10.f);
	
		velocity.y *= -1;
	}
}
