#include "credits_menu.h"

CreditsMenu::CreditsMenu() {
    settings = nullptr;
    window = nullptr;
    scene = nullptr;
    submenu = nullptr;

    if (!font.loadFromFile("../assets/fonts/Girassol-Regular.ttf")) exit(1);

    returnText.setFont(font);
    returnText.setString("Return");
    returnText.setCharacterSize(32);
    returnText.setFillColor(sf::Color::Green);
    returnText.setStyle(sf::Text::Bold);
    returnText.setPosition(50, 50);
}

void CreditsMenu::display() {
    window->draw(returnText);
}

void CreditsMenu::update() {
    if (isClicked(returnText)) {
        *submenu = 0;
    }
}

void CreditsMenu::init(Settings *newSettings, int *newSubmenu) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scene = settings->getScenePointer();
    submenu = newSubmenu;
}

bool CreditsMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x && mousePosition.x <= textPosition.x + textWidth &&
           mousePosition.y >= textPosition.y && mousePosition.y <= textPosition.y + textHeight;
}
