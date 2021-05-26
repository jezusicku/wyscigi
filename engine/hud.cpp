#include "hud.h"

Hud::Hud() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->score = nullptr;

    if (!font.loadFromFile("../assets/fonts/boxy_bold.ttf")) exit(1);

    speedText.setFont(font);
    speedText.setCharacterSize(40);
    speedText.setLetterSpacing(2.f);
    speedText.setPosition(16.f, 16.f);

    scoreText.setFont(font);
    scoreText.setCharacterSize((40));
    scoreText.setLetterSpacing(2.f);
    scoreText.setPosition(16.f, 100.f);
}

void Hud::display() {
    window->draw(speedText);
    window->draw(scoreText);
}

void Hud::update() {
    char speedChars[10];
    sprintf(speedChars, "%imph", *speed);
    speedText.setString(speedChars);
    char scoreChars[20];
    sprintf(scoreChars, "Score:\n%i", *score);
    scoreText.setString(scoreChars);
}

void Hud::init(Settings *newSettings, int *speedPointer, int *scorePointer) {
    settings = newSettings;
    window = this->settings->getWindowPointer();
    speed = speedPointer;
    score = scorePointer;
}
