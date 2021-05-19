#include "main.h"

int main() {

    Settings settings;

    sf::VideoMode videoMode(1280, 960);
    std::string title = "Racer";
    sf::RenderWindow window(videoMode, title);
    window.setFramerateLimit(60);
    settings.setWindowPointer(&window);

    Menu menu(&settings);
    Engine engine(&settings);

    sf::Event event{};
    int *scene = settings.getScenePointer();
    bool *focus = settings.getFocusPointer();

    *scene = 1; // loading game immediately (remove line to load menu)

    while (window.isOpen() && *scene >= 0) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::LostFocus) {
                *focus = false;
            } else if (event.type == sf::Event::GainedFocus) {
                *focus = true;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (*scene == 0) menu.update();
                }
            }
        }

        window.clear();

        if (*scene == 0) {
            menu.display();
        } else if (*scene == 1) {
            engine.update();
            engine.display();
        }

        window.display();
    }
}
