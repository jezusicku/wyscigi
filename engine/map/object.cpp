#include "object.h"

Object::Object() {
    this->settings = nullptr;
    this->window = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
    this->speed = 0;
}

void Object::display() {
    window->draw(sprite);
}

void Object::update() {
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed * .1);
}

void Object::init(Settings *newSettings, std::string pathToTexture, float objectSpeed, int line) {
    this->settings = newSettings;
    this->window = this->settings->getWindowPointer();
    this->speed = objectSpeed;

    if (!texture.loadFromFile(pathToTexture)) exit(1);
    texture.setSmooth(true);
    texture.setRepeated(false);

    sprite.setTexture(texture);
    sprite.setScale(.30f, .30f);

    float position, shift = 5;
    if (line == 1) position = 354 - shift;
    else if (line == 2) position = 482 - shift;
    else if (line == 3) position = 610 - shift;
    else if (line == 4) position = 738 - shift;
    else position = 866 - shift;
    sprite.setPosition(position, -256);
}

Object *Object::getNext() {
    return next;
}

void Object::setNext(Object *object) {
    next = object;
}

Object *Object::getPrev() {
    return prev;
}

void Object::setPrev(Object *object) {
    prev = object;
}

float Object::getYPosition() {
    return sprite.getPosition().y;
}
