#ifndef OBJECTS_H
#define OBJECTS_H
//@formatter:off

#include "object.h"

/**
 * Object of this class generates, displays and removes cars on the screen.
 */
class Objects {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *speed;
    Object objects[100];
    int begin, elements;
    sf::Texture textures[19];
    float lastObject;

public:
    Objects();
    void display();
    void update(float);
    void init(Settings *, int *);
    void clear();

    bool collide(sf::Sprite *);
    void generateObject(int);
};

#endif //OBJECTS_H
