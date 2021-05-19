#include "objects.h"

Objects::Objects() {
    this->settings = nullptr;
    this->window = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
    this->tempLastLine = -1;
}

void Objects::display() {
    for (Object *object = head; object != nullptr; object = object->getNext())
        object->display();
}

void Objects::update() {
    for (Object *object = head; object != nullptr; object = object->getNext())
        object->update();
    Object *object = tail;
    while (object != nullptr) {
        if (object->getYPosition() > 1200) {
            tail = object->getPrev();
            free(object);
            if (tail == nullptr) {
                head = nullptr;
                break;
            } else tail->setNext(nullptr);
        } else break;
    }
}

void Objects::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = newSettings->getWindowPointer();
}

void Objects::addRandomObject() {
    auto *newObject = new Object;
    float objectSpeed = 28.f - rand() % 4;
    int objectLine = rand() % 5 + 1;
    if (objectLine == tempLastLine) objectLine++;
    if (objectLine > 5) objectLine = 1;

    std::string texture;
    int randomTexture = rand() % 4;
    if (randomTexture == 0) texture = "../assets/cars/carrera.png";
    else if (randomTexture == 1) texture = "../assets/cars/ferrari.png";
    else if (randomTexture == 2) texture = "../assets/cars/lambo.png";
    else texture = "../assets/cars/jakis.png";

    newObject->init(settings, texture, objectSpeed, objectLine);
    if (tail == nullptr) {
        head = newObject;
        tail = newObject;
    } else {
        tail->setNext(newObject);
        newObject->setPrev(tail);
        tail = newObject;
    }
}
