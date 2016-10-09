#pragma once

#include <SFML/Graphics.hpp>

class Ball;

class Paddle : public sf::Drawable
{
public:
	enum class Type
	{
		PlayerOne,
		PlayerTwo,
		AI
	};

	explicit Paddle(Type key);
	explicit Paddle(Type key, Ball *ball);

	void update(sf::Time dt);

	void setPosition(const float x, const float y);
	sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f &getPosition() const;
	const sf::Vector2f &getSize() const;

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void updateAI(sf::Time dt);

	Type key;
	Ball *ball;
	sf::RectangleShape shape;
};

