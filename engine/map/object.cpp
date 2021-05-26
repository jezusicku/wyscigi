#include "object.h"

Object::Object() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = 0;
}

void Object::display() {
    window->draw(sprite);
}

void Object::update(float change) {
    sprite.move(0.f, change - speed / 10);
}

void Object::init(Settings *newSettings) {
    settings = newSettings;
    window = settings->getWindowPointer();
}

void Object::create(sf::Texture *texturePointer, int line, float objectSpeed) {
    texture = sf::Texture(*texturePointer);
    speed = objectSpeed;
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setScale(.33, .33);
    sprite.setPosition(348.f + float(line * 128), -256.f);
}

bool Object::isVisible() {
    return sprite.getPosition().y > 1200;
}

sf::Sprite * Object::getSpritePointer() {
    return &sprite;
}
