//
// Created by micha on 15.06.2020.
//

#include<SFML/Graphics.hpp>
#include <iostream>
#include "SpaceShip.h"
#include "Targets.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,1000),"SpaceShooter");
    window.setMouseCursorVisible(false);
    float framerate = 60;
    float elapsed,frame_timer;

    frame_timer = 0.f;
    elapsed =0.f;

    std::vector<Entity*>all_entities;

    SpaceShip ship;
    std::vector<Targets> targets;
    ship.init(window,targets);
    all_entities.emplace_back(&ship);
    sf::Clock timer;

    sf::RectangleShape back;
    back.setSize({(float)window.getSize().x,(float)window.getSize().y});
    sf::Texture backgr;

    targets.emplace_back(Targets(window,{500.0f,500.0f},{0.f,1.f},500.5f));

    backgr.loadFromFile("data/back.jpg");
    back.setTexture(&backgr);
    while (window.isOpen())
    {
        elapsed = timer.restart().asSeconds();

        sf::Event e;
        while (window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                window.close();
        }
        frame_timer+=elapsed;
        if(frame_timer>1.f/framerate)
        {
            window.clear();
            window.draw(back);
            for(auto& t:all_entities)
            {
                t->input();
                for(auto& h:targets)
                {
                    h.update(elapsed);
                    h.render(window);
                }
                t->update(frame_timer);
                t->render(window);
            }
            frame_timer=0.f;
            window.display();
        }

    }



}
