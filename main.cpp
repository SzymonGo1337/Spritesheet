#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML-CLion");

    sf::Texture txt;
    txt.loadFromFile("spritesheet.jpg");

    sf::IntRect rectSourceSprite(0, 0, 32, 32);

    sf::RectangleShape sprite;
    sprite.setSize(sf::Vector2f(32.0f, 32.0f));
    sprite.setTextureRect(rectSourceSprite);
    sprite.setTexture(&txt);
    sprite.setPosition(0.0f, 0.0f);

    sf::Clock clock;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        if(clock.getElapsedTime().asSeconds() > 0.3f) {
            if(rectSourceSprite.left == 96)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 32;

            sprite.setTextureRect(rectSourceSprite);
            clock.restart();
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }

    return 0;
}
