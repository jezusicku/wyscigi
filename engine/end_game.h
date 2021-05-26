#ifndef TRANSITION_H
#define TRANSITION_H

//@formatter:off
class EndGame {
private:
    Settings *settings;
    sf::RenderWindow *window;
    int *score;
    int duration;
    int step;
    int place;

    sf::RectangleShape background;
    sf::Font font;
    sf::Text scorePlainText;
    sf::Text scoreText;
    sf::Text returnText;

    Scores scores;

public:
    EndGame();
    void display();
    void update();
    void init(Settings *, int *);

private:
    bool isClicked(sf::Text &);
};

#endif //TRANSITION_H
