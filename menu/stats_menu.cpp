#include "stats_menu.h"

StatsMenu::StatsMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    stats_text.setFont(font);
    stats_text.setString("STATS");
    stats_text.setCharacterSize(32);
    stats_text.setFillColor(sf::Color::White);
    stats_text.setStyle(sf::Text::Bold);
    stats_text.setPosition(100, 300);

    stats_text1.setFont(font);
    stats_text1.setString("ACCELERATION:  5.00s");
    stats_text1.setCharacterSize(32);
    stats_text1.setFillColor(sf::Color::White);
    stats_text1.setStyle(sf::Text::Bold);
    stats_text1.setPosition(50, 400);

    stats_text2.setFont(font);
    stats_text2.setString("TOP SPEED:  211.1km/h");
    stats_text2.setCharacterSize(32);
    stats_text2.setFillColor(sf::Color::White);
    stats_text2.setStyle(sf::Text::Bold);
    stats_text2.setPosition(50, 500);

    stats_text3.setFont(font);
    stats_text3.setString("WEIGHT:  50kg");
    stats_text3.setCharacterSize(32);
    stats_text3.setFillColor(sf::Color::White);
    stats_text3.setStyle(sf::Text::Bold);
    stats_text3.setPosition(50, 600);

    stats_text4.setFont(font);
    stats_text4.setString("HANDLING:  1.300Gs");
    stats_text4.setCharacterSize(32);
    stats_text4.setFillColor(sf::Color::White);
    stats_text4.setStyle(sf::Text::Bold);
    stats_text4.setPosition(50, 700);
}

void StatsMenu::display() {
    std::stringstream ss;
    ss << "ACCELERATION:\t" << settings->getPlayerData().getAcceleration();
    stats_text1.setString(ss.str());
    ss.str("");
    ss.clear();
    ss << "INITIAL / TOP SPEED:\t" << settings->getPlayerData().getInitSpeed() << " / "
       << settings->getPlayerData().getMaxSpeed();
    stats_text2.setString(ss.str());
    ss.str("");
    ss.clear();
    ss << "INITIAL / MAX FUEL:\t" << settings->getPlayerData().getInitFuel() << " / "
       << settings->getPlayerData().getMaxFuel();
    stats_text3.setString(ss.str());
    ss.str("");
    ss.clear();
    ss << "ROTATION:\t" << settings->getPlayerData().getRotationFactor();
    stats_text4.setString(ss.str());

    v1.loadFromFile(settings->getPlayerData().getPreviewTexture());
    sprite1 = sf::Sprite();
    sprite1.setTexture(v1);

    if (settings->getPlayerId() == 0) {
        this->sprite1.setPosition(900, 365);
        this->sprite1.setScale(1.5f, 1.5f);
    } else if (settings->getPlayerId() == 1) {
        this->sprite1.setPosition(900, 365);
        this->sprite1.setScale(1.5f, 1.5f);
    } else if (settings->getPlayerId() == 2) {
        this->sprite1.setPosition(800, 410);
        this->sprite1.setScale(0.85f, 0.85f);
    } else if (settings->getPlayerId() == 3) {
        this->sprite1.setPosition(850, 410);
        this->sprite1.setScale(1.25f, 1.25);
    } else if (settings->getPlayerId() == 4) {
        this->sprite1.setPosition(900, 365);
        this->sprite1.setScale(1.5f, 1.5f);
    } else if (settings->getPlayerId() == 5) {
        this->sprite1.setPosition(900, 365);
        this->sprite1.setScale(1.5f, 1.5f);
    } else if (settings->getPlayerId() == 6) {
        this->sprite1.setPosition(900, 365);
        this->sprite1.setScale(1.5f, 1.5f);
    } else if (settings->getPlayerId() == 7) {
        this->sprite1.setPosition(840, 315);
        this->sprite1.setScale(0.8f, 0.8f);
    }


    window->draw(sprite_background);
    window->draw(sprite_return);
    window->draw(sprite);
    window->draw(sprite1);
    /*window->draw(sprite2);
    window->draw(sprite3);
    window->draw(sprite4);*/
    window->draw(stats_text);
    window->draw(stats_text1);
    window->draw(stats_text2);
    window->draw(stats_text3);
    window->draw(stats_text4);
}

void StatsMenu::update() {
    if (isSpriteClicked(sprite))
        *scene = 1;
    else if (isSpriteClicked(sprite_return))
        *submenu = 1;
}

void StatsMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();

    /*this->texture_background.loadFromFile(PATH + "/assets/cars/stats_background.png");
    this->sprite_background.setTexture(texture_background);
    this->sprite_background.setPosition(0, 0);
    this->sprite_background.setScale(1.5f, 1.5f);*/

    this->texture_background.loadFromFile("../assets/cars/stats_b.png");
    this->sprite_background.setTexture(texture_background);
    this->sprite_background.setPosition(0, 0);
    this->sprite_background.setScale(1.3f, 1.39f);

    //this->sprite_gif;
    //this->sprite_gif.setPosition(100, 100);

    this->texture.loadFromFile("../assets/cars/play_button-removebg-preview.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(80, 50);
    this->sprite.setScale(1.3f, 1.3f);

    this->texture_return.loadFromFile("../assets/cars/return_button-removebg-preview-2.png");
    this->sprite_return.setTexture(texture_return);
    this->sprite_return.setPosition(1100, 50);
    this->sprite_return.setScale(1.3f, 1.3f);

    /*this->v1.loadFromFile("../assets/cars/vehicle1-removebg-preview-2.png");
    this->sprite1.setTexture(v1);
    this->sprite1.setPosition(900, 365);
    this->sprite1.setScale(1.5f, 1.5f);*/

    submenu = newSubmenu;
}

bool StatsMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + textWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + textHeight;
}

bool StatsMenu::isSpriteClicked(sf::Sprite &sprite) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = sprite.getPosition();
    float imageWidth = sprite.getLocalBounds().width;
    float imageHeight = sprite.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + imageWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + imageHeight;
}
