#include "map.h"

Map::Map() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->score = nullptr;
    this->fuel = nullptr;
    this->counter = 0;
    this->point = 0;

    lines[0] = -rand() % 4096;
    lines[1] = -rand() % 4096;
    lines[2] = -rand() % 4096;
    lines[3] = -rand() % 4096;
    lines[4] = -rand() % 4096;

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

    trees.display();
    fuels.display();
    objects.display();
}

void Map::update(sf::Sprite *playerSprite) {
    float change = float(*speed) / 10;

    point += change * change;
    if (point > 800) {
        point = 0;
        *score += 1;
    }

    for (int i = 0; i < 5; i++) {
        lines[i] += change;
        if (lines[i] > 0) {
            int min = 0, max = -2147000000;
            for (float line : lines) {
                if(line < min) min = line;
                if(line > max) max = line;
            }

            if (abs(min - max) < 1000) {
                lines[i] = float(-800 - (rand() % 800));
                continue;
            }

            if (fuels.needCreate()) {
                fuels.create(i);
                *score += 10;
                lines[i] = float(-800 - (rand() % 800));
            } else {
                objects.generateObject(i);
                lines[i] = float(-1600 - (rand() % 1600));
            }
        }
    }

    trees.update(change);

    if (fuels.isCollectable(playerSprite)) {
        *fuel += 50;
        fuels.collect();
    }
    fuels.update(change);

    objects.update(change);

    counter += change;
    if (counter >= 512) counter -= 512;
}

void Map::init(Settings *newSettings, int *speedPointer, int *scorePointer, int *fuelPointer) {
    settings = newSettings;
    window = newSettings->getWindowPointer();
    speed = speedPointer;
    score = scorePointer;
    fuel = fuelPointer;
    objects.init(settings, speed);
    trees.init(settings);
    fuels.init(settings);
}

void Map::clear() {
    objects.clear();
    trees.clear();
    fuels.clear();
    lines[0] = -rand() % 4096;
    lines[1] = -rand() % 4096;
    lines[2] = -rand() % 4096;
    lines[3] = -rand() % 4096;
    lines[4] = -rand() % 4096;
}

bool Map::collide(sf::Sprite *playerSprite) {
    return objects.collide(playerSprite);
}
