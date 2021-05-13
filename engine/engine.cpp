#include "engine.h"

Engine::Engine(Settings *settings) {
    this->settings = settings;
    this->window = settings->getWindowPointer();
    this->scene = settings->getScenePointer();
    this->player.init(settings);
}

void Engine::display() {
    player.display();
}

void Engine::update() {
    player.update();
}
