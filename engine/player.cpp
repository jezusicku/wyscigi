#include "player.h"

Player::Player() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->position = 0;
    this->rotation = 0;
    if (!this->texture.loadFromFile("../assets/cars/bolid.png")) exit(1);
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
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && position > -280) {
        if (rotation > 0.0) {
            rotationZero();
        }
        rotation -= .15;
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && position < 280) {
        if (rotation < 0.0) {
            rotationZero();
        }
        rotation += .15;
    }

    if (rotation > 0 && position < 280) {
        position += (2 * rotation * (float(*speed) / 100)) * settings->getPlayerData().getRotationFactor();
    } else if (rotation < 0 && position > -280) {
        position += (2 * rotation * (float(*speed) / 100)) * settings->getPlayerData().getRotationFactor();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rotationZero();
    }
    float newPosition = int(window->getSize().x - settings->getPlayerData().getCoordinateX()) / 2 + position;
    sprite.setPosition(newPosition, settings->getPlayerData().getCoordinateY());
    sprite.setRotation(rotation);
}

void Player::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    speed = speedPointer;
    sprite.setPosition((window->getSize().x - settings->getPlayerData().getCoordinateX()) / 2, settings->getPlayerData().getCoordinateY());
    position = 0;
    rotation = 0;
    if (!(texture.loadFromFile(settings->getPlayerData().getTexture()))) exit(1);
    sprite.setTexture(texture);
    this->sprite.setScale(settings->getPlayerData().getScale(), settings->getPlayerData().getScale());
    sprite.setOrigin(sf::Vector2f((texture.getSize().x * .3) / 2, texture.getSize().y * .3));
    }

    // tutaj nalezy przygotowac wszystkie rzeczy przed rozpoczeciem gry:
    // wysrodkowac pojazd, zresetowac skret, wczytac teksture itp
    // dane wybranego gracza mozna uzyskac przykładowo w poniższy sposób:
    // settings->getPlayerData().getTexture(); (zwraca std::string)


sf::Sprite *Player::getSpritePointer() {
    return &sprite;
}
