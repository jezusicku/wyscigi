#include "map.h"

Map::Map() {
    this->settings = nullptr;
    this->window = nullptr;
}


void Map::display() {
    sf::RectangleShape grass(sf::Vector2f(1600.f, 1200.f));
    grass.setPosition(0.f, 0.f);
    grass.setFillColor(sf::Color(76, 209, 55));
    window->draw(grass);

    sf::RectangleShape road(sf::Vector2f(800.f, 1200.f));
    road.setPosition(400.f, 0.f);
    road.setFillColor(sf::Color(44, 44, 44));
    window->draw(road);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            sf::RectangleShape line(sf::Vector2f(10.f, 50.f));
            line.setPosition(555.f + float(j) * 160, float(lines) + 100 * float(i) - 100);
            line.setFillColor(sf::Color::White);
            window->draw(line);
        }
    }
    lines += 3;
    if (lines > 100) lines = 0;
}

void Map::update() {

}

void Map::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = this->settings->getWindowPointer();
}
