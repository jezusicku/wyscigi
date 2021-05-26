#ifndef HUD_H
#define HUD_H

//@formatter:off
class Hud {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *speed;
    int *score;
    int *fuel;

    sf::Font font;
    sf::Text speedText;
    sf::Text scoreText;

    sf::RectangleShape fuelShape;
    sf::RectangleShape currentFuelShape;

public:
    Hud();
    void display();
    void update();
    void init(Settings *, int *, int *);
};

#endif //HUD_H
