#ifndef STATS_MENU_H
#define STATS_MENU_H

class StatsMenu {
private:
    Settings* settings;
    sf::RenderWindow* window;
    int* scene;
    int* submenu;

    sf::Font font;
    sf::Text stats_text;
    sf::Text stats_text1;
    sf::Text stats_text2;
    sf::Text stats_text3;
    sf::Text stats_text4;
    sf::Texture texture;
    sf::Texture texture_return;
    sf::Texture texture_background;
    sf::Texture v1;
    sf::Texture v2;
    sf::Texture v3;
    sf::Texture v4;
    sf::Sprite sprite_background;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Sprite sprite4;
    sf::Sprite _background;
    sf::Sprite sprite;
    sf::Sprite sprite_return;

public:
    StatsMenu();
    void update();
    void display();
    void init(Settings*, int*);

private:
    bool isClicked(sf::Text&);
    bool isSpriteClicked(sf::Sprite&);
};

#endif //STATS_MENU_H
