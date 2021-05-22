#ifndef ENGINE_H
#define ENGINE_H

#include "settings.h"
#include "player.h"
#include "map/map.h"

//@formatter:off
class Engine {
private:
    Settings *settings;
    sf::RenderWindow *window;

    int *scene;
    int speed;
    int counter;

    Player player;
    Map map;
    Hud hud;

public:
    Engine(Settings *settings);
    void display();
    void update();
};

#endif //ENGINE_H
