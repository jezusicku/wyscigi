#ifndef ENGINE_H
#define ENGINE_H
//@formatter:off

#include "settings.h"
#include "player.h"
#include "map/map.h"

/**
 * Object of this class manages all game mechanics.
 */
class Engine {
private:
    Settings *settings;
    sf::RenderWindow *window;

    int *scene;
    int speed;
    int counter;
    bool pause;
    bool end;
    int score;
    int fuel;

    Player player;
    Map map;
    Hud hud;
    PauseMenu pauseMenu;
    EndGame endGame;

public:
    explicit Engine(Settings *settings);
    void display();
    void update();
    void init();

    void swapPause();
};

#endif //ENGINE_H
