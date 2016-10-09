#pragma once

#include <SFML/Graphics.hpp>

#include "SoundPlayer.hpp"
#include "ResourcesID.hpp"
#include "Score.hpp"
#include "GameModes.hpp"

namespace States
{
	class Context
	{
	public:
		explicit Context(sf::RenderWindow &window
						, SoundPlayer &soundPlayer
						, FontManager &fontManager
						, TextureManager &textureManager
						, GameMode &gamemode
						, unsigned int &maxGoals)
			: window(&window)
			, soundPlayer(&soundPlayer)
			, fontManager(&fontManager)
			, textureManager(&textureManager)
			, gamemode(&gamemode)
			, maxGoals(&maxGoals)
		{};

		sf::RenderWindow *window;
		SoundPlayer *soundPlayer;
		FontManager *fontManager;
		TextureManager *textureManager;
		GameMode *gamemode;
		unsigned int *maxGoals;
	};
}