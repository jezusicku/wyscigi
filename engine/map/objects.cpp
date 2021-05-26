#include "objects.h"

Objects::Objects() {
    this->settings = nullptr;
    this->window = nullptr;
    this->begin = 0;
    this->elements = 0;
    this->speed = nullptr;
    this->lastObject = 0;
}

void Objects::display() {
    for (int i = 0; i < elements; i++)
        objects[(begin + i) % 100].display();
}

void Objects::update(float change) {
    for (int i = 0; i < elements; i++)
        objects[(begin + i) % 100].update(change);
    for (int i = 0; i < elements; i++) {
        if (objects[(begin) % 100].isVisible()) {
            begin++;
            elements--;
        }
    }
    lastObject += change;
}

void Objects::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    speed = speedPointer;

    for (int i = 1; i < 18; i++) {
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

void Objects::generateObject(int line) {
    int texture = rand() % 18;
    auto objectSpeed = float(float(*speed) / 2 - 5 + rand() % 10);
    objects[(begin + elements++) % 100].create(&textures[texture], line, objectSpeed);
}

bool Objects::collide(sf::Sprite *playerSprite) {
    for (int i = 0; i < elements; i++)
        if (Collision::BoundingBoxTest(*playerSprite, *objects[(begin + i) % 100].getSpritePointer()))
            if (Collision::PixelPerfectTest(*playerSprite, *objects[(begin + i) % 100].getSpritePointer()))
                return true;
    return false;
}

void Objects::clear() {
    begin = 0;
    elements = 0;
}
