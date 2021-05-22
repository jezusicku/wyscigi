#ifndef OBJECT_H
#define OBJECT_H

//@formatter:off
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
};

#endif //OBJECT_H
