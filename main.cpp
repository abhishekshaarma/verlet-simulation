#include <iostream>
#include <cstdint> // For uint32_t
#include <SFML/Graphics.hpp>
#include "renderer.h"
#include "solver.h"
#include <ctime>
int main()
{
    const int window_height = 840;
    const int window_length = 840;
    const size_t max_objects = 500;
    const float spawn_delay = 1.0f; 
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    
    sf::RenderWindow window(sf::VideoMode(window_height,window_length),
                            "Verlet", sf::Style::Default, settings);
    sf::Clock clock; 
    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);
    
    Renderer renderer{window};
    Solver solver;
    solver.set_boundary({static_cast<float>(window.getSize().x), 
                     static_cast<float>(window.getSize().y)}); 
    solver.addObject({400.0f, 150.0f}, 10.0f);
    //mainloop
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            float ratio = 840.0f / window.getSize().x;
            sf::Vector2f pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)) *  ratio;
            solver.mouse_pull(pos);
            
        }
        
        //particles
        if (solver.get_objects().size() < max_objects && clock.getElapsedTime().asSeconds() >= spawn_delay)
        {
            std::cout << "Spawning new particle!" << std::endl; 
            clock.restart();
            auto &object = solver.addObject({400.0f, 150.0f}, 10.0f);
            solver.setObjectVelocity(object, {500.0f, 50.0f});
        }
        solver.update();
        window.clear(sf::Color::Black);
        renderer.render(solver);  
        window.display();
    }
    return 0;
}
