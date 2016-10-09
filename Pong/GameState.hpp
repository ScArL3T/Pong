#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "Score.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"

#include <SFML/Audio.hpp>

class GameState final : public State
{
public:
	explicit GameState(StateManager &stack, States::Context context);

	bool handleEvent(const sf::Event &event) override;
	bool update(sf::Time dt) override;
	void draw() override;

private:
	Score leftScore, rightScore;

	Paddle leftPaddle, rightPaddle;
	Ball ball;

	sf::Texture	board;

	sf::Font font;
	unsigned int currentGoals;
};

#endif