#include "Menu.h"

void Menu::Initialize(sf::RenderWindow &window)
{
	/*
	Initializam meniul:
	Font, text, imagini.
	*/
	picking = false;

	//Initialize title
	title.setString("Pong");
	title.setCharacterSize(100);
	title.setFont(font);
	title.setPosition(sf::Vector2f(window.getSize().x / 2 - title.getLocalBounds().width / 2,
		title.getLocalBounds().height));
	
	//Initialize play button
	playButton->load("BabyBlue.conf");
	playButton->setText("Play");
	playButton->setPosition(WIDTH / 2 - playButton->getSize().x / 2, 220);
	playButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	playButton->setCallbackId(1);

	//Initialize options button
	optionsButton->load("BabyBlue.conf");
	optionsButton->setText("Options");
	optionsButton->setPosition(WIDTH / 2 - optionsButton->getSize().x / 2, 290);
	optionsButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	optionsButton->setCallbackId(2);
	
	//Initialize quit button
	quitButton->load("BabyBlue.conf");
	quitButton->setText("Quit");
	quitButton->setPosition(WIDTH / 2 - quitButton->getSize().x / 2, 360);
	quitButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	quitButton->setCallbackId(3);
	
	//Add the TGUI objects to the gui
	gui.add(playButton);
	gui.add(optionsButton);
	gui.add(quitButton);
}

void Menu::Update(sf::RenderWindow &window)
{
	//Check TGUI events
	tgui::Callback callback;
	while (gui.pollCallback(callback))
	{
		switch (callback.id)
		{
		case 1:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play();
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				clickSound.play(), Destroy(), engine.SetState(new PickState());
			break;
		case 2:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play();
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				clickSound.play(), Destroy(), engine.SetState(new Options());
			break;
		case 3:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play();
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				window.close();
			break;
		default:
			break;
		}
	}
	
}

void Menu::Draw(sf::RenderWindow &window)
{
	//Draw
	gui.draw();
	window.draw(title);
}

void Menu::HandleEvents(sf::RenderWindow &window, sf::Event &event)
{
	//TGUI event handler
	gui.handleEvent(event);
}

void Menu::Destroy()
{
	//Destroy all objects
	gui.removeAllWidgets();
}