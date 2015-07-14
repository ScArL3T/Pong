#ifndef OPTIONS_H
#define OPTIONS_H

#include "States.h"
#include "Globals.h"

class Options : public State
{
public:
	void Initialize(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void HandleEvents(sf::RenderWindow &window, sf::Event &event);
private:
	void Destroy();

	//TGUI
	tgui::Button::Ptr backButton;
	tgui::Button::Ptr applyButton;

	sf::Text		  title;
	int				  copie_nivel;
	bool		      isApplied;

	struct difficulty
	{
		sf::Text		    diffText;
		tgui::ComboBox::Ptr combobox;
	}diff;
};

#endif