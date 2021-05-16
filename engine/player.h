#ifndef PLAYER_H
#define PLAYER_H

//@formatter:off
class Player {
private:
    Settings* settings;
    sf::RenderWindow* window;
    float position;
    float speed;
    float rotation;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Player();
    void display();
    void update();
    void init(Settings *);
};

#endif //PLAYER_H
