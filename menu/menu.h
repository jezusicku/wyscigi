#ifndef MENU_H
#define MENU_H

#include "../engine/settings.h"

//@formatter:off
class Menu {
    Settings *settings;
    int submenu;

    MainMenu mainMenu;
    NewGameMenu newGameMenu;
    CreditsMenu creditsMenu;
    Splash splash;
    StatsMenu statsMenu;

public:
    explicit Menu(Settings*);
    void display();
    void update();
};

#endif //MENU_H
