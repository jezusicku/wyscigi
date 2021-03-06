#ifndef MAIN_H
#define MAIN_H

#include <cstring>
#include <sstream>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

#include "engine/scores.cpp"

#include "menu/new_game_menu.cpp"
#include "menu/splash.cpp"
#include "menu/stats_menu.cpp"
#include "menu/leaderboard_menu.cpp"
#include "menu/menu.cpp"

#include "engine/data/player.cpp"

#include "engine/collision.cpp"
#include "engine/pause_menu.cpp"
#include "engine/hud.cpp"
#include "engine/player.cpp"
#include "engine/settings.cpp"
#include "engine/end_game.cpp"
#include "engine/engine.cpp"

#include "engine/map/object.cpp"
#include "engine/map/objects.cpp"
#include "engine/map/tree.cpp"
#include "engine/map/trees.cpp"
#include "engine/map/fuel.cpp"
#include "engine/map/map.cpp"

#endif //MAIN_H
