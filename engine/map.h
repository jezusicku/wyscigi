#ifndef MAP_H
#define MAP_H

//@formatter:off
class Map {
private:
    Settings* settings;
    sf::RenderWindow *window;
    int lines;

public:
    Map();
    void display();
    void update();
    void init(Settings *);
};

#endif //MAP_H
