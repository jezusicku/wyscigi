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
/**
 * Function which turns rotation to zero when no key is pressed, the speed of it depends on vehicle which has been chosen
 */
void Player::rotationZero() {
    if (rotation != 0.0) {
        if (rotation <= .3 && rotation >= -.3) {
            rotation = 0;
        } else if (rotation > 0) {
            rotation -= .5 * settings->getPlayerData().getRotationFactor();
        } else if (rotation < 0) {
            rotation += .5 * settings->getPlayerData().getRotationFactor();
        }
    }
}
/**
 * Function which change player's position on the screen
 */
void Player::update() {
    /**
     * When we push arrow key to the left or right then rotation has change, but only when the player isn't on the
     * edge of the road
     */
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
/**
 * When rotation isn't zero and the player isn't on the edge of the road the player's position is changed.
 * The speed at which the position is changed on the screen depends on the driving speed, vehicle that has been selected
 * and rotation value.
 */
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
/**
 * Function set details about the player, gets it from Settings pointer because there are all of started details about
 * the game and which player was chosen.
 */
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

sf::Sprite *Player::getSpritePointer() {
    return &sprite;
}
