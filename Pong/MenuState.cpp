#include "MenuState.hpp"
#include "Button.hpp"

MenuState::MenuState(StateManager &stack, States::Context context)
	: State(stack, context)
{
	sf::RenderWindow &window = *getContext().window;
	
	title.setFont(getContext().fontManager->get(Fonts::ID::GUI));
	title.setColor(sf::Color::White);
	title.setCharacterSize(40);
	title.setString("Pong");
	title.setPosition(static_cast<int>(window.getSize().x / 2 - title.getLocalBounds().width / 2), 50.f);

	auto pvai = std::make_shared<Button>(*getContext().soundPlayer);
	pvai->setTexture(getContext().textureManager->get(Textures::ID::ButtonGreen));
	pvai->setPosition(static_cast<int>(window.getSize().x / 2 - 190 / 2), 200.f);
	pvai->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	pvai->setText("1P START");
	pvai->setCallback([this]()
	{
		*getContext().gamemode = GameMode::PvAI;
		popState();
		pushState(States::ID::Game);
	});

	auto pvp = std::make_shared<Button>(*getContext().soundPlayer);
	pvp->setTexture(getContext().textureManager->get(Textures::ID::ButtonGreen));
	pvp->setPosition(static_cast<int>(window.getSize().x / 2 - 190 / 2), 250.f);
	pvp->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	pvp->setText("2P START");
	pvp->setCallback([this]()
	{
		*getContext().gamemode = GameMode::PvP;
		popState();
		pushState(States::ID::Game);
	});

	auto goals = std::make_shared<Button>(*getContext().soundPlayer);
	goals->setTexture(getContext().textureManager->get(Textures::ID::ButtonGreen));
	goals->setPosition(static_cast<int>(window.getSize().x / 2 - 190 / 2), 300.f);
	goals->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	goals->setText("GOALS " + std::to_string(*getContext().maxGoals));
	goals->setCallback([=]()
	{
		*getContext().maxGoals = *getContext().maxGoals + 1;
		if (*getContext().maxGoals > 7)
			*getContext().maxGoals = 1;

		goals->setText("GOALS " + std::to_string(*getContext().maxGoals));
	});

	auto quit = std::make_shared<Button>(*getContext().soundPlayer);
	quit->setTexture(getContext().textureManager->get(Textures::ID::ButtonRed));
	quit->setPosition(static_cast<int>(window.getSize().x / 2 - 190 / 2), 350.f);
	quit->setFont(getContext().fontManager->get(Fonts::ID::GUI));
	quit->setText("QUIT");
	quit->setCallback([this]()
	{
		popState();
	});

	container.addWidget(pvai);
	container.addWidget(pvp);
	container.addWidget(goals);
	container.addWidget(quit);
}

bool MenuState::handleEvent(const sf::Event &event)
{
	container.handleKeyboard(event);
	return false;
}

bool MenuState::update(sf::Time dt)
{
	return false;
}

void MenuState::draw()
{
	getContext().window->draw(container);
	getContext().window->draw(title);
}