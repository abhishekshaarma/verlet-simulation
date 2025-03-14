#include <string>
#include <SFML/Graphics.hpp>
#include "particle.h"
#include "solver.h"

class Renderer
{
public:
    Renderer(sf::RenderTarget &target_)
        :target{target_}
    {}

   
    void render(Solver &solver)
    {
        //  Get window size as boundary
        const sf::Vector2f boundary = solver.getBoundary();

        // Draw boundary as a rectangle (window edges)
        sf::RectangleShape boundary_rect(boundary);
        boundary_rect.setFillColor(sf::Color::Transparent); 
        boundary_rect.setOutlineColor(sf::Color::Black);   
        boundary_rect.setOutlineThickness(5.0f);          
        boundary_rect.setPosition(0, 0);                   
        target.draw(boundary_rect);                        

        //  Draw particles
        sf::CircleShape circle{1.0f};
        const auto& objects = solver.get_objects();
        for(const auto &obj : objects)
        {
            circle.setRadius(obj.radius);
            circle.setOrigin(obj.radius, obj.radius); 
            circle.setPosition(obj.position);
            circle.setFillColor(sf::Color::Cyan);
            target.draw(circle);
        }
    }


private:
    sf::RenderTarget &target;
};

