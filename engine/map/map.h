#ifndef MAP_H
#define MAP_H
//@formatter:off

#include "objects.h"
#include "trees.h"
#include "fuel.h"

/**
 * Object of this class manages road, roadside, trees, vehicles and other objects.
 */
class Map {
private:
    Settings* settings;
    sf::RenderWindow *window;
    int *speed;
    int *score;
    int *fuel;
    float counter;
    float scoreCounter;
    float fuelCounter;
    float lanes[5];

    sf::Texture grassTexture;
    sf::RectangleShape grassShape;
    sf::Texture asphaltTexture;
    sf::RectangleShape asphaltShape;
    sf::RectangleShape leftLineShape;
    sf::RectangleShape rightLineShape;
    sf::RectangleShape lineShapes[32];

    Objects objects;
    Trees trees;
    Fuel fuels;

public:
    Map();
    void display();
    void update(sf::Sprite *);
    void init(Settings *, int *, int *, int *);
    void clear();

    bool collide(sf::Sprite *);
};

#endif //MAP_H
