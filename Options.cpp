#include "Options.h"
#include "Menu.h"

void Options::Initialize(sf::RenderWindow &window)
{
	//Initialize difficulty = easy
	copie_nivel = nivel;
	isApplied = false;

	//Initialize title
	title.setString("Options");
	title.setCharacterSize(100);
	title.setFont(font);
	title.setPosition(sf::Vector2f(window.getSize().x / 2 - title.getLocalBounds().width / 2,
		title.getLocalBounds().height));

	//Initialize difficulty text
	diff.diffText.setString("Difficulty");
	diff.diffText.setCharacterSize(25);
	diff.diffText.setFont(font);
	diff.diffText.setPosition({ window.getSize().x / 4 - diff.diffText.getLocalBounds().width / 2, 220 });
	
	//Initialize back button
	backButton->load("BabyBlue.conf");
	backButton->setText("Back");
	backButton->setPosition(WIDTH / 4 - backButton->getSize().x / 2, 420);
	backButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	backButton->setCallbackId(1);

	//Initialize apply button
	applyButton->load("BabyBlue.conf");
	applyButton->setText("Apply");
	applyButton->setPosition(WIDTH / 4 * 3 - applyButton->getSize().x / 2, 420);
	applyButton->bindCallback(tgui::Button::LeftMouseClicked | tgui::Button::MouseEntered);
	applyButton->setCallbackId(2);

	//Initialize difficulty combobox
	diff.combobox->load("BabyBlue.conf");
	diff.combobox->setPosition(300, 200);
	diff.combobox->setSize(120, 21);
	diff.combobox->setPosition(WIDTH / 4 * 3 - diff.combobox->getSize().x / 2, 210);
	diff.combobox->addItem("Easy", 0);
	diff.combobox->addItem("Normal", 1);
	diff.combobox->addItem("Hard", 2);
	diff.combobox->setSelectedItem(nivel);

	//Add the TGUI objects to the gui
	gui.add(backButton);
	gui.add(applyButton);
	gui.add(diff.combobox);
}

void Options::Update(sf::RenderWindow &window)
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
				clickSound.play(), Destroy(), engine.SetState(new Menu());
			break;
		case 2:
			if (callback.trigger == tgui::Button::MouseEntered)
				hoverSound.play();
			else if (callback.trigger == tgui::Button::LeftMouseClicked)
				clickSound.play(), isApplied = true;
			break;
		default:
			break;
		}
	}
	
	//If true then we change the difficulty
	if (isApplied)
	{
		nivel = diff.combobox->getSelectedItemIndex();
		isApplied = false;
	}

	//Menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && window.hasFocus())
	{
		Destroy();
		engine.SetState(new Menu());
	}
}

void Options::Draw(sf::RenderWindow &window)
{
	//Draw 
	window.draw(title);
	window.draw(diff.diffText);
	gui.draw();
}

void Options::HandleEvents(sf::RenderWindow &window, sf::Event &event)
{
	//TGUI event handler
	gui.handleEvent(event);
}

void Options::Destroy()
{
	//Destroy all objects
	gui.removeAllWidgets();
}