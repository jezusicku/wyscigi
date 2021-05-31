#include "map.h"

Map::Map() {
    this->settings = nullptr;
    this->window = nullptr;
    this->speed = nullptr;
    this->score = nullptr;
    this->fuel = nullptr;
    this->counter = 0;
    this->scoreCounter = 0;
    this->fuelCounter = 0;

    lanes[0] = -rand() % 4096;
    lanes[1] = -rand() % 4096;
    lanes[2] = -rand() % 4096;
    lanes[3] = -rand() % 4096;
    lanes[4] = -rand() % 4096;

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

/**
 * Function displays grass and trees on the roadside, displays road and all objects on it.
 */
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

/**
 * Function moves all visible objects based on the current speed of player's vehicle. Function also checks for
 * collisions with fuel canister and fills player's vehicle fuel.
 * @param vehicleSprite Pointer to player's vehicle sprite
 */
void Map::update(sf::Sprite *vehicleSprite) {
    float change = float(*speed) / 10;

    scoreCounter += change * change;
    if (scoreCounter > 800) {
        scoreCounter = 0;
        *score += 1;
    }

    fuelCounter++;
    if (fuelCounter > 250) {
        fuelCounter = 0;
        *fuel -= 1;
    }

    for (int i = 0; i < 5; i++) {
        lanes[i] += change;
        if (lanes[i] > 0) {
            int min = 0, max = -2147000000;
            for (float line : lanes) {
                if (line < min) min = line;
                if (line > max) max = line;
            }

            if (abs(min - max) < 1400) {
                lanes[i] = float(-1600 - (rand() % 600));
                continue;
            }

            if (fuels.needCreate()) {
                fuels.create(i);
                lanes[i] = float(-1200 - (rand() % 600));
            } else {
                objects.generateObject(i);
                lanes[i] = float(-1600 - (rand() % 1500));
            }
        }
    }

    trees.update(change);

    if (fuels.isCollectable(vehicleSprite)) {
        *score += 100;
        fuels.collect();
    }
    fuels.update(change);

    objects.update(change);

    counter += change;
    if (counter >= 512) counter -= 512;
}

/**
 * Function initializes object.
 * @param newSettings Pointer to object of class Settings
 * @param speedPointer Pointer to player speed
 * @param scorePointer Pointer to player score
 * @param fuelPointer Pointer to current fuel level
 * @see Settings
 */
void Map::init(Settings *newSettings, int *speedPointer, int *scorePointer, int *fuelPointer) {
    settings = newSettings;
    window = newSettings->getWindowPointer();
    speed = speedPointer;
    score = scorePointer;
    fuel = fuelPointer;
    objects.init(settings, speed);
    trees.init(settings);
    fuels.init(settings, fuel);
}

/**
 * Function removes all objects from the screen and sets the parameters of all visible objects to default.
 */
void Map::clear() {
    objects.clear();
    trees.clear();
    fuels.clear();
    lanes[0] = -rand() % 4096;
    lanes[1] = -rand() % 4096;
    lanes[2] = -rand() % 4096;
    lanes[3] = -rand() % 4096;
    lanes[4] = -rand() % 4096;
}

/**
 * Function checks if player's vehicle collides with any other car on the screen.
 * @param playerSprite Pointer to player sprite
 * @return True if player's vehicle collides with other car.
 */
bool Map::collide(sf::Sprite *playerSprite) {
    return objects.collide(playerSprite);
}
