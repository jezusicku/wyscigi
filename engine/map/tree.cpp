#include "tree.h"

Tree::Tree() {
    this->settings = nullptr;
    this->window = nullptr;
}

/**
 * Function displays the tree on the screen.
 */
void Tree::display() {
    window->draw(sprite);
}

/**
 * Function changes position of the tree on the screen. Tree will be moved down by specified number of pixels.
 * @param change Number of pixels
 */
void Tree::update(float change) {
    sprite.move(0.f, change);
}

/**
 * Function initializes object.
 * @param newSettings Pointer to object of class Settings
 * @see Settings
 */
void Tree::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = settings->getWindowPointer();
}

/**
 * Function creates new tree with given texture. Coordinates of the top left corner of texture are set to [x, -256].
 * @param texturePointer Pointer to tree texture
 * @param x Coordinate x of the top left corner of the texture
 */
void Tree::create(sf::Texture *texturePointer, float x) {
    texture = sf::Texture(*texturePointer);
    sprite = sf::Sprite();
    sprite.setTexture(texture);
    sprite.setPosition(x, -256);
}

/**
 * @return True if tree is visible on the screen
 */
bool Tree::isVisible() {
    return sprite.getPosition().y > 1200;
}
