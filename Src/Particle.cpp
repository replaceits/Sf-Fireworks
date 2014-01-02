/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#include "Particle.hpp"

Particle::Particle(sf::Vector2f P, sf::Color C)
{
    this->Position = P;
    this->Color = C;
    this->AlphaSub = this->Color.a / (rand() % 15 + 5);
    this->Tick = 0;
    return;
};

Particle::~Particle()
{
    return;
};

sf::Color Particle::GetColor( void )
{
    return this->Color;
};

sf::Vector2f Particle::GetPosition( void )
{
    return this->Position;
};

bool Particle::Poll ( void )
{
    if(this->Position.y >= 600 || this->Color.a - this->AlphaSub <= 0)
        return false;
    this->Position = this->Position + sf::Vector2f(rand() % 5 - 3,rand() % 2);
    this->Color.a = this->Color.a - this->AlphaSub;
    if(this->Color.a > 200)
        this->Color.a = 200;
    return true;
};
