#ifndef NEW_GAME_MENU_H
#define NEW_GAME_MENU_H

#include "../engine/settings.h"

//@formatter:off
class NewGameMenu {
private:
    Settings* settings;
    sf::RenderWindow* window;
    int* scene;
    int* submenu;

    sf::Font font;
    sf::Text newGameText;
    sf::Texture gif;		 //gif
    sf::Texture texture_gif; //gif
    sf::Texture texture;
    sf::Texture texture_return;
    sf::Texture v1;
    sf::Texture v2;
    sf::Texture v3;
    sf::Texture v4;
    sf::Texture v5;
    sf::Texture v6;
    sf::Texture v7;
    sf::Texture v8;
    sf::Sprite sprite_gif; //gif
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Sprite sprite4;
    sf::Sprite sprite5;
    sf::Sprite sprite6;
    sf::Sprite sprite7;
    sf::Sprite sprite8;
    sf::Sprite _background;
    sf::Sprite sprite;
    sf::Sprite sprite_return;

public:
    NewGameMenu();
    void update();
    void display();
    void init(Settings*, int*);

private:
    bool isClicked(sf::Text&);
    bool isSpriteClicked(sf::Sprite&);
};

#endif //NEW_GAME_MENU_H
