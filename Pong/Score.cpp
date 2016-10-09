#include "Score.hpp"

Score::Score(const sf::Font &font)
	: score()
	, count(0)
{
	score.setFont(font);
	score.setString(std::to_string(count));
	score.setCharacterSize(40);
	score.setFillColor(sf::Color::White);
}

void Score::addScore()
{
	count++;
	score.setString(std::to_string(count));
}

void Score::resetScore()
{
	count = 0;
	score.setString(std::to_string(count));
}

unsigned int Score::getValue() const
{
	return count;
}

sf::Vector2f Score::getSize() const
{
	return sf::Vector2f(score.getLocalBounds().width, score.getLocalBounds().height);
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(score, states);
}
