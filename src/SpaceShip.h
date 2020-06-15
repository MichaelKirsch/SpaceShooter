#pragma once

#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <array>
#include <iostream>
#include "Targets.h"

class Bullet : public Entity
{
public:
    void update(float elapsed) override;

    void init(sf::RenderWindow& window);

    void input() override;

    void render(sf::RenderWindow &window) override;

    bool alife = false;
    void respawn(sf::Vector2f position, float life,float offset);
    float lifetime = 0.5f;
    float speed = 10.f;
    sf::Vector2f direction ={0.f,-1.f};
    sf::RectangleShape body;
};

class SpaceShip : public Entity{
public:
    void update(float elapsed) ;

    void init(sf::RenderWindow& i_window, std::vector<Targets>& targets);

    void input();

    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape body;
    sf::Texture rockettexture;
    sf::RenderWindow* m_window;
    std::array<Bullet,100> bulletpool;
    int firerate = 10;
    float firetimer=0.f;
    std::vector<Targets>* targets;
};


