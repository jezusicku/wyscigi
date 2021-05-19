#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "../engine/settings.h"

//@formatter:off
class MainMenu {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *scene;
    int *submenu;

    sf::Font font;
    sf::Text newGameText;
    sf::Text creditsText;
    sf::Text exitText;
    sf::Sprite _background;
    sf::Texture texture;
    sf::Sprite sprite;

    sf::Sprite _play_button;

public:
    MainMenu();
    void update();
    void display();
    void init(Settings *, int *);

private:
    bool isClicked(sf::Text &);
};

#endif //MAIN_MENU_H
