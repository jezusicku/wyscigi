#include "menu.h"

Menu::Menu(Settings *settings) {
    this->settings = settings;
    submenu = 3; // default 3

    newGameMenu.init(this->settings, &submenu);
    splash.init(this->settings, &submenu);
    statsMenu.init(this->settings, &submenu);
    leaderboardMenu.init(this->settings, &submenu);
}

void Menu::display() {
    if (submenu == 1) newGameMenu.display();
    else if (submenu == 3) splash.display();
    else if (submenu == 4) statsMenu.display();
    else if (submenu == 5) leaderboardMenu.display();
}

void Menu::update() {
    if (submenu == 1) newGameMenu.update();
    else if (submenu == 3) splash.update();
    else if (submenu == 4) statsMenu.update();
    else if (submenu == 5) leaderboardMenu.update();
}
