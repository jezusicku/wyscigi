#include "settings.h"

Settings::Settings() {
    windowWidth = 1280;
    windowHeight = 720;
    windowPointer = nullptr;
    scene = 0;
    focus = true;
}

void Settings::setWindowWidth(int newWindowWidth) {
    windowWidth = newWindowWidth;
}

int Settings::getWindowWidth() const {
    return windowWidth;
}

void Settings::setWindowHeight(int newWindowHeight) {
    windowHeight = newWindowHeight;
}

int Settings::getWindowHeight() const {
    return windowHeight;
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
