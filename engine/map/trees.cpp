#include "trees.h"

Trees::Trees() {
    this->settings = nullptr;
    this->window = nullptr;
    this->begin = 0;
    this->elements = 0;
    this->lastLeftTree = 0.f;
    this->lastRightTree = 0.f;
}

/**
 * Function displays all trees on the screen.
 */
void Trees::display() {
    for (int i = 0; i < elements; i++)
        trees[(begin + i) % 100].display();
}

/**
 * Function changes position of all visible trees on the screen. Trees will be moved down by specified number of pixels.
 * Function also try to generate new trees with method generateTrees().
 * @param change Number of pixels
 */
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

/**
 * Function initializes object, loads all necessary textures to memory and initializes all trees.
 * @param newSettings Pointer to object of class Settings
 * @see Settings
 */
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

/**
 * Function generates new trees on the screen only if previously generated tree has moved away by specified number of
 * pixels. When new tree is generated then new distance is drawn after which another tree will generate. Trees on the
 * left and right side of the road are generated independently.
 */
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

/**
 * Function removes all trees from the screen.
 */
void Trees::clear() {
    begin = 0;
    elements = 0;
}
