#include "engine.h"

Engine::Engine(Settings *settings) {
    this->settings = settings;
    this->window = settings->getWindowPointer();
    this->scene = settings->getScenePointer();
    this->speed = 30.f;
    this->player.init(settings);
    this->player.setSpeedPlayer(speed);
    this->map.init(settings);
}

void Engine::display() {
    map.display();
    player.display();
}

void Engine::update() {
    map.update();
    player.update();
}
