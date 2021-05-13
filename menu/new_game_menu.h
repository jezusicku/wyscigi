#ifndef NEW_GAME_MENU_H
#define NEW_GAME_MENU_H

#include "../engine/settings.h"

//@formatter:off
class NewGameMenu {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *scene;
    int *submenu;

    sf::Font font;
    sf::Text newGameText;
    sf::Text returnText;

public:
    NewGameMenu();
    void update();
    void display();
    void init(Settings*, int*);

private:
    bool isClicked(sf::Text &);
};

#endif //NEW_GAME_MENU_H
