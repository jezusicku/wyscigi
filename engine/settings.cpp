#include "settings.h"

Settings::Settings() {
    this->windowPointer = nullptr;
    this->scene = 0;
    this->focus = true;
    this->playerId = 5;
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

int Settings::getPlayerId() const {
    return playerId;
}

void Settings::setPlayerId(int newPlayerId) {
    playerId = newPlayerId;
}

PlayerData Settings::getPlayerData() {
    return playersData.players[playerId];
}

void Settings::setInit(int newInit) {
    init = newInit;
}

int Settings::getInit() {
    return init;
}
