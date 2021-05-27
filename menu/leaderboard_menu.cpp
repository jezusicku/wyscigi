#include "leaderboard_menu.h"

LeaderboardMenu::LeaderboardMenu() {
    settings = nullptr;
    window = nullptr;
    scores = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    if (!leaderboardTexture.loadFromFile("../assets/cars/leaderboard.png")) exit(1);
    leaderboardTexture.setRepeated(false);
    leaderboardTexture.setSmooth(true);

    leaderBoardSprite.setTexture(leaderboardTexture);
    leaderBoardSprite.setScale(.1f, .1f);
    leaderBoardSprite.setPosition(1229.f, 0.f);

    for (int i = 0; i < 24; i++) {
        scoreTexts[i].setFont(font);
        scoreTexts[i].setFillColor(sf::Color::Red);
        scoreTexts[i].setStyle(sf::Text::Bold);
        scoreTexts[i].setCharacterSize(32);
        scoreTexts[i].setPosition(float(100 + 300 * ((i % 12) / 3)), float(220 + 440 * (i / 12) + 65 * (i % 3)));
        scoreTexts[i].setString("XD " + std::to_string(i));
    }
}

void LeaderboardMenu::display() {
    window->draw(sprite_gif);
    window->draw(sprite1);
    window->draw(sprite2);
    window->draw(sprite3);
    window->draw(sprite4);
    window->draw(sprite5);
    window->draw(sprite6);
    window->draw(sprite7);
    window->draw(sprite8);
    window->draw(leaderBoardSprite);

    for (int i = 0; i < 24; ++i) {
        std::string place = std::to_string(i % 3 + 1) + ".\t";
        scoreTexts[i].setString(place + std::to_string(scores->getScore(i / 3, i % 3)));
    }


    for (const auto &scoreText : scoreTexts)
        window->draw(scoreText);
}

void LeaderboardMenu::update() {
    if (isSpriteClicked(leaderBoardSprite)) {
        *submenu = 1;
    }
}

void LeaderboardMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();
    scores = settings->getScoresPointer();

    if (!gif.loadFromFile("../assets/cars/background5.png")) exit(1);
    sprite_gif.setTexture(gif);
    sprite_gif.setPosition(0, 0);
    sprite_gif.setScale(1.5f, 1.5f);

    if (!v1.loadFromFile("../assets/cars/vehicle1-removebg-preview-2.png")) exit(1);
    sprite1.setTexture(v1);
    sprite1.setPosition(100, 20);

    if (!v2.loadFromFile("../assets/cars/vehicle2-removebg-preview-2.png")) exit(1);
    sprite2.setTexture(v2);
    sprite2.setPosition(350, 20);

    if (!v3.loadFromFile("../assets/cars/zygzak_front-removebg-preview.png")) exit(1);
    sprite3.setTexture(v3);
    sprite3.setPosition(630, 60);
    sprite3.setScale(0.56f, 0.56f);

    if (!v4.loadFromFile("../assets/cars/ice_cream_truck-removebg-preview-2.png")) exit(1);
    sprite4.setTexture(v4);
    sprite4.setPosition(950, 70);
    sprite4.setScale(0.9f, 0.9f);

    if (!v5.loadFromFile("../assets/cars/vehicle5-removebg-preview-2.png")) exit(1);
    sprite5.setTexture(v5);
    sprite5.setPosition(100, 470);

    if (!v6.loadFromFile("../assets/cars/vahicle6-removebg-preview-2.png")) exit(1);
    sprite6.setTexture(v6);
    sprite6.setPosition(400, 470);

    if (!v7.loadFromFile("../assets/cars/vehicle7-removebg-preview-2.png")) exit(1);
    sprite7.setTexture(v7);
    sprite7.setPosition(700, 470);

    if (!v8.loadFromFile("../assets/cars/vehicle8-removebg-preview.png")) exit(1);
    sprite8.setTexture(v8);
    sprite8.setPosition(950, 420);
    sprite8.setScale(0.5f, 0.5f);

    submenu = newSubmenu;
}

bool LeaderboardMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + textWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + textHeight;
}

bool LeaderboardMenu::isSpriteClicked(sf::Sprite &sprite) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = sprite.getPosition();
    float imageWidth = sprite.getLocalBounds().width;
    float imageHeight = sprite.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + imageWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + imageHeight;
}
