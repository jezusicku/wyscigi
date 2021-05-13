#ifndef ENGINE_H
#define ENGINE_H

#include "settings.h"
#include "player.h"

//@formatter:off
class Engine {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *scene;
    Player player;

public:
    Engine(Settings *settings);
    void display();
    void update();
};

#endif //ENGINE_H
