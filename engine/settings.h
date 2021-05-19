#ifndef SETTINGS_H
#define SETTINGS_H

//@formatter:off
class Settings {
private:
    sf::RenderWindow* windowPointer;
    int scene;
    bool focus;

public:
    int temp; // TODO rename and make private
    Settings();
    void setWindowPointer(sf::RenderWindow*);
    sf::RenderWindow* getWindowPointer() const;
    int* getScenePointer();
    bool* getFocusPointer();
};

#endif //SETTINGS_H
