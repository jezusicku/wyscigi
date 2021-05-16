#ifndef CREDITS_MENU_H
#define CREDITS_MENU_H

#include "../engine/settings.h"

//@formatter:off
class CreditsMenu {
    private:
        Settings *settings;
        sf::RenderWindow *window;
        int *scene;
        int *submenu;

        sf::Font font;
        sf::Text returnText;

    public:
        CreditsMenu();
        void update();
        void display();
        void init(Settings *, int *);

    private:
        bool isClicked(sf::Text &);
};

#endif //CREDITS_MENU_H
