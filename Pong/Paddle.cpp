#include "Paddle.hpp"
#include "Ball.hpp"

Paddle::Paddle(Type key)
	: Paddle(key, nullptr)
{
}

Paddle::Paddle(Type key, Ball *ball)
	: key(key)
	, ball(ball)
{
	shape.setSize({ 20, 100 });
	shape.setOrigin(shape.getSize() / 2.f);
}

void Paddle::update(sf::Time dt)
{
	switch (key)
	{
	case Type::PlayerOne:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shape.getPosition().y - shape.getSize().y / 2 > 75)
			shape.move({ 0, -150 * dt.asSeconds() });
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shape.getPosition().y < 575 - shape.getSize().y)
			shape.move({ 0, 150 * dt.asSeconds() });
		break;
	case Type::PlayerTwo:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && shape.getPosition().y - shape.getSize().y / 2 > 75)
			shape.move({ 0, -150 * dt.asSeconds() });
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && shape.getPosition().y < 575 - shape.getSize().y)
			shape.move({ 0, 150 * dt.asSeconds() });
		break;
	case Type::AI:
		updateAI(dt);
		break;
	}
}

void Paddle::setPosition(const float x, const float y)
{
	shape.setPosition(x, y);
}

sf::FloatRect Paddle::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}

const sf::Vector2f &Paddle::getPosition() const
{
	return shape.getPosition();
}

const sf::Vector2f &Paddle::getSize() const
{
	return shape.getSize();
}

void Paddle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(shape);
}

void Paddle::updateAI(sf::Time dt)
{
	if (ball->getPosition().y < shape.getPosition().y && shape.getPosition().y - shape.getSize().y / 2 > 75)
	{
		shape.move(0.f, -150 * dt.asSeconds());
	}
	else if (ball->getPosition().y > shape.getPosition().y && shape.getPosition().y < 575 - shape.getSize().y)
	{
		shape.move(0.f, 150 * dt.asSeconds());
	}
}
