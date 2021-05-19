#ifndef SETTINGS_H
#define SETTINGS_H

//@formatter:off
class Settings {
private:
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;

public:
    Settings();
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
};

#endif //SETTINGS_H
