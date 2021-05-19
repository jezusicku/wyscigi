#ifndef MAP_H
#define MAP_H

#include "map/objects.h"

//@formatter:off
class Map {
private:
    Settings* settings;
    sf::RenderWindow *window;
    int *speed;
    Objects objects;
    int lines;
    int counter;

public:
    Map();
    void display();
    void update();
    void init(Settings *);
};

#endif //MAP_H
