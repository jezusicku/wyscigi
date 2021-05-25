#include "player.h"

Player::Player() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->position = 0;
    this->rotation = 0;
    if (!this->texture.loadFromFile("../assets/cars/ferrari2.png")) exit(1);
    this->texture.setSmooth(true);
    this->texture.setRepeated(false);
    this->sprite.setTexture(texture);
    this->sprite.setScale(.3, .3);
    this->sprite.setOrigin(sf::Vector2f((texture.getSize().x * .3) / 2, texture.getSize().y * .3));
}

void Player::display() {
    window->draw(sprite);
}

void Player::rotationZero() {
    if (rotation != 0.0) {
        if (rotation <= .3 && rotation >= -.3) {
            rotation = 0;
        } else if (rotation > 0) {
            rotation -= .5;
        } else if (rotation < 0) {
            rotation += .5;
        }
    }
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (rotation > 0.0) {
            rotationZero();
        }
        rotation -= .15;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (rotation < 0.0) {
            rotationZero();
        }
        rotation += .15;
    }

    if (rotation > 0 && position < 295) {
        position += 2 * rotation * (float(*speed) / 100);
    } else if (rotation < 0 && position > -260) {
        position += 2 * rotation * (float(*speed) / 100);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rotationZero();
    }
    float newPosition = int(window->getSize().x / 2) - 40 + position;
    sprite.setPosition(newPosition, 720);
    sprite.setRotation(rotation);
}

void Player::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    speed = speedPointer;

    // tutaj nalezy przygotowac wszystkie rzeczy przed rozpoczeciem gry:
    // wysrodkowac pojazd, zresetowac skret, wczytac teksture itp
    // id wybranego gracza mozna uzyskac poprzez: settings->getPlayer()
    // funkcja settings->getPlayer() zwraca inta ze zbioru {0, 1, 2, ..., 7}

}


sf::Sprite *Player::getSpritePointer() {
    return &sprite;
}
