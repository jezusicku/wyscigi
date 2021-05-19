#ifndef ENGINE_H
#define ENGINE_H

#include "settings.h"
#include "player.h"
#include "map.h"

//@formatter:off
class Engine {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *scene;
    float speed;
    Player player;
    Map map;

public:
    Engine(Settings *settings);
    void display();
    void update();
};

#endif //ENGINE_H
