#include "pause_menu.h"

PauseMenu::PauseMenu() {
    this->settings = nullptr;
    this->window = nullptr;
    this->pause = nullptr;

    background.setSize(sf::Vector2f(1280.f, 960.f));
    background.setFillColor(sf::Color(0, 0, 0, 192));
    background.setPosition(0.f, 0.f);

    if (!font.loadFromFile("../assets/fonts/boxy_bold.ttf")) exit(1);

    continueText.setFont(font);
    continueText.setCharacterSize(48);
    continueText.setLetterSpacing(2.f);
    continueText.setString("CONTINUE");
    continueText.setOrigin(continueText.getLocalBounds().width / 2, continueText.getLocalBounds().height / 2);
    continueText.setPosition(640.f, 480.f);
}

/**
 * Function displays pause menu on the screen.
 */
void PauseMenu::display() {
    window->draw(background);
    window->draw(continueText);
}

/**
 * Function checks if user has clicked continue button. If button is clicked then pause is turned off.
 */
void PauseMenu::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && *settings->getFocusPointer())
        if (isClicked(continueText))
            *pause = false;
}

/**
 * Function initializes object.
 * @param newSettings Pointer to object of class Settings
 * @param pausePointer Pointer to pause boolean
 * @see Settings
 */
void PauseMenu::init(Settings *newSettings, bool *pausePointer) {
    settings = newSettings;
    window = newSettings->getWindowPointer();
    pause = pausePointer;
}

/**
 * @param text Pointer to object of class sf::Text
 * @return True if given text has been clicked
 */
bool PauseMenu::isClicked(sf::Text &text) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    sf::Vector2f textPosition = text.getPosition();
    sf::Vector2f textOrigin = text.getOrigin();
    float textWidth = text.getLocalBounds().width;
    float textHeight = text.getLocalBounds().height;
    return mousePosition.x >= textPosition.x - textOrigin.x &&
           mousePosition.x <= textPosition.x - textOrigin.x + textWidth &&
           mousePosition.y >= textPosition.y - textOrigin.y &&
           mousePosition.y <= textPosition.y - textOrigin.y + textHeight;
}
