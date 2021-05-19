#include "new_game_menu.h"

NewGameMenu::NewGameMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf"))
        exit(1);

    newGameText.setFont(font);
    newGameText.setString("CHOOSE YOUR PLAYER");
    newGameText.setCharacterSize(32);
    newGameText.setFillColor(sf::Color::Red);
    newGameText.setStyle(sf::Text::Bold);
    newGameText.setPosition(470, 220);

    /*returnText.setFont(font);
    returnText.setString("Return");
    returnText.setCharacterSize(32);
    returnText.setFillColor(sf::Color::Green);
    returnText.setStyle(sf::Text::Bold);
    returnText.setPosition(50, 150);*/
}

void NewGameMenu::display() {
    window->draw(sprite_gif);
    window->draw(sprite_return);
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
}

void NewGameMenu::update() {
    if (isSpriteClicked(sprite))
        *scene = 1;
    else if (isSpriteClicked(sprite_return))
        *submenu = 3;
    else if (isSpriteClicked(sprite1))
        settings->temp = 1;
    else if (isSpriteClicked(sprite2))
        settings->temp = 2;
    else if (isSpriteClicked(sprite3))
        settings->temp = 3;
    else if (isSpriteClicked(sprite4))
        settings->temp = 4;
    else if (isSpriteClicked(sprite5))
        settings->temp = 5;
    else if (isSpriteClicked(sprite6))
        settings->temp = 6;
    else if (isSpriteClicked(sprite7))
        settings->temp = 7;
    else if (isSpriteClicked(sprite8))
        settings->temp = 8;
}

void NewGameMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();

    this->gif.loadFromFile("../assets/cars/background5.png");
    this->sprite_gif.setTexture(gif);
    this->sprite_gif.setPosition(0, 5);

    //this->sprite_gif;
    //this->sprite_gif.setPosition(100, 100);

    this->texture.loadFromFile("../assets/cars/play_button-removebg-preview.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(80, 50);

    this->v1.loadFromFile("../assets/cars/vehicle1-removebg-preview-2.png");
    this->sprite1.setTexture(v1);
    this->sprite1.setPosition(50, 250);

    this->v2.loadFromFile("../assets/cars/vehicle2-removebg-preview-2.png");
    this->sprite2.setTexture(v2);
    this->sprite2.setPosition(300, 250);

    this->v3.loadFromFile("../assets/cars/vehicle3-removebg-preview-2.png");
    this->sprite3.setTexture(v3);
    this->sprite3.setPosition(550, 250);

    this->v4.loadFromFile("../assets/cars/vehicle4-removebg-preview-2.png");
    this->sprite4.setTexture(v4);
    this->sprite4.setPosition(900, 250);

    this->v5.loadFromFile("../assets/cars/vehicle5-removebg-preview-2.png");
    this->sprite5.setTexture(v5);
    this->sprite5.setPosition(50, 500);

    this->v6.loadFromFile("../assets/cars/vahicle6-removebg-preview-2.png");
    this->sprite6.setTexture(v6);
    this->sprite6.setPosition(350, 500);

    this->v7.loadFromFile("../assets/cars/vehicle7-removebg-preview-2.png");
    this->sprite7.setTexture(v7);
    this->sprite7.setPosition(650, 500);

    this->v8.loadFromFile("../assets/cars/vehicle8-removebg-preview-2.png");
    this->sprite8.setTexture(v8);
    this->sprite8.setPosition(900, 500);

    this->texture_return.loadFromFile("../assets/cars/return_button-removebg-preview-2.png");
    this->sprite_return.setTexture(texture_return);
    this->sprite_return.setPosition(1100, 50);

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
