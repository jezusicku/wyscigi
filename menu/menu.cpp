#include "menu.h"

Menu::Menu(Settings *settings) {
    this->settings = settings;
    submenu = 0;

    mainMenu.init(this->settings, &submenu);
    newGameMenu.init(this->settings, &submenu);
    creditsMenu.init(this->settings, &submenu);
}

void Menu::display() {
    if (submenu == 0) mainMenu.display();
    else if (submenu == 1) newGameMenu.display();
    else if (submenu == 2) creditsMenu.display();
}

void Menu::update() {
    if (submenu == 0) mainMenu.update();
    else if (submenu == 1) newGameMenu.update();
    else if (submenu == 2) creditsMenu.update();
}
