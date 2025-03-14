Verlet Integration Simulation

Overview

This project is a Verlet Integration-based physics simulation using SFML (Simple and Fast Multimedia Library). It models particle movement and collisions within a defined boundary while implementing realistic physics behaviors such as gravity, velocity reflection, and object interactions.

Features

Verlet Integration for smooth and stable physics-based movement.

Collision Detection & Response ensuring realistic bouncing particles.

Boundary Constraints to prevent particles from leaving the simulation window.

Mouse Interaction to pull or push particles.

Optimized Performance using a structured Solver for efficient updates.

Technologies Used

C++

SFML (Simple and Fast Multimedia Library)

Git & GitHub (for version control)

Installation & Setup

1️⃣ Install SFML (if not already installed)

sudo apt-get install libsfml-dev  # For Ubuntu/Debian
yum install SFML-devel             # For Fedora
brew install sfml                  # For macOS

2️⃣ Clone the Repository

git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation

3️⃣ Compile the Project

g++ main.cpp solver.h particle.h renderer.h -lsfml-system -lsfml-window -lsfml-graphics -o verlet_simulation

4️⃣ Run the Simulation

./verlet_simulation

How It Works

Physics Engine (Solver.h)

Uses Verlet Integration instead of traditional velocity-based physics.

Handles gravity, particle updates, and collision detection.

Implements boundary constraints to prevent objects from leaving the screen.

Particle System (Particle.h)

Stores each particle's position, previous position, acceleration, and radius.

Updates movement using Verlet-based calculations.

Handles velocity modifications based on interactions.

Rendering (Renderer.h)

Uses SFML to draw particles and boundaries.

Updates each frame with new object positions.

User Interaction

Left Mouse Click → Pulls nearby particles.

Right Mouse Click → Pushes nearby particles.

ESC Key → Closes the simulation.

Future Improvements

More optimized collision detection using spatial hashing.

Friction and damping improvements for realistic slow-down.

More interaction modes (drag and drop, object creation, etc.).

Author

Abhishek Sharma

GitHub: abhishekshaarma

License

This project is open-source under the MIT License. Feel free to modify and contribute!

Enjoy simulating physics with Verlet Integration! 🚀
