#include "States.h"
#include "Menu.h"
#include "GameObject.h"
#include "SplashScreen.h"

GameState        engine;
SplashScreen     splash;

sf::RenderWindow window;
sf::Music		 introMusic, bgMusic;
sf::Texture		 bgTexture;
sf::Sprite		 bgSprite;
sf::Image		 icon;
sf::Font		 font;
sf::Sound		 clickSound, hoverSound;
sf::SoundBuffer  sb1, sb2;
tgui::Gui	     gui;

unsigned char    opacity = 255;
float			 duration = 2.f;
int				 nivel;

void Initialize();

//TODO
//sinus/cosinus
//options -> scor maxim
//resourcemanager fix
//anim class

int main()
{
	Initialize();
	
	while (window.isOpen())
	{
		//Events
		sf::Event event;
		engine.SetEvent(event);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			engine.HandleEvents();
		}

		//Update, render
		window.clear();

		engine.Update();
		engine.Draw();

		window.display();
	}

	return 0;
}

void Initialize()
{
	/*Initializam window, muzica, imagini, icon.*/
	nivel = 0;
	font.loadFromFile("data/font.ttf");

	sb1.loadFromFile("data/click2.ogg");
	clickSound.setBuffer(sb1);

	sb2.loadFromFile("data/mouseover.ogg");
	hoverSound.setBuffer(sb2);
	hoverSound.setVolume(10);

	//splash.Create(opacity, duration);

	window.create({ WIDTH, HEIGHT }, "Game", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	std::cout << "Window created." << std::endl;

	icon.loadFromFile("data/icon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	gui.setWindow(window);
	gui.setGlobalFont(font);

	engine.SetWindow(window);
	engine.SetState(new Menu());
}