#include "new_game_menu.h"

NewGameMenu::NewGameMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    newGameText.setFont(font);
    newGameText.setString("Start New Game");
    newGameText.setCharacterSize(32);
    newGameText.setFillColor(sf::Color::Green);
    newGameText.setStyle(sf::Text::Bold);
    newGameText.setPosition(50, 50);

    returnText.setFont(font);
    returnText.setString("Return");
    returnText.setCharacterSize(32);
    returnText.setFillColor(sf::Color::Green);
    returnText.setStyle(sf::Text::Bold);
    returnText.setPosition(50, 150);
}

void NewGameMenu::display() {
    window->draw(newGameText);
    window->draw(returnText);
}

void NewGameMenu::update() {
    if (isClicked(newGameText)) {
        *scene = 1;
    } else if (isClicked(returnText)) {
        *submenu = 0;
    }
}

void NewGameMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();
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
