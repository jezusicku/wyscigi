#ifndef SPLASH_H
#define SPLASH_H

//@formatter:off
class Splash {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *scene;
    int *submenu;

    sf::Clock _clock;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Splash();
    void update();
    void display();
    void init(Settings *, int *);
};

#endif //SPLASH_H
