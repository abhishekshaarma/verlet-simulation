#ifndef PARTICLE_H
#define PARTICLE_H
#include <SFML/Graphics.hpp>
struct Particle
{
  public:
    sf::Vector2f position;
    sf::Vector2f last_position; // Fixed typo
    sf::Vector2f acceleration;
    float radius = 10.0f;
    Particle() = default;
    
    Particle(sf::Vector2f position_, float radius_)
        : position{position_}, 
          last_position{position_}, 
          acceleration(10.0f, 10.0f), 
          radius(radius_) 
    {}
    void update(float dt)
    {
        
    
        sf::Vector2f displacement = position - last_position;
        last_position = position;
        position = position + displacement + acceleration * (dt * dt);
        acceleration = {0.0f, 0.0f}; // reset the acceleration l
    }
    void accelerate(sf::Vector2f a)
    {
        acceleration += a;
    }
    void add_velocity(sf::Vector2f a, float dt)
    {
        last_position -= (a * dt);
    }
    void set_velocity(sf::Vector2f a ,float dt)
    {
        last_position = position - (dt * a);
    }
    sf::Vector2f get_velocity()
    {
        return -last_position + position;
    }
              
};
#endif // PARTICLE_H
