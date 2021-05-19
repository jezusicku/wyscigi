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
    sf::Texture _background_texture;
    sf::Texture texture;
    sf::Sprite _background;
    sf::Sprite sprite;

public:
    Splash();
    void update();
    void display();
    void init(Settings *, int *);
};

#endif //SPLASH_H
