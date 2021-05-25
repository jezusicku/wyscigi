#ifndef PLAYER_H
#define PLAYER_H

//@formatter:off
class Player {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *speed;
    float position;
    float rotation;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Player();
    void display();
    void update();
    void init(Settings *, int *);
    void rotationZero();

    sf::Sprite *getSpritePointer();
};

#endif //PLAYER_H
