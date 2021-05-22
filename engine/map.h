#ifndef MAP_H
#define MAP_H

#include "map/objects.h"
#include "map/trees.h"

//@formatter:off
class Map {
private:
    Settings* settings;
    sf::RenderWindow *window;
    int *speed;
    float counter;

    sf::Texture grassTexture;
    sf::RectangleShape grassShape;
    sf::Texture asphaltTexture;
    sf::RectangleShape asphaltShape;
    sf::RectangleShape leftLineShape;
    sf::RectangleShape rightLineShape;
    sf::RectangleShape lineShapes[32];

    Objects objects;
    Trees trees;

public:
    Map();
    void display();
    void update();
    void init(Settings *, int *);
};

#endif //MAP_H
