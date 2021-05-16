#include "main_menu.h"

MainMenu::MainMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    newGameText.setFont(font);
    newGameText.setString("New Game");
    newGameText.setCharacterSize(32);
    newGameText.setFillColor(sf::Color::Green);
    newGameText.setStyle(sf::Text::Bold);
    newGameText.setPosition(50, 50);

    creditsText.setFont(font);
    creditsText.setString("Credits");
    creditsText.setCharacterSize(32);
    creditsText.setFillColor(sf::Color::Green);
    creditsText.setStyle(sf::Text::Bold);
    creditsText.setPosition(50, 150);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(32);
    exitText.setFillColor(sf::Color::Green);
    exitText.setStyle(sf::Text::Bold);
    exitText.setPosition(50, 250);
}

void MainMenu::display() {
    window->draw(newGameText);
    window->draw(creditsText);
    window->draw(exitText);
}

void MainMenu::update() {
    if (isClicked(newGameText)) {
        *submenu = 1;
    } else if (isClicked(exitText)) {
        *scene = -1;
    } else if (isClicked(creditsText)) {
        *submenu = 2;
    }
}

void MainMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();
    submenu = newSubmenu;
}

bool MainMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + textWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + textHeight;
}
