#include "end_game.h"

EndGame::EndGame() {
    this->settings = nullptr;
    this->window = nullptr;
    this->scores = nullptr;
    this->score = nullptr;
    this->duration = 0;
    this->step = -1;
    this->place = 0;

    background.setPosition(.0f, .0f);
    background.setSize(sf::Vector2f(1280.f, 0.f));
    background.setFillColor(sf::Color(0, 0, 0, 192));

    if (!font.loadFromFile("../assets/fonts/boxy_bold.ttf")) exit(1);

    scorePlainText.setFont(font);
    scorePlainText.setCharacterSize(48);
    scorePlainText.setLetterSpacing(2.f);
    scorePlainText.setString("SCORE");
    scorePlainText.setOrigin(scorePlainText.getLocalBounds().width / 2, scorePlainText.getLocalBounds().height / 2);

    scoreText.setFont(font);
    scoreText.setCharacterSize(64);
    scoreText.setLetterSpacing(2.f);
    scoreText.setString("SCORE");
    scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);

    returnText.setFont(font);
    returnText.setCharacterSize(48);
    returnText.setLetterSpacing(2.f);
    returnText.setString("RETURN");
    returnText.setOrigin(returnText.getLocalBounds().width / 2, returnText.getLocalBounds().height / 2);

}

void EndGame::display() {
    window->draw(background);
    window->draw(scorePlainText);
    window->draw(scoreText);
    window->draw(returnText);
}

void EndGame::update() {
    duration += 20;
    if (step == -1) {
        place = scores->setScore(settings->getPlayerId(), *score);
        step = 0;
    } else if (step == 0) {
        background.setSize(sf::Vector2f(1280.f, float(duration)));
    } else if (step == 1) {
        scorePlainText.move(.0f, -14.f);
    } else if (step == 2) {
        char scoreChars[10];
        sprintf(scoreChars, "%i", *score);
        scoreText.setString(scoreChars);
        scoreText.setOrigin(scoreText.getLocalBounds().width / 2, scoreText.getLocalBounds().height / 2);
        scoreText.setPosition(640.f, scoreText.getPosition().y);
        scoreText.move(.0f, -11.f);
    } else if (step == 3) {
        returnText.move(.0f, -6.f);
    }

    if (duration > 1000) {
        if (step < 4) step++;
        duration = 0;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && *settings->getFocusPointer()) {
        if (isClicked(returnText)) {
            settings->setInit(true);
            *settings->getScenePointer() = 0;
        }
    }
}

void EndGame::init(Settings *newSettings, int *scorePointer) {
    settings = newSettings;
    window = settings->getWindowPointer();
    scores = settings->getScoresPointer();
    score = scorePointer;
    duration = 0;
    step = -1;

    scorePlainText.setPosition(640.f, 1000.f);
    scoreText.setPosition(640.f, 1000.f);
    returnText.setPosition(640.f, 1000.f);
}

bool EndGame::isClicked(sf::Text &text) {
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
