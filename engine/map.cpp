#include "map.h"

Map::Map() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->counter = 0;

    if (!grassTexture.loadFromFile("../assets/map/grass.png")) exit(1);
    grassTexture.setRepeated(true);
    grassShape.setTextureRect(sf::IntRect(0.f, 0.f, 1280.f, 1500.f));
    grassShape.setTexture(&grassTexture);
    grassShape.setPosition(0.f, -512.f);
    grassShape.setSize(sf::Vector2f(1280.f, 1500.f));

    if (!asphaltTexture.loadFromFile("../assets/map/asphalt.png")) exit(1);
    asphaltTexture.setRepeated(true);
    asphaltShape.setTextureRect(sf::IntRect(0.f, 0.f, 640.f, 1500.f));
    asphaltShape.setTexture(&asphaltTexture);
    asphaltShape.setPosition(320.f, -512.f);
    asphaltShape.setSize(sf::Vector2f(640.f, 1500.f));

    leftLineShape.setFillColor(sf::Color::White);
    leftLineShape.setPosition(315.f, 0.f);
    leftLineShape.setSize(sf::Vector2f(10.f, 960.f));

    rightLineShape.setFillColor(sf::Color::White);
    rightLineShape.setPosition(955.f, 0.f);
    rightLineShape.setSize(sf::Vector2f(10.f, 960.f));

    for (auto &lineShape : lineShapes) {
        lineShape.setFillColor(sf::Color::White);
        lineShape.setSize(sf::Vector2f(10.f, 100.f));
    }
}

void Map::display() {

    grassShape.setPosition(0.f, float(counter) - 512.f);
    window->draw(grassShape);

    asphaltShape.setPosition(320.f, float(counter) - 512.f);
    window->draw(asphaltShape);

    window->draw(leftLineShape);
    window->draw(rightLineShape);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            lineShapes[i + 8 * j].setPosition(443.f + float(128 * j), float(counter + i * 256) - 512);
            window->draw(lineShapes[i + 8 * j]);
        }
    }

    objects.display();
}

void Map::update() {
    objects.update();
    counter++;
    if (counter == 128 || counter == 256 || counter == 384 || counter == 512) objects.addRandomObject();
    if (counter == 512) {
        counter = 0;
    }
}

void Map::init(Settings *newSettings, float *speedPointer) {
    this->settings = newSettings;
    this->window = this->settings->getWindowPointer();
    this->speed = speedPointer;
    this->objects.init(settings);
}
