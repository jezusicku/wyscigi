#ifndef OBJECT_H
#define OBJECT_H

//@formatter:off
class Object {
private:
    Settings *settings;
    sf::RenderWindow *window;
    Object *next, *prev;
    float speed;

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Object();
    void display();
    void update();
    void init(Settings *, std::string, float, int);
    Object *getNext();
    void setNext(Object *object);
    Object *getPrev();
    void setPrev(Object *object);
    float getYPosition();
};


#endif //OBJECT_H
