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

/**
 * Function displays fuel canister on the screen.
 */
void Fuel::display() {
    if (position < 1200 && position > -100) window->draw(sprite);
}

/**
 * Function changes position of the fuel canister on the screen. Fuel canister will be moved down by specified
 * number of pixels.
 * @param change Number of pixels
 */
void Fuel::update(float change) {
    if (position < 1200) {
        position += change;
        sprite.setPosition(sprite.getPosition().x, position);
    }
    counter++;
}

/**
 * Function initializes object.
 * @param newSettings Pointer to object of class Settings
 * @see Settings
 */
void Fuel::init(Settings *newSettings, int *fuelPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    fuel = fuelPointer;
}

/**
 * Function removes fuel canister from the screen.
 */
void Fuel::clear() {
    this->position = 1500.f;
    counter = -2000;
}

/**
 * @return True if fuel canister must be generated on the screen.
 */
bool Fuel::needCreate() const {
    return counter > 0;
}

/**
 * Creates new fuel canister on the screen. Fuel canister is generated on the given lane.
 * @param lane Lane from range 0-4
 */
void Fuel::create(int lane) {
    position = -200;
    counter = -2000;
    sprite.setPosition(363.f + float(128 * lane), position);
}

/**
 * @param vehicleSprite Pointer to sprite of the player's vehicle
 * @return True if fuel canister collides with player's vehicle
 */
bool Fuel::isCollectable(sf::Sprite *vehicleSprite) {
    sf::Sprite vehicleSpriteCopy = *vehicleSprite;
    if (Collision::BoundingBoxTest(vehicleSpriteCopy, sprite))
        if (Collision::PixelPerfectTest(vehicleSpriteCopy, sprite))
            return true;
    return false;
}

/**
 * Function removes fuel canister from the road and sets vehicle's fuel level to maximum.
 */
void Fuel::collect() {
    position = 1500;
    sprite.setPosition(363.f, position);
    *fuel = settings->getPlayerData().getMaxFuel();
}
