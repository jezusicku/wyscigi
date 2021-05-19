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
    sprite.setScale(.15f, .15f);

    float position;
    if (line == 1) position = 354;
    else if (line == 2) position = 482;
    else if (line == 3) position = 610;
    else if (line == 4) position = 738;
    else position = 866;
    sprite.setPosition(position, -128);
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
