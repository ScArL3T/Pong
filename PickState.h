#ifndef PICKSTATE_H
#define PICKSTATE_H

#include "States.h"
#include "Globals.h"
#include "GamePlayer.h"

class PickState : public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void HandleEvents(sf::RenderWindow &window, sf::Event &event);
private:
	void Destroy();

	//TGUI
	tgui::Button::Ptr  playerButton;
	tgui::Button::Ptr  compButton;

	sf::RectangleShape mask, line;

	bool			   picking;
	sf::Text		   title;
};

#endif