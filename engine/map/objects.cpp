#include "objects.h"

Objects::Objects() {
    this->settings = nullptr;
    this->window = nullptr;
    this->begin = 0;
    this->end = 0;
}

void Objects::display() {
    for (int i = begin; i != end; i = (i + 1) % 100)
        objects[i].display();
}

void Objects::update() {
    for (int i = begin; i != end; i = (i + 1) % 100)
        objects[i].update();
    if (objects[begin].getYPosition() > 1200 and begin != end) begin++;
}

void Objects::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = newSettings->getWindowPointer();
}

void Objects::addRandomObject() {
    float objectSpeed = 30.f - rand() % 3;
    int objectLine = rand() % 5 + 1;

    std::string texture;
    int randomTexture = rand() % 4;
    if (randomTexture == 0) texture = "../assets/cars/carrera.png";
    else if (randomTexture == 1) texture = "../assets/cars/ferrari.png";
    else if (randomTexture == 2) texture = "../assets/cars/lambo.png";
    else texture = "../assets/cars/jakis.png";

    objects[++end].init(settings, texture, objectSpeed, objectLine);
}
