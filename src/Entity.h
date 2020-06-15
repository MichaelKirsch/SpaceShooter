#pragma once
#include "SFML/Graphics.hpp"

struct Entity {
    virtual void update(float elapsed){};

    virtual void init(){

    };

    virtual void input(){};

    virtual  void render(sf::RenderWindow& window){};
};


