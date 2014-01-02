/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#ifndef FIREWORK_HPP_INCLUDED
#define FIREWORK_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Particle.hpp"

class Firework{
private:
    sf::Color Color;
    sf::Vector2f Velocity;
    sf::Vector2f Position;
    unsigned short int Tick;
    std::vector<Particle*> *ParticleVector;
public:
    Firework(std::vector<Particle*>*);
    ~Firework();
    sf::Color GetColor ( void );
    sf::Vector2f GetPosition ( void );
    bool Poll ( void );
};

#endif // FIREWORK_HPP_INCLUDED
