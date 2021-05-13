#include "player.h"

Player::Player() {
    this->settings = nullptr;
    this->window = nullptr;
    this->position = 0;
    this->speed = 10;
    if (!this->texture.loadFromFile("../assets/cars/car.png")) exit(1);
    this->texture.setSmooth(true);
    this->texture.setRepeated(false);
    this->sprite.setTexture(texture);
    this->sprite.setScale(.15, .15);
}

void Player::display() {
    window->draw(sprite);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position -= 7;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position += 7;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        speed++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speed--;
    }

    float newPosition = int(window->getSize().x / 2) - 40 + position;
    sprite.setPosition(newPosition, 580);
}

void Player::init(Settings *newSettings) {
    settings = newSettings;
    window = settings->getWindowPointer();
}
