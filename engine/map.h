#ifndef MAP_H
#define MAP_H

#include "map/objects.h"

//@formatter:off
class Map {
private:
    Settings* settings;
    sf::RenderWindow *window;
    float *speed;
    int counter;
    Objects objects;

    sf::Texture grassTexture;
    sf::RectangleShape grassShape;
    sf::Texture asphaltTexture;
    sf::RectangleShape asphaltShape;
    sf::RectangleShape leftLineShape;
    sf::RectangleShape rightLineShape;
    sf::RectangleShape lineShapes[32];

public:
    Map();
    void display();
    void update();
    void init(Settings *, float *);
};

#endif //MAP_H
