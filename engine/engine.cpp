#include "engine.h"

Engine::Engine(Settings *settings) {
    this->settings = settings;
    this->window = settings->getWindowPointer();
    this->scene = settings->getScenePointer();
    this->speed = 20;
    this->counter = 0;
    this->player.init(settings);
    this->player.setSpeedPlayer(speed);
    this->map.init(settings, &speed);
}

void Engine::display() {
    map.display();
    player.display();
}

void Engine::update() {
    map.update();
    player.update();
    if (++counter == 100 and speed < 60) {
        counter = 0;
        speed++;
    }
}
