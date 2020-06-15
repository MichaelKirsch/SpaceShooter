//
// Created by micha on 15.06.2020.
//

#include "Targets.h"


Targets::Targets(sf::RenderWindow &window,sf::Vector2f start_pos, sf::Vector2f dire, float spd) {
    text.loadFromFile("data/poop.png");
    body.setTexture(&text);
    body.setPosition(start_pos);
    m_window = &window;
    auto size = window.getSize().x*0.08f;
    body.setSize({size,size});
    speed = spd;
    direction = dire;
}

void Targets::render(sf::RenderWindow &window) {
    window.draw(body);
}

void Targets::update(float elapsed) {
    auto pos = body.getPosition();
    body.setPosition(pos+direction*elapsed*700.f);
}

void Targets::input() {
    Entity::input();
}
