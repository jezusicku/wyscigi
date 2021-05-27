#include "splash.h"

#define splash_time 2.0

Splash::Splash() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;
}

void Splash::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();

    if (!texture.loadFromFile("../assets/cars/background-removebg-preview.png")) exit(1);
    sprite.setTexture(texture);
    sprite.setPosition(120, 130);

    submenu = newSubmenu;
}

void Splash::update() {
    if (_clock.getElapsedTime().asSeconds() > splash_time)
        *submenu = 1;
}

void Splash::display() {
    window->draw(sprite);
    if (_clock.getElapsedTime().asSeconds() > splash_time)
        *submenu = 1;
}
