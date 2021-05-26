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
    Engine(Settings *settings);
    void display();
    void update();
    void init();

    void ScoreCounter();
};

#endif //ENGINE_H
