#include "hud.h"

Hud::Hud() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;

    if (!font.loadFromFile("../assets/fonts/boxy_bold.ttf")) exit(1);

    speedText.setFont(font);
    speedText.setCharacterSize(48);
    speedText.setLetterSpacing(2.f);
    speedText.setPosition(16.f, 16.f);
}

void Hud::display() {
    window->draw(speedText);
}

void Hud::update() {
    char speedChars[10];
    sprintf(speedChars, "%i", *speed);
    speedText.setString(speedChars);
}

void Hud::init(Settings *newSettings, int *speedPointer) {
    settings = newSettings;
    window = this->settings->getWindowPointer();
    speed = speedPointer;
}
