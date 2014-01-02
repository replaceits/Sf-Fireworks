/*
    Sf-Fireworks
    By replaceits
    January 1st, 2014
*/

#include "Firework.hpp"

Firework::Firework(std::vector<Particle*> *PV)
{
    this->Color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    this->Position = sf::Vector2f(rand() % 801,600);
    this->Velocity = sf::Vector2f(rand() % 5 + 1, (rand() % 8 + 3)*(-1));
    if(this->Position.x >= 400)
        this->Velocity.x = this->Velocity.x * (-1);
    this->Tick = 0;
    this->ParticleVector = PV;
    return;
};

Firework::~Firework()
{
    return;
};

sf::Color Firework::GetColor( void )
{
    return this->Color;
};

sf::Vector2f Firework::GetPosition( void )
{
    return this->Position;
};

bool Firework::Poll ( void )
{
    this->Position = this->Position + this->Velocity;
    for(unsigned short int y = 0; y < this->Velocity.y * (-1); ++y )
        for(unsigned short int i = 0; i < 5; i++)
            this->ParticleVector->push_back(new Particle(sf::Vector2f(this->GetPosition().x,this->GetPosition().y + y),this->GetColor()));
    if(Tick >= 50)
        return false;
    this->Tick++;
    return true;
};
