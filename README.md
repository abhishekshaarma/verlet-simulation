Verlet Physics Simulation
A physics-based simulation using Verlet integration and SFML to model particles with gravity, boundary constraints, and interactive forces.

🚀 Features
✅ Verlet integration for smooth physics simulation.
✅ Realistic collisions with boundary constraints.
✅ Mouse interactions for pushing and pulling particles.
✅ Efficient update loop with adjustable substeps.
✅ SFML-based rendering with real-time visualization.

🛠 Installation & Setup
1️⃣ Clone the Repository
sh
Copy
Edit
git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation
2️⃣ Install Dependencies
SFML (Simple and Fast Multimedia Library)
Install SFML using:
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
Download SFML from https://www.sfml-dev.org/download.php
Extract and set up the include and lib paths.
💻 Compilation & Running
1️⃣ Compile the Code
Use g++ to compile with SFML:

sh
Copy
Edit
g++ main.cpp solver.h particle.h renderer.h -o verlet-simulation -lsfml-graphics -lsfml-window -lsfml-system
2️⃣ Run the Simulation
sh
Copy
Edit
./verlet-simulation
🕹️ Controls
🎯 Left Click: Pull particles toward the cursor.
🚀 Right Click: Push particles away.
❌ Escape Key: Exit the simulation.

🔧 Configuration
Modify these parameters in Solver.h for different behaviors:

gravity = {0.0f, 500.0f}; → Adjusts gravity strength.
substep = 1; → Increase for more stable physics.
damping = 0.50f; → Controls energy loss over time.
📜 Code Overview
🔹 Main Files
main.cpp → Runs the simulation loop.
solver.h → Handles physics updates & constraints.
particle.h → Defines particle properties & movement.
renderer.h → Manages SFML rendering.
