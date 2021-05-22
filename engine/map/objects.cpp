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
    generateObjects();
}

void Objects::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    speed = speedPointer;

    if (!textures[0].loadFromFile("../assets/cars/jakis.png")) exit(1);
    if (!textures[1].loadFromFile("../assets/cars/lambo.png")) exit(1);
    if (!textures[2].loadFromFile("../assets/cars/ferrari.png")) exit(1);
    if (!textures[3].loadFromFile("../assets/cars/carrera.png")) exit(1);
    textures[0].setSmooth(true);
    textures[1].setSmooth(true);
    textures[2].setSmooth(true);
    textures[3].setSmooth(true);
    textures[0].setRepeated(false);
    textures[1].setRepeated(false);
    textures[2].setRepeated(false);
    textures[3].setRepeated(false);

    for (auto &object : objects)
        object.init(newSettings);
}

void Objects::generateObjects() {
    if (lastObject > 500 && rand() % 1200 - 200 < lastObject) {
        int texture = rand() % 4;
        int line = rand() % 5;
        auto objectSpeed = float(float(*speed) / 2 - 5 + rand() % 10);
        lastObject = -120;
        objects[(begin + elements++) % 100].create(&textures[texture], line, objectSpeed);
    }
}
