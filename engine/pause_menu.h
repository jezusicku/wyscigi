#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H
//@formatter:off

/**
 * Object of this class displays pause menu.
 */
class PauseMenu {
private:
    Settings *settings;
    sf::RenderWindow *window;
    bool *pause;

    sf::RectangleShape background;
    sf::Font font;
    sf::Text continueText;

public:
    PauseMenu();
    void display();
    void update();
    void init(Settings *, bool *);

private:
    bool isClicked(sf::Text &);
};

#endif //PAUSE_MENU_H
