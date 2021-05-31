#ifndef TREES_H
#define TREES_H
//@formatter:off

#include "tree.h"

/**
 * Object of this class generates, displays and removes trees on the screen.
 */
class Trees {
private:
    Settings* settings;
    sf::RenderWindow *window;
    Tree trees[100];
    int begin, elements;
    float lastLeftTree, lastRightTree;
    sf::Texture textures[47];

public:
    Trees();
    void display();
    void update(float);
    void init(Settings *);
    void clear();

private:
    void generateTrees();
};

#endif //TREES_H
