#include "player.h"

PlayerData::PlayerData(int initSpeed, int maxSpeed, int initFuel, int maxFuel, int coordinateY , int coordinateX,
                       float scale, float rotationFactor, float acceleration, std::string texture) {
    this->initSpeed = initSpeed;
    this->maxSpeed = maxSpeed;
    this->initFuel = initFuel;
    this->maxFuel = maxFuel;
    this->coordinateY = coordinateY;
    this->coordinateX = coordinateX;
    this->scale = scale;
    this->rotationFactor = rotationFactor;
    this->acceleration = acceleration;
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

float PlayerData::getScale() {
    return scale;
}

float PlayerData::getRotationFactor() {
    return rotationFactor;
}
float PlayerData::getAcceleration(){
    return acceleration;
}

PlayersData::PlayersData() {
    players[0] = PlayerData(40, 120, 60, 60, 800, 40, .3, 0.8,  1, "../assets/cars/jakis.png");
    players[1] = PlayerData(30, 80, 80, 120, 750, 55, .4, 0.5, 1.5, "../assets/cars/zuk.png");
    players[2] = PlayerData(40, 200, 60, 60, 800, 40, .3, 1.1, 0.8, "../assets/cars/carrera.png");
    players[3] = PlayerData(60, 300, 30, 60, 800, 40, .3, 2 , 0.5, "../assets/cars/bolid.png");
    players[4] = PlayerData(40, 220, 120, 120, 800, 40, .3, 1.5, 0.7, "../assets/cars/ferrari.png");
    players[5] = PlayerData(100, 500, 50, 50, 800, 40, .3, 2, 0.5, "../assets/cars/nevada_ze_stara.png");
    players[6] = PlayerData(35, 90, 80, 120, 750, 55, .4 ,0.5, 1.2, "../assets/cars/wywrotka.png");
    players[7] = PlayerData(60, 280, 50, 70, 800, 40, .3, 0.5, 0.85, "../assets/cars/lambo.png");
}
