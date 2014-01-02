/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#ifndef PARTICLE_HPP_INCLUDED
#define PARTICLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Particle{
private:
    sf::Color Color;
    sf::Vector2f Position;
    float AlphaSub;
    unsigned short int Tick;
public:
    Particle(sf::Vector2f,sf::Color);
    ~Particle();
    sf::Color GetColor ( void );
    sf::Vector2f GetPosition ( void );
    bool Poll ( void );
};

#endif // PARTICLE_HPP_INCLUDED
