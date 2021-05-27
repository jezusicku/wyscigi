#ifndef LEADERBOARD_MENU_H
#define LEADERBOARD_MENU_H

class LeaderboardMenu {
private:
    Settings* settings;
    sf::RenderWindow* window;
    Scores *scores;
    int* scene;
    int* submenu;

    sf::Font font;
    sf::Texture gif;
    sf::Texture texture;
    sf::Texture v1;
    sf::Texture v2;
    sf::Texture v3;
    sf::Texture v4;
    sf::Texture v5;
    sf::Texture v6;
    sf::Texture v7;
    sf::Texture v8;
    sf::Sprite sprite_gif;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Sprite sprite4;
    sf::Sprite sprite5;
    sf::Sprite sprite6;
    sf::Sprite sprite7;
    sf::Sprite sprite8;

    sf::Texture leaderboardTexture;
    sf::Sprite leaderBoardSprite;
    sf::Text scoreTexts[24];

public:
    LeaderboardMenu();
    void update();
    void display();
    void init(Settings*, int*);

private:
    bool isClicked(sf::Text&);
    bool isSpriteClicked(sf::Sprite&);
};


#endif //LEADERBOARD_MENU_H
