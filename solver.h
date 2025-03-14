#ifndef SOLVER_H
#define SOLVER_H
#include <unordered_map>
#include "particle.h"
#include <vector>
#include <cmath>



class Solver
{
public:
    Solver() = default;

     Particle& addObject(sf::Vector2f position, float r)
    {
        objects.emplace_back(position, r); 
        return objects.back(); 
    }
    

     std::vector<Particle>& get_objects() 
    {
    return objects;
    }

    void update()
    {
        float dt = step_dt / substep;
        
        for(int i = 0; i < substep; i++)
        {
            apply_gravity();
            update_objects(dt);
            collisionDetection();
            apply_boundary();
        }
    }

    void set_boundary(sf::Vector2f window)
    {
        boundary_min = {0.0f, 0.0f};
        boundary_max = window;
    }
    
    sf::Vector2f getBoundary() const
    {
        return boundary_max; 
    }
   
    void mouse_pull(sf::Vector2f pos)
    {
        for(Particle &obj : objects)
        {
            sf::Vector2f dir = pos - obj.position;
            float dist = sqrt(dir.x * dir.x + dir.y * dir.y);
            obj.accelerate(dir*std::max(0.0f, 10 * (120 - dist)));
        }
    }

    void mouse_push(sf::Vector2f pos)
    {
        for (Particle &obj : objects)
        {
            sf::Vector2f dir = obj.position - pos; 
            float dist = sqrt(dir.x * dir.x + dir.y * dir.y);
            obj.accelerate(dir * std::max(-10 * (120 - dist), 0.0f));
        }
    }
    
    void setObjectVelocity(Particle& object, sf::Vector2f v)
    {
        object.set_velocity(v, getStepDt());
    }
    float getStepDt() const
    {
        return step_dt;
    }

    

    
private:
    std::vector<Particle> objects;
    sf::Vector2f gravity = {0.0f, 500.0f};

    sf::Vector2f boundary_min;
    sf::Vector2f boundary_max = {0.0f, 840.0f};

    int substep = 1;

    //std::unordered_map<int, std::vector <Particle*>> grid;
    // float cell_size = 20.0f;
    
    
    float step_dt = 1.0f/ 60.0;

    
    void apply_gravity()
    {
        for(auto &obj : objects)
        {
            obj.accelerate(gravity);
        }
    }

    
    
    void apply_boundary()
    {
        for (auto &obj : objects)
        {
            sf::Vector2f velocity = obj.get_velocity();
            

            if (obj.position.x - obj.radius < boundary_min.x)
            {
                obj.position.x = boundary_min.x + obj.radius;
                obj.set_velocity({-velocity.x, velocity.y}, 1.0f);
            }

            if (obj.position.x + obj.radius > boundary_max.x)
            {
                obj.position.x = boundary_max.x - obj.radius;
                obj.set_velocity({-velocity.x, velocity.y}, 1.0f);
            }

            if (obj.position.y - obj.radius < boundary_min.y)
            {
                obj.position.y = boundary_min.y + obj.radius;
                obj.set_velocity({velocity.x, -velocity.y}, 1.0f); 
            }

            if (obj.position.y + obj.radius > boundary_max.y)
            {
                obj.position.y = boundary_max.y - obj.radius;
                obj.set_velocity({velocity.x, -velocity.y}, 1.0f);
            }
            
        }
    }

    void update_objects(float dt)
    {
        float damping = 0.50f; // Energy loss factor (closer to 1 = slow decay)
        
        
        for (auto &obj : objects)
        {
            sf::Vector2f velocity = (obj.position - obj.last_position) * damping; //  Use obj.position
            obj.last_position = obj.position;
            obj.position += velocity + obj.acceleration * (dt * dt); //  Use obj.acceleration
            obj.acceleration = {}; //  Reset acceleration
        }  
    }

    void collisionDetection()
    {}

   
    


};

#endif // SOLVER_H
