#ifndef TREE_H
#define TREE_H

//@formatter:off
class Tree {
private:
    Settings* settings;
    sf::RenderWindow *window;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Tree();
    void display();
    void update(float);
    void init(Settings *);
    void create(sf::Texture *, float);
    bool isVisible();
};

#endif //TREE_H
