#include "objects.h"

Objects::Objects() {
    this->settings = nullptr;
    this->window = nullptr;
    this->head = nullptr;
    this->tail = nullptr;
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
    float objectSpeed = 28.f - rand() % 6;
    int objectLine = rand() % 5 + 1;
    newObject->init(settings, "../assets/cars/car.png", objectSpeed, objectLine);
    if (tail == nullptr) {
        head = newObject;
        tail = newObject;
    } else {
        tail->setNext(newObject);
        newObject->setPrev(tail);
        tail = newObject;
    }
}
