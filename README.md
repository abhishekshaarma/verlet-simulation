Verlet Physics Simulation
A real-time physics simulation using Verlet integration and SFML. This project simulates particles under gravity, handles collisions, and allows interaction using the mouse.

### Features
Verlet integration for stable motion updates.
Particle collisions with realistic bouncing.
Interactive controls for pushing and pulling particles.
Boundary constraints to keep particles within the simulation window.
SFML-based real-time rendering.
### Installation & Setup
1. Clone the Repository
sh
Copy
Edit
git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation
2. Install SFML
Linux (Ubuntu/Debian)
sh
Copy
Edit
sudo apt install libsfml-dev
Mac (Homebrew)
sh
Copy
Edit
brew install sfml
Windows
Download SFML from SFML Official Site.
Extract it and set up the include and lib paths.
### Compilation & Running
Compile the Project
sh
Copy
Edit
g++ main.cpp solver.h particle.h renderer.h -o verlet-simulation -lsfml-graphics -lsfml-window -lsfml-system
Run the Simulation
sh
Copy
Edit
./verlet-simulation
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
### Project Structure
bash
Copy
Edit
verlet-simulation/
│── main.cpp        # Main application loop
│── solver.h        # Verlet physics engine
│── particle.h      # Particle properties & movement
│── renderer.h      # SFML-based rendering system
│── README.md       # Project documentation
### Contributing
To contribute, fork the repository and submit a pull request.

sh
Copy
Edit
git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation
git checkout -b feature-branch
After making changes:

sh
Copy
Edit
git add .
git commit -m "Added new feature"
git push origin feature-branch
