#include "new_game_menu.h"

NewGameMenu::NewGameMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    newGameText.setFont(font);
    newGameText.setString("CHOOSE YOUR PLAYER");
    newGameText.setCharacterSize(32);
    newGameText.setFillColor(sf::Color::Red);
    newGameText.setStyle(sf::Text::Bold);
    newGameText.setPosition(470, 300);

    if (!leaderboardTexture.loadFromFile("../assets/cars/leaderboard.png")) exit(1);
    leaderboardTexture.setRepeated(false);
    leaderboardTexture.setSmooth(true);

    leaderBoardSprite.setTexture(leaderboardTexture);
    leaderBoardSprite.setScale(.1f, .1f);
    leaderBoardSprite.setPosition(1229.f, 0.f);
}

void NewGameMenu::display() {
    window->draw(sprite_gif);
    window->draw(sprite);
    window->draw(sprite1);
    window->draw(sprite2);
    window->draw(sprite3);
    window->draw(sprite4);
    window->draw(sprite5);
    window->draw(sprite6);
    window->draw(sprite7);
    window->draw(sprite8);
    window->draw(newGameText);
    window->draw(leaderBoardSprite);
}

void NewGameMenu::update() {
    if (isSpriteClicked(sprite1)) {
        settings->setVehicleId(0);
        *submenu = 4;
    } else if (isSpriteClicked(sprite2)) {
        settings->setVehicleId(1);
        *submenu = 4;
    } else if (isSpriteClicked(sprite4)) {
        settings->setVehicleId(3);
        *submenu = 4;
    } else if (isSpriteClicked(sprite5)) {
        settings->setVehicleId(4);
        *submenu = 4;
    } else if (isSpriteClicked(sprite6)) {
        settings->setVehicleId(5);
        *submenu = 4;
    } else if (isSpriteClicked(sprite7)) {
        settings->setVehicleId(6);
        *submenu = 4;
    } else if (isSpriteClicked(sprite8)) {
        settings->setVehicleId(7);
        *submenu = 4;
    } else if (isSpriteClicked(sprite3)) {
        settings->setVehicleId(2);
        *submenu = 4;
    } else if (isSpriteClicked(leaderBoardSprite)) {
        *submenu = 5;
    }
}

void NewGameMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();

    if (!gif.loadFromFile("../assets/cars/background5.png")) exit(1);
    sprite_gif.setTexture(gif);
    sprite_gif.setPosition(0, 0);
    sprite_gif.setScale(1.5f, 1.5f);

    if (!texture.loadFromFile("../assets/cars/logo-removebg-preview.png")) exit(1);
    sprite.setTexture(texture);
    sprite.setPosition(100, 0);

    if (!v1.loadFromFile("../assets/cars/vehicle1-removebg-preview-2.png")) exit(1);
    sprite1.setTexture(v1);
    sprite1.setPosition(100, 400);

    if (!v2.loadFromFile("../assets/cars/vehicle2-removebg-preview-2.png")) exit(1);
    sprite2.setTexture(v2);
    sprite2.setPosition(350, 400);

    if (!v3.loadFromFile("../assets/cars/zygzak_front-removebg-preview.png")) exit(1);
    sprite3.setTexture(v3);
    sprite3.setPosition(630, 440);
    sprite3.setScale(0.56f, 0.56f);

    if (!v4.loadFromFile("../assets/cars/ice_cream_truck-removebg-preview-2.png")) exit(1);
    sprite4.setTexture(v4);
    sprite4.setPosition(950, 430);
    sprite4.setScale(0.9f, 0.9f);

    if (!v5.loadFromFile("../assets/cars/vehicle5-removebg-preview-2.png")) exit(1);
    sprite5.setTexture(v5);
    sprite5.setPosition(100, 650);

    if (!v6.loadFromFile("../assets/cars/vahicle6-removebg-preview-2.png")) exit(1);
    sprite6.setTexture(v6);
    sprite6.setPosition(400, 650);

    if (!v7.loadFromFile("../assets/cars/vehicle7-removebg-preview-2.png")) exit(1);
    sprite7.setTexture(v7);
    sprite7.setPosition(700, 650);

    if (!v8.loadFromFile("../assets/cars/vehicle8-removebg-preview.png")) exit(1);
    sprite8.setTexture(v8);
    sprite8.setPosition(950, 600);
    sprite8.setScale(0.5f, 0.5f);

    submenu = newSubmenu;
}

bool NewGameMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + textWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + textHeight;
}

bool NewGameMenu::isSpriteClicked(sf::Sprite &sprite) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = sprite.getPosition();
    float imageWidth = sprite.getLocalBounds().width;
    float imageHeight = sprite.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + imageWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + imageHeight;
}
