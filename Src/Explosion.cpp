/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#include "Explosion.hpp"

Explosion::Explosion(sf::Vector2f P, sf::Color C)
{
    this->Position = P;
    if(rand() % 2)
        this->Velocity.x = rand() % 10;
    else
        this->Velocity.x = (rand() % 10) * (-1);
    if(rand() % 2)
        this->Velocity.y = rand() % 10;
    else
        this->Velocity.y = (rand() % 10) * (-1);
    this->Color = C;
    this->AlphaSub = this->Color.a / (rand() % 50 + 5);
    this->Tick = 0;
    return;
};

Explosion::~Explosion()
{
    return;
};

sf::Color Explosion::GetColor( void )
{
    return this->Color;
};

sf::Vector2f Explosion::GetPosition( void )
{
    return this->Position;
};

bool Explosion::Poll ( void )
{
    if(this->Color.a - this->AlphaSub <= 0 || Tick >= 50)
        return false;
    this->Position = this->Position + this->Velocity;
    this->Color.a = this->Color.a - this->AlphaSub;
    if(this->Color.a > 200)
        this->Color.a = 200;
    this->Tick++;
    return true;
};
