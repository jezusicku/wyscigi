#ifndef OBJECTS_H
#define OBJECTS_H

#include "object.h"

//@formatter:off
class Objects {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *speed;
    Object objects[100];
    int begin, elements;
    sf::Texture textures[4];
    float lastObject;

public:
    Objects();
    void display();
    void update(float);
    void init(Settings *, int *);
    void clear();

    bool collide(sf::Sprite *);

private:
    void generateObjects();
};

#endif //OBJECTS_H
