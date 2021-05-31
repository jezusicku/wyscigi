#include "objects.h"

Objects::Objects() {
    this->settings = nullptr;
    this->window = nullptr;
    this->begin = 0;
    this->elements = 0;
    this->speed = nullptr;
    this->lastObject = 0;
}

/**
 * Function displays all cars on the screen.
 */
void Objects::display() {
    for (int i = 0; i < elements; i++)
        objects[(begin + i) % 100].display();
}

/**
 * Function changes position of all visible cars on the screen. Cars will be moved down by specified number of pixels
 * minus speed of car divided by 10. Function also removes invisible cars from screen.
 * @param change Number of pixels
 */
void Objects::update(float change) {
    for (int i = 0; i < elements; i++)
        objects[(begin + i) % 100].update(change);
    for (int i = 0; i < elements; i++) {
        if (objects[(begin) % 100].isVisible()) {
            begin = (begin + 1) % 100;
            elements--;
        }
    }
    lastObject += change;
}

/**
 * Function initializes object, loads all necessary textures to memory and initializes all cars.
 * @param newSettings Pointer to object of class Settings
 * @param speedPointer Pointer to player's vehicle speed
 * @see Settings
 */
void Objects::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    speed = speedPointer;

    for (int i = 1; i < 20; i++) {
        std::stringstream path;
        path << "../assets/map/objects/car_";
        if (i < 10) path << "0";
        path << i << ".png";
        if (!textures[i - 1].loadFromFile(path.str())) exit(1);
        textures[i - 1].setRepeated(false);
        textures[i - 1].setSmooth(true);
    }

    for (auto &object : objects)
        object.init(newSettings);
}

/**
 * Function generates new car on the given lane. Car texture is selected randomly and car speed is set to approximately
 * 50% of the player's vehicle speed.
 * @param lane Lane from range 1-5
 */
void Objects::generateObject(int lane) {
    int texture = rand() % 20;
    auto objectSpeed = float(float(*speed) / 2 - 5 + rand() % 10);
    objects[(begin + elements++) % 100].create(&textures[texture], lane, objectSpeed);
}

/**
 * @param vehicleSprite Pointer to player's vehicle sprite
 * @return True if player collides with any of the cars.
 */
bool Objects::collide(sf::Sprite *vehicleSprite) {
    for (int i = 0; i < elements; i++)
        if (Collision::BoundingBoxTest(*vehicleSprite, *objects[(begin + i) % 100].getSpritePointer()))
            if (Collision::PixelPerfectTest(*vehicleSprite, *objects[(begin + i) % 100].getSpritePointer()))
                return true;
    return false;
}

/**
 * Function removes all cars from the screen.
 */
void Objects::clear() {
    begin = 0;
    elements = 0;
}
