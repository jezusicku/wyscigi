#include "object.h"

Object::Object() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = 0;
}

/**
 * Function display the car on the screen.
 */
void Object::display() {
    window->draw(sprite);
}

/**
 * Function changes position of the car on the screen. Car will be moved down by specified number of pixels minus
 * current car speed divided by 10.
 * @param change Number of pixels
 */
void Object::update(float change) {
    sprite.move(0.f, change - speed / 10);
}

/**
 * Function initializes object.
 * @param newSettings Pointer to object of class Settings
 * @see Settings
 */
void Object::init(Settings *newSettings) {
    settings = newSettings;
    window = settings->getWindowPointer();
}

/**
 * Function creates new car with given texture. Car is set on the given lane and it's speed is set to given speed.
 * Speed and lane doesn't change after object updates.
 * @param texturePointer Pointer to car texture
 * @param lane Lane from range 0-5
 * @param objectSpeed Speed
 * @note Speed must be less than player's vehicle speed.
 */
void Object::create(sf::Texture *texturePointer, int lane, float objectSpeed) {
    texture = sf::Texture(*texturePointer);
    speed = objectSpeed;
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setScale(.33, .33);
    sprite.setPosition(348.f + float(lane * 128), -256.f);
}

/**
 * @return True if car is visible on the screen
 */
bool Object::isVisible() {
    return sprite.getPosition().y > 1200;
}

/**
 * @return Pointer to car sprite
 */
sf::Sprite * Object::getSpritePointer() {
    return &sprite;
}
