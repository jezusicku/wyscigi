#ifndef SETTINGS_H
#define SETTINGS_H

//@formatter:off
class Settings {
private:
    int windowWidth;
    int windowHeight;
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;

public:
    Settings();
    void setWindowWidth(int);
    int getWindowWidth() const;
    void setWindowHeight(int);
    int getWindowHeight() const;
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
};

#endif //SETTINGS_H
