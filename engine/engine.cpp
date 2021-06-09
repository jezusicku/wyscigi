#include "engine.h"

Engine::Engine(Settings *settings) {
    this->settings = settings;
    this->window = settings->getWindowPointer();
    this->scene = settings->getScenePointer();
    this->speed = 20;
    this->counter = 0;
    this->pause = false;
    this->end = false;
    this->score = 0;
    this->fuel = 100;
    this->player.init(settings, &speed);
    this->map.init(settings, &speed, &score, &fuel);
    this->hud.init(settings, &speed, &score, &fuel);
    this->pauseMenu.init(settings, &pause);
    this->endGame.init(settings, &score);
}

/**
 * Function display player's vehicle, map and hud.
 * If pause is turned on then displays pause menu.
 * If game ended then displays end game screen.
 */
void Engine::display() {
    map.display();
    player.display();
    hud.display();
    if (end) endGame.display();
    else if (pause) pauseMenu.display();
}

/**
 * If game is not initialized then function initializes the game using the init function.
 * If game has been ended then the end game screen is updated.
 * If pause is turned on then the pause menu is updated.
 * Otherwise player's vehicle and map are updated.
 */
void Engine::update() {
    if (settings->getInit() == true) {
        init();
        return;
    }

    if (!*settings->getFocusPointer()) pause = true;

    if (end) {
        endGame.update();
        return;
    }
/**
 * Implementation of vehicle's acceleration and arrow key up boost. When we put key acceleration is 3 times faster.
 */
    if (!pause) {
        map.update(player.getSpritePointer());
        player.update();
        float ac = settings->getPlayerData().getAcceleration();
        int limit = 200 * ac;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            counter++;
            counter++;
        }
        if ((++counter == limit || counter == limit +1 || counter == limit +2) and speed < settings->getPlayerData().getMaxSpeed()) {
            counter = 0;
            speed++;
        }
        hud.update();
        if (map.collide(player.getSpritePointer()) || fuel <= 0)
            end = true;
    } else pauseMenu.update();
}

/**
 * Function initializes player's vehicle speed, player score and fuel level. All current objects are removed from the
 * map and pause menu and end game screen are disabled.
 */
void Engine::init() {
    speed = settings->getPlayerData().getInitSpeed();
    counter = 0;
    pause = false;
    end = false;
    score = 0;
    fuel = settings->getPlayerData().getInitFuel();
    player.init(settings, &speed);
    map.clear();
    endGame.init(settings, &score);
    settings->setInit(false);
}

/**
 * Function swaps visibility of pause menu.
 */
void Engine::swapPause() {
    pause = !pause;
}