#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <TGUI/Button.hpp>
#include <TGUI/TGUI.hpp>

#define WIDTH    640
#define HEIGHT   480

extern sf::Font  font;
extern sf::Sound clickSound;
extern sf::Sound hoverSound;
extern tgui::Gui gui;
extern int	     nivel;

#endif