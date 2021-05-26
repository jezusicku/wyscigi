#include "player.h"

PlayerData::PlayerData(int initSpeed, int maxSpeed, int initFuel, int maxFuel, int coordinateY , int coordinateX, float rotationFactor, std::string texture) {
    this->initSpeed = initSpeed;
    this->maxSpeed = maxSpeed;
    this->initFuel = initFuel;
    this->maxFuel = maxFuel;
    this->coordinateY = coordinateY;
    this->coordinateX = coordinateX;
    this->rotationFactor = rotationFactor;
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

int PlayerData::getCoordinateY(){
    return coordinateY;
}

int PlayerData::getCoordinateX() {
    return coordinateX;
}

float PlayerData::getRotationFactor() {
    return rotationFactor;
}

PlayersData::PlayersData() {
    players[0] = PlayerData(40, 80, 60, 60, 800, 40, 0.8, "../assets/cars/jakis.png");
    players[1] = PlayerData(40, 100, 60, 60, 800, 40, 0.8, "../assets/cars/jakis.png");
    players[2] = PlayerData(40, 60, 60, 60, 700, 40, 1.1, "../assets/cars/carrera.png");
    players[3] = PlayerData(60, 300, 30, 60, 700, 40, 2 , "../assets/cars/bolid.png");
    players[4] = PlayerData(10, 50, 120, 120, 720, 40, 1.5, "../assets/cars/ferrari.png");
    players[5] = PlayerData(100, 500, 50, 50, 800, 40, 2, "../assets/cars/nevada_ze_stara.png");
    players[6] = PlayerData(60, 90, 50, 50, 700, 40, 0.5, "../assets/cars/lambo.png");
    players[7] = PlayerData(60, 90, 50, 70, 700, 40, 0.5, "../assets/cars/lambo.png");
}
