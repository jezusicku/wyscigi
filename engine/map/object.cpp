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
    window = this->settings->getWindowPointer();
}

void Object::create(sf::Texture *texturePointer, int line, float objectSpeed) {
    texture = *texturePointer;
    speed = objectSpeed;
    sprite.setTexture(texture);
    sprite.setScale(.3f, .3f);
    sprite.setPosition(345.f + float(line * 128), -256.f);
}

bool Object::isVisible() {
    return sprite.getPosition().y > 1200;
}

sf::Sprite * Object::getSpritePointer() {
    return &sprite;
}
