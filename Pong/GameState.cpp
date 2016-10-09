#include "GameState.hpp"

GameState::GameState(StateManager &stack, States::Context context)
	: State(stack, context)
	, ball(*getContext().window, leftPaddle, rightPaddle)
	, leftPaddle(Paddle::Type::PlayerOne)
	, rightPaddle((*getContext().gamemode == GameMode::PvAI) ? Paddle::Type::AI : Paddle::Type::PlayerTwo, &ball)
	, leftScore(getContext().fontManager->get(Fonts::ID::GUI))
	, rightScore(getContext().fontManager->get(Fonts::ID::GUI))
	, currentGoals(0)
{
	board.loadFromFile("data/board.png");
	leftPaddle.setPosition(35.f, getContext().window->getSize(). y / 2.f);
	rightPaddle.setPosition(765.f, getContext().window->getSize().y / 2.f);

	leftScore.setPosition(350.f, 100.f);
	rightScore.setPosition(425.f, 100.f);
}

bool GameState::handleEvent(const sf::Event &event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
	{
		pushState(States::ID::Pause);
	}
	return false;
}

bool GameState::update(sf::Time dt)
{
	leftPaddle.update(dt);
	rightPaddle.update(dt);
	ball.update(dt);

	// Ball out of bounds
	if (ball.getPosition().x < 0)
	{
		rightScore.addScore();
		ball.reset();
	}
	else if (ball.getPosition().x > 800)
	{
		leftScore.addScore();
		ball.reset();
	}

	// Determine winner
	if (leftScore.getValue() == *getContext().maxGoals)
	{
		popState();
		pushState(States::ID::Menu);
	}
	else if (rightScore.getValue() == *getContext().maxGoals)
	{
		// right paddle wins
		if (*getContext().gamemode == GameMode::PvAI)
		{
			// ai wins
		}
		popState();
		pushState(States::ID::Menu);
	}

	return false;
}

void GameState::draw()
{
	sf::Sprite boardSprite(board);
	getContext().window->draw(boardSprite);

	getContext().window->draw(leftScore);
	getContext().window->draw(rightScore);

	getContext().window->draw(leftPaddle);
	getContext().window->draw(rightPaddle);
	getContext().window->draw(ball);
}