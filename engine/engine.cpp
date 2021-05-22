#include "engine.h"

Engine::Engine(Settings *settings) {
    this->settings = settings;
    this->window = settings->getWindowPointer();
    this->scene = settings->getScenePointer();
    this->speed = 20;
    this->counter = 0;
    this->pause = false;
    this->player.init(settings);
    this->player.setSpeedPlayer(float(speed));
    this->map.init(settings, &speed);
    this->hud.init(settings, &speed);
    this->pauseMenu.init(settings, &pause);
}

void Engine::display() {
    map.display();
    player.display();
    hud.display();
    if (pause) pauseMenu.display();
}

void Engine::update() {
    if (!*settings->getFocusPointer()) pause = true;
    if (!pause) {
        map.update();
        player.update();
        if (++counter == 100 and speed < 60) {
            counter = 0;
            speed++;
        }
        hud.update();
    } else {
        pauseMenu.update();
    }
}
