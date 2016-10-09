#include "StateManager.hpp"
#include "SplashScreen.h"

#include "MenuState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "PauseState.hpp"

#include "GameModes.hpp"

int main()
{
	// Splash
#ifdef _WIN32
	unsigned char opacity = 255;
	float duration = 1.5f;
	SplashScreen ss;
	//ss.create(opacity, duration);
#endif

	sf::RenderWindow window;
	window.create({ 800, 600 }, "Pong", sf::Style::Titlebar | sf::Style::Close);
	//window.setFramerateLimit(200);

	FontManager fontManager;
	fontManager.load(Fonts::ID::GUI, "data/font.ttf");

	SoundPlayer soundPlayer;
	soundPlayer.load();

	TextureManager textureManager;
	textureManager.load(Textures::ID::ButtonGreen, "data/button.png");
	textureManager.load(Textures::ID::ButtonRed, "data/button.png");
	//textureManager.load(Textures::ID::Panel, "data/panel.png");

	GameMode gamemode(GameMode::PvAI);
	unsigned int maxGoals = 3;

	States::Context context(window, soundPlayer, fontManager, textureManager, gamemode, maxGoals);
	StateManager manager(context);

	// Registering available states
	manager.registerState<MenuState>(States::ID::Menu);
	manager.registerState<GameState>(States::ID::Game);
	manager.registerState<GameOverState>(States::ID::GameOver);
	manager.registerState<PauseState>(States::ID::Pause);
	manager.pushState(States::ID::Menu);

	const sf::Time frameTime = sf::seconds(1.f / 60.f);
	sf::Clock clock;
	sf::Time passedTime = sf::Time::Zero;

	// Main loop
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		passedTime += elapsedTime;

		// Physics, logics etc
		while (passedTime > frameTime)
		{
			// Event loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::MouseButtonPressed)
					std::cout << event.mouseButton.x << ' ' << event.mouseButton.y << '\n';
				manager.processEvents(event);
			}

			passedTime -= frameTime;
			manager.update(frameTime);

			if (manager.isEmpty())
				window.close();
		}

		// Rendering
		window.clear();
		manager.draw();
		window.display();
	}

	return 0;
}