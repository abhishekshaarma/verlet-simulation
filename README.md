Verlet Physics Simulation
A real-time physics simulation using Verlet integration and SFML. This project simulates particles under gravit. 

### Features
Verlet integration for stable motion updates.
Particle collisions with realistic bouncing(need to add)
Interactive controls for pushing and pulling particles.

### Controls
Action	Key/Mouse
Move particles toward cursor	Left Click
Push particles away	Right Click
Exit simulation	Escape Key
### Configuration
Modify Solver.h to change physics behavior:

cpp
Copy
Edit
sf::Vector2f gravity = {0.0f, 500.0f}; // Gravity strength
int substep = 1; // Stability vs. performance
float damping = 0.50f; // Energy loss over time

