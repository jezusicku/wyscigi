#ifndef SETTINGS_H
#define SETTINGS_H

#include "data/player.h"

//@formatter:off
class Settings {
private:
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;
    int playerId;
    bool init;
    PlayersData playersData;

public:
    Settings();
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
    int getPlayerId() const;
    void setPlayerId(int);
    PlayerData getPlayerData();
    void setInit(int);
    int getInit();
};

#endif //SETTINGS_H
