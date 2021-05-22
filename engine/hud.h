#ifndef HUD_H
#define HUD_H

//@formatter:off
class Hud {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *speed;

    sf::Font font;
    sf::Text speedText;

public:
    Hud();
    void display();
    void update();
    void init(Settings *, int *);
};

#endif //HUD_H
