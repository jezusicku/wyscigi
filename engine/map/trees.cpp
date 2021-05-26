#include "trees.h"

Trees::Trees() {
    this->settings = nullptr;
    this->window = nullptr;
    this->begin = 0;
    this->elements = 0;
    this->lastLeftTree = 0.f;
    this->lastRightTree = 0.f;
}

void Trees::display() {
    for (int i = 0; i < elements; i++)
        trees[(begin + i) % 100].display();
}

void Trees::update(float change) {
    for (int i = 0; i < elements; i++)
        trees[(begin + i) % 100].update(change);
    for (int i = 0; i < elements; i++) {
        if (trees[(begin) % 100].isVisible()) {
            begin++;
            elements--;
        }
    }
    lastLeftTree += change;
    lastRightTree += change;
    generateTrees();
}

void Trees::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = this->settings->getWindowPointer();
    for (int i = 1; i < 48; i++) {
        std::stringstream path;
        path << "../assets/map/trees/tree_";
        if (i < 10) path << "0";
        path << i << ".png";
        if (!textures[i - 1].loadFromFile(path.str())) exit(1);
        textures[i - 1].setRepeated(false);
        textures[i - 1].setSmooth(true);
    }
    for (auto &tree : trees)
        tree.init(newSettings);
}

void Trees::generateTrees() {
    if (lastLeftTree > 0) {
        int texture = rand() % 47;
        lastLeftTree = -60 - rand() % 60;
        float x = 40 + float(rand() % (280 - textures[texture].getSize().x));
        trees[(begin + elements++) % 100].create(&textures[texture], x);
    }
    if (lastRightTree > 0) {
        int texture = rand() % 47;
        lastRightTree = -60 - rand() % 60;
        float x = 960 + float(rand() % (280 - textures[texture].getSize().x));
        trees[(begin + elements++) % 100].create(&textures[texture], x);
    }
}

void Trees::clear() {
    begin = 0;
    elements = 0;
}
