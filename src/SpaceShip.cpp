//
// Created by micha on 15.06.2020.
//

#include "SpaceShip.h"

void SpaceShip::update(float elapsed) {
    for(auto& b:bulletpool)
    {
        b.update(elapsed);
        if(b.alife)
        {
            for(auto& t:*targets)
            {
                //if(t.body.getLocalBounds().intersects(b.body.getLocalBounds()))
                //{
                //    b.alife = false;
                //    t.alife = false;
                //}
            }
        }
    }
    firetimer+=elapsed;
}

void SpaceShip::init(sf::RenderWindow &i_window, std::vector<Targets> &tar) {
    m_window = &i_window;
    auto size_rocket =  m_window->getSize().x*0.1f;
    body.setSize({size_rocket,size_rocket});
    rockettexture.loadFromFile("data/rok2.png");
    body.setTexture(&rockettexture);

    for(auto& b:bulletpool)
        b.init(i_window);
    targets = &tar;
}


void SpaceShip::input() {
    body.setPosition(sf::Mouse::getPosition(*m_window).x,sf::Mouse::getPosition(*m_window).y);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&firetimer>1.f/firerate)
    {
        firetimer=0.f;
        for(auto& b:bulletpool)
        {
            if(!b.alife)
            {
                b.respawn({body.getPosition().x,body.getPosition().y},0.5f,body.getSize().x/2.f);
                break;
            }
        }
    }
}

void SpaceShip::render(sf::RenderWindow &window) {
    for(auto& b:bulletpool)
        b.render(window);
    window.draw(body);
}



void Bullet::update(float elapsed) {
    lifetime-=elapsed;
    if(lifetime<=0.f)
        alife = false;

    auto pos = body.getPosition();

    body.setPosition(pos+direction*elapsed*2000.f);
}

void Bullet::input() {

}

void Bullet::render(sf::RenderWindow &window) {
    if(alife)
        window.draw(body);
}

void Bullet::init(sf::RenderWindow &window) {
    float size =  window.getSize().x*0.02f;
    body.setSize({size,size});
    body.setFillColor({0, (sf::Uint8)(rand()%255), (sf::Uint8)(rand()%255)});
}

void Bullet::respawn(sf::Vector2f position, float life,float offset) {
    body.setPosition(position.x+offset,position.y);
    alife = true;
    lifetime = life;
}
