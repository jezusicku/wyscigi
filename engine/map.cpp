#include "map.h"

Map::Map() {
    this->settings = nullptr;
    this->window = nullptr;
    this->lines = 0;
    this->counter = 0;
}

void Map::display() {
    sf::RectangleShape grass(sf::Vector2f(1280.f, 960.f));
    grass.setPosition(0.f, 0.f);
    grass.setFillColor(sf::Color(76, 209, 55));
    window->draw(grass);

    sf::RectangleShape road(sf::Vector2f(640.f, 960.f));
    road.setPosition(320.f, 0.f);
    road.setFillColor(sf::Color(44, 44, 44));
    window->draw(road);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 4; j++) {
            sf::RectangleShape line(sf::Vector2f(10.f, 50.f));
            line.setPosition(443.f + float(j) * 128, float(lines) + 150 * float(i) - 256);
            line.setFillColor(sf::Color::White);
            window->draw(line);
        }
    }

    objects.display();
}

void Map::update() {
    objects.update();
    counter++;
    if(counter > 120) {
        objects.addRandomObject();
        objects.addRandomObject();
        counter = 0;
    }
    lines += 3;
    if (lines >= 150) lines -= 150;
}

void Map::init(Settings *newSettings) {
    this->settings = newSettings;
    this->window = this->settings->getWindowPointer();
    this->objects.init(settings);
}
