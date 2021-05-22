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
    void update();
    void init(Settings *, std::string, float, int);
    float getYPosition();
};

#endif //OBJECT_H
