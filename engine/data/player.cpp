#include "player.h"

PlayerData::PlayerData(int initSpeed, int maxSpeed, int initFuel, int maxFuel, std::string texture) {
    this->initSpeed = initSpeed;
    this->maxSpeed = maxSpeed;
    this->initFuel = initFuel;
    this->maxFuel = maxFuel;
    this->texture = texture;
}

int PlayerData::getInitSpeed() {
    return initSpeed;
}

int PlayerData::getMaxSpeed() {
    return maxSpeed;
}

int PlayerData::getInitFuel() {
    return initFuel;
}

int PlayerData::getMaxFuel() {
    return maxFuel;
}

std::string PlayerData::getTexture() {
    return texture;
}

PlayersData::PlayersData() {
    players[0] = PlayerData(20, 80, 60, 60, "jakis.png");
    players[1] = PlayerData(20, 100, 60, 60, "jakis.png");
    players[2] = PlayerData(20, 60, 60, 60, "carrera.png");
    players[3] = PlayerData(20, 80, 30, 60, "carrera.png");
    players[4] = PlayerData(10, 50, 120, 120, "ferrari.png");
    players[5] = PlayerData(40, 120, 50, 50, "ferrari.png");
    players[6] = PlayerData(30, 90, 50, 50, "lambo.png");
    players[7] = PlayerData(30, 90, 50, 70, "lambo.png");
    std::cout << players[7].getMaxFuel();
}