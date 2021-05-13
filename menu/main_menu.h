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
    sf::Text exitText;

public:
    MainMenu();
    void update();
    void display();
    void init(Settings *, int *);

private:
    bool isClicked(sf::Text &);
};

#endif //MAIN_MENU_H