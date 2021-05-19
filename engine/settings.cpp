#include "settings.h"

Settings::Settings() {
    windowPointer = nullptr;
    scene = 0;
    focus = true;
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
