#include "settings.h"

Settings::Settings() {
    this->windowPointer = nullptr;
    this->scene = 0;
    this->focus = true;
    this->vehicleId = 5;
    this->init = true;
}

/**
 * Functions sets window pointer.
 * @param newWindowPointer Pointer to window
 */
void Settings::setWindowPointer(sf::RenderWindow *newWindowPointer) {
    windowPointer = newWindowPointer;
}

/**
 * @return Pointer to the window.
 */
sf::RenderWindow *Settings::getWindowPointer() const {
    return windowPointer;
}

/**
 * @return Pointer to scene integer
 */
int *Settings::getScenePointer() {
    return &scene;
}

/**
 * @return Pointer to focus boolean
 */
bool *Settings::getFocusPointer() {
    return &focus;
}

/**
 * @return Current player's vehicle id
 */
int Settings::getVehicleId() const {
    return vehicleId;
}

/**
 * Function sets vehicle id chosen by user.
 * @param newVehicleId Vehicle id from range 0-7
 */
void Settings::setVehicleId(int newVehicleId) {
    vehicleId = newVehicleId;
}

/**
 * @return Object of class PlayerData containing information about chosen vehicle
 * @see PlayerData
 */
PlayerData Settings::getPlayerData() {
    return playersData.players[vehicleId];
}

/**
 * Function sets init parameter to given value.
 * If init value is true all objects will be reset when new game starts.
 * @param newInit Init boolean
 */
void Settings::setInit(int newInit) {
    init = newInit;
}

/**
 * @return Init boolean
 */
int Settings::getInit() {
    return init;
}

/**
 * @return Pointer to object of class Scores
 * @see Scores
 */
Scores *Settings::getScoresPointer() {
    return &scores;
}
