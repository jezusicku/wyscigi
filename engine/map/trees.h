#ifndef TREES_H
#define TREES_H

#include "tree.h"

//@formatter:off
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

private:
    void generateTrees();
};

#endif //TREES_H
