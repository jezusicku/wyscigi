#ifndef SETTINGS_H
#define SETTINGS_H

//@formatter:off
class Settings {
private:
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;
    int player;
    bool init;

public:
    Settings();
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
    void setPlayer(int);
    int getPlayer();
    void setInit(int);
    int getInit();
};

#endif //SETTINGS_H
