#ifndef MENU_H
#define MENU_H

#include "../engine/settings.h"

//@formatter:off
class Menu {
    Settings *settings;
    int submenu;

    NewGameMenu newGameMenu;
    Splash splash;
    StatsMenu statsMenu;
    LeaderboardMenu leaderboardMenu;

public:
    explicit Menu(Settings*);
    void display();
    void update();
};

#endif //MENU_H
