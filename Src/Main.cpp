/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014

    Controls:
        Left click: Launch a firework
        Escape    : Close application

    Dependencies:
        SFML 2.0
        G++
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Firework.hpp"
#include "Particle.hpp"
#include "Explosion.hpp"

int main ( int argc, char* argv[] )
{
    srand( time(NULL) );
    sf::RenderWindow App(sf::VideoMode(800,600,32),"Fireworks");
    sf::Event AppEvent;

    std::vector<Firework*> Fireworks;
    std::vector<Particle*> Particles;
    std::vector<Explosion*> Explosions;

    sf::RectangleShape RectShape;
    RectShape.setSize(sf::Vector2f(2,2));

    sf::Clock Polltimer;

    while(App.isOpen())
    {
        while(App.pollEvent(AppEvent))
        {
            switch(AppEvent.type)
            {
            case sf::Event::Closed:
                App.close();
                break;
            case sf::Event::KeyPressed:
                switch(AppEvent.key.code)
                {
                case sf::Keyboard::Escape:
                    App.close();
                    break;
                default:
                    break;
                }
                break;
            case sf::Event::MouseButtonPressed:
                switch(AppEvent.mouseButton.button)
                {
                case sf::Mouse::Left:
                    Fireworks.push_back(new Firework(&Particles));
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }

        App.clear(sf::Color(0,0,0));
        RectShape.setSize(sf::Vector2f(1,1));
        for( std::vector<Particle*>::iterator it = Particles.begin(); it != Particles.end(); ++it )
        {
            RectShape.setFillColor((*it)->GetColor());
            RectShape.setPosition((*it)->GetPosition());
            App.draw(RectShape);
        }
        RectShape.setSize(sf::Vector2f(2,2));
        for(std::vector<Explosion*>::iterator it = Explosions.begin(); it != Explosions.end(); ++it )
        {
            RectShape.setFillColor((*it)->GetColor());
            RectShape.setPosition((*it)->GetPosition());
            App.draw(RectShape);
        }
        for( std::vector<Firework*>::iterator it = Fireworks.begin(); it != Fireworks.end(); ++it )
        {
            RectShape.setFillColor((*it)->GetColor());
            RectShape.setPosition((*it)->GetPosition());
            App.draw(RectShape);
        }
        if(Polltimer.getElapsedTime().asMilliseconds() >= 50)
        {
            for( std::vector<Particle*>::iterator it = Particles.begin(); it != Particles.end(); ++it )
            {
                if(!(*it)->Poll())
                {
                    delete *it;
                    Particles.erase(it);
                    it--;
                }
            }
            for( std::vector<Firework*>::iterator it = Fireworks.begin(); it != Fireworks.end(); ++it )
            {
                if(!(*it)->Poll())
                {
                    for(unsigned short int i = 0; i < 50; i++)
                        Explosions.push_back(new Explosion((*it)->GetPosition(),(*it)->GetColor()));
                    delete *it;
                    Fireworks.erase(it);
                    it--;
                }
            }
            for( std::vector<Explosion*>::iterator it = Explosions.begin(); it != Explosions.end(); ++it )
            {
                if(!(*it)->Poll())
                {
                    Particles.push_back(new Particle((*it)->GetPosition(),(*it)->GetColor()));
                    delete *it;
                    Explosions.erase(it);
                    it--;
                }
            }
            Polltimer.restart();
        }
        App.display();
    }
    return EXIT_SUCCESS;
}
