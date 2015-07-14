#ifndef MENU_H
#define MENU_H

#include "States.h"
#include "Globals.h"
#include "GamePlayer.h"
#include "Options.h"
#include "PickState.h"

class Menu: public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void HandleEvents(sf::RenderWindow &window, sf::Event &event);
private:
	void Destroy();

	//TGUI
	tgui::Button::Ptr playButton;
	tgui::Button::Ptr optionsButton;
	tgui::Button::Ptr quitButton;

	bool			  picking;
	sf::Text		  title;
};

#endif