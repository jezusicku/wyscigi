#include "settings.h"

Settings::Settings() {
    this->windowPointer = nullptr;
    this->scene = 0;
    this->focus = true;
    this->player = 0;
    this->init = true;
}

void Settings::setWindowPointer(sf::RenderWindow *newWindowPointer) {
    windowPointer = newWindowPointer;
}

sf::RenderWindow *Settings::getWindowPointer() const {
    return windowPointer;
}

int *Settings::getScenePointer() {
    return &scene;
}

bool *Settings::getFocusPointer() {
    return &focus;
}

void Settings::setPlayer(int newPlayer) {
    player = newPlayer;
}

int Settings::getPlayer() {
    return player;
}

void Settings::setInit(int newInit) {
    init = newInit;
}

int Settings::getInit() {
    return init;
}
