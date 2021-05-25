#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

//@formatter:off
class PlayerData {
private:
    int initSpeed;
    int maxSpeed;
    int initFuel;
    int maxFuel;
    std::string texture;

public:
    PlayerData() = default;
    PlayerData(int, int, int, int, std::string);
    int getInitSpeed();
    int getMaxSpeed();
    int getInitFuel();
    int getMaxFuel();
    std::string getTexture();
};

class PlayersData {
public:
    PlayerData players[8];
    PlayersData();
};

#endif //PLAYER_DATA_H
