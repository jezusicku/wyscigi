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
    this->hud.init(settings, &speed);
    this->pauseMenu.init(settings, &pause);
    this->endGame.init(settings, &score);
}

void Engine::display() {
    map.display();
    player.display();
    hud.display();
    if (end) endGame.display();
    else if (pause) pauseMenu.display();
}

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

    if (!pause) {
        map.update(player.getSpritePointer());
        player.update();
        if (++counter == 200 and speed < 80) {
            counter = 0;
            speed++;
        }
        hud.update();
        if (map.collide(player.getSpritePointer())) {
            end = true;
        }
    } else pauseMenu.update();
}

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
