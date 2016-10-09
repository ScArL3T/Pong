#pragma once

#include <SFML/Graphics.hpp>

class Paddle;

class Ball : public sf::Drawable
{
public:
	Ball(sf::RenderWindow &window, Paddle &leftPaddle, Paddle &rightPaddle);

	void update(sf::Time dt);
	void reset();

	const sf::Vector2f &getPosition() const;

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void checkCollision();

	Paddle &leftPaddle, &rightPaddle;

	sf::RectangleShape shape;
	sf::Vector2f velocity;
	sf::Vector2f initialPos;

	bool cooldown;
	sf::Time cdTime;
};