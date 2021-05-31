#ifndef OBJECT_H
#define OBJECT_H
//@formatter:off

/**
 * Object of this class represents single car on the screen.
 */
class Object {
private:
    Settings *settings;
    sf::RenderWindow *window;
    float speed;

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Object();
    void display();
    void update(float);
    void init(Settings *);
    void create(sf::Texture *, int, float);
    bool isVisible();

    sf::Sprite *getSpritePointer();
};

#endif //OBJECT_H
