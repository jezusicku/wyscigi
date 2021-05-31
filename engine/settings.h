#ifndef SETTINGS_H
#define SETTINGS_H
//@formatter:off

#include "data/player.h"

/**
 * Object of this class allows communication between menu and game engine and stores basic information (necessary to
 * start the game) about player's vehicle. It also stores information about objects needed during the gameplay (Scores,
 * sf::RenderWindow, pause, vehicleId).
 * @see Scores
 */
class Settings {
private:
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;
    int vehicleId;
    bool init;
    PlayersData playersData;
    Scores scores;

public:
    Settings();
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
    int getVehicleId() const;
    void setVehicleId(int);
    PlayerData getPlayerData();
    void setInit(int);
    int getInit();
    Scores *getScoresPointer();
};

#endif //SETTINGS_H
