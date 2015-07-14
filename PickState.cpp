#include "PickState.h"
#include "Menu.h"

void PickState::Initialize(sf::RenderWindow &window)
{
	//Initialize pvp button
	playerButton->load("BabyBlue.conf");
	playerButton->setText("PvP");
	playerButton->setTextSize(30);
	playerButton->setTextColor(sf::Color::White);
	playerButton->setTransparency(0);
	playerButton->setSize(WIDTH, HEIGHT / 2);
	playerButton->setPosition(0, 0);
	playerButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	playerButton->setCallbackId(1);

	//Initialize comp button
	compButton->load("BabyBlue.conf");
	compButton->setText("Comp");
	compButton->setTextSize(30);
	compButton->setTextColor(sf::Color::White);
	compButton->setTransparency(0);
	compButton->setSize(WIDTH, HEIGHT / 2);
	compButton->setPosition(0, HEIGHT / 2);
	compButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	compButton->setCallbackId(2);

	//Add the objects to the gui
	gui.add(playerButton);
	gui.add(compButton);

	//Set the mask
	mask.setSize({ WIDTH, HEIGHT / 2 });
	mask.setPosition(0, 0);
	mask.setFillColor(sf::Color(0, 0, 0, 200));

	//Set the line
	line.setSize({ WIDTH, 6 });
	line.setPosition(0, HEIGHT / 2 - line.getLocalBounds().height / 2);
	line.setFillColor(sf::Color::White);
}

void PickState::Update(sf::RenderWindow &window)
{
	//Check TGUI events
	tgui::Callback callback;
	while (gui.pollCallback(callback))
	{
		switch (callback.id)
		{
		case 1:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play(), mask.setPosition(0, HEIGHT / 2 - 1);
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				clickSound.play(), Destroy(), engine.SetState(new GamePlayer());
			break;
		case 2:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play(), mask.setPosition(0, 0);
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				clickSound.play(), Destroy();//engine.SetState(new Options());
			break;
		default:
			break;
		}
	}
}

void PickState::Draw(sf::RenderWindow &window)
{
	//Draw
	gui.draw();
	window.draw(mask);
	window.draw(line);
}

void PickState::HandleEvents(sf::RenderWindow &window, sf::Event &event)
{
	//Event handler
	gui.handleEvent(event);
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		Destroy(), engine.SetState(new Menu());
}

void PickState::Destroy()
{
	//Destroy all objects
	gui.removeAllWidgets();
}