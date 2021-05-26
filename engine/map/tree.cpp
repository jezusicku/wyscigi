#include "tree.h"

Tree::Tree() {
    this->settings = nullptr;
    this->window = nullptr;
}

void Tree::display() {
    window->draw(sprite);
}

void Tree::update(float change) {
    sprite.move(0.f, change);
}

void Tree::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = settings->getWindowPointer();
}

void Tree::create(sf::Texture *texturePointer, float x) {
    texture = sf::Texture(*texturePointer);
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition(x, -256);
}

bool Tree::isVisible() {
    return sprite.getPosition().y > 1200;
}
