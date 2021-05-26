#include "hud.h"

Hud::Hud() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->score = nullptr;
    this->fuel = nullptr;
    this->fuel = new int;
    *fuel = 30;

    if (!font.loadFromFile("../assets/fonts/boxy_bold.ttf")) exit(1);

    speedText.setFont(font);
    speedText.setCharacterSize(40);
    speedText.setLetterSpacing(2.f);
    speedText.setPosition(16.f, 16.f);

    scoreText.setFont(font);
    scoreText.setCharacterSize((40));
    scoreText.setLetterSpacing(2.f);
    scoreText.setPosition(16.f, 100.f);

    fuelShape.setSize(sf::Vector2f(295.f, 60.f));
    fuelShape.setPosition(975.f, 10.f);
    fuelShape.setFillColor(sf::Color::Transparent);
    fuelShape.setOutlineThickness(5.f);
    fuelShape.setOutlineColor(sf::Color::Red);

    currentFuelShape.setSize(sf::Vector2f(295.f, 60.f));
    currentFuelShape.setPosition(975.f, 10.f);
    currentFuelShape.setFillColor(sf::Color::Red);
}

void Hud::display() {
    window->draw(speedText);
    window->draw(scoreText);
    window->draw(fuelShape);
    window->draw(currentFuelShape);
}

void Hud::update() {
    char speedChars[10];
    sprintf(speedChars, "%imph", *speed);
    speedText.setString(speedChars);
    char scoreChars[20];
    sprintf(scoreChars, "Score:\n%i", *score);
    scoreText.setString(scoreChars);
    float currentFuelShapeX = 295.f * float(*fuel) / float(settings->getPlayerData().getMaxFuel());
    currentFuelShape.setSize(sf::Vector2f(currentFuelShapeX, 60.f));

}

void Hud::init(Settings *newSettings, int *speedPointer, int *scorePointer) {
    settings = newSettings;
    window = this->settings->getWindowPointer();
    speed = speedPointer;
    score = scorePointer;
}
