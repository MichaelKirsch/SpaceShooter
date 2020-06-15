#pragma once
#include "Entity.h"

class Targets : public Entity{
public:

    Targets(sf::RenderWindow &window,sf::Vector2f start_pos, sf::Vector2f direction, float speed);

    virtual void update(float elapsed);


    virtual void input();

    virtual void render(sf::RenderWindow &window);
    bool alife=true;
    sf::RectangleShape body;
private:
    sf::RenderWindow* m_window;
    sf::Vector2f direction;
    float speed;
    sf::Texture text;
};


