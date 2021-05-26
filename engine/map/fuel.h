#ifndef FUEL_H
#define FUEL_H

//@formatter:off
class Fuel {
private:
    Settings *settings;
    sf::RenderWindow *window;
    float position;
    int counter;
    int *fuel;

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Fuel();
    void display();
    void update(float);
    void init(Settings *, int *);
    void clear();
    bool needCreate() const;
    void create(int);
    bool isCollectable(sf::Sprite *);
    void collect();
};

#endif //FUEL_H
