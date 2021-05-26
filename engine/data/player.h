#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

//@formatter:off
class PlayerData {
private:
    int initSpeed;
    int maxSpeed;
    int initFuel;
    int maxFuel;
    int coordinateY;
    int coordinateX;
    float rotationFactor;
    std::string texture;

public:
    PlayerData() = default;
    PlayerData(int, int, int, int, int, int, float, std::string);
    int getInitSpeed();
    int getMaxSpeed();
    int getInitFuel();
    int getMaxFuel();
    int getCoordinateY();
    std::string getTexture();
    int getCoordinateX();
    float getRotationFactor();
};

class PlayersData {
public:
    PlayerData players[8];
    PlayersData();
};

#endif //PLAYER_DATA_H
