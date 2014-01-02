/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#ifndef EXPLOSION_HPP_INCLUDED
#define EXPLOSION_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Explosion{
private:
    sf::Color Color;
    sf::Vector2f Position;
    sf::Vector2f Velocity;
    float AlphaSub;
    unsigned short int Tick;
public:
    Explosion(sf::Vector2f,sf::Color);
    ~Explosion();
    sf::Color GetColor ( void );
    void SetColor ( sf::Color );
    sf::Vector2f GetPosition ( void );
    bool Poll ( void );
};

#endif // EXPLOSION_HPP_INCLUDED
