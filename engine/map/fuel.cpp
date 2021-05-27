#include "fuel.h"

Fuel::Fuel() {
    this->settings = nullptr;
    this->window = nullptr;
    this->position = 1500.f;
    this->counter = -2000;
    this->fuel = nullptr;

    if (!texture.loadFromFile("../assets/map/fuel.png")) exit(1);
    texture.setSmooth(true);
    texture.setRepeated(false);
    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);
}

void Fuel::display() {
    if (position < 1200) window->draw(sprite);
}

void Fuel::update(float change) {
    if (position < 1200) {
        position += change;
        sprite.setPosition(sprite.getPosition().x, position);
    }
    counter++;
}

void Fuel::init(Settings *newSettings, int *fuelPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    fuel = fuelPointer;
}

void Fuel::clear() {
    this->position = 1500.f;
    counter = -2000;
}

bool Fuel::needCreate() const {
    return counter > 0;
}

void Fuel::create(int fuelLine) {
    position = -200;
    counter = -2000;
    sprite.setPosition(363.f + float(128 * fuelLine), position);
}

bool Fuel::isCollectable(sf::Sprite *playerSprite) {
    sf::Sprite playerSpriteCopy = *playerSprite;
    if (Collision::BoundingBoxTest(playerSpriteCopy, sprite)) {
        if (Collision::PixelPerfectTest(playerSpriteCopy, sprite)) {
            return true;
        }
    }
    return false;
}

void Fuel::collect() {
    position = 1500;
    sprite.setPosition(363.f, position);
    *fuel = settings->getPlayerData().getMaxFuel();
}
