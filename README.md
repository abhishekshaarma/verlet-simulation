🚀 Verlet Physics Simulation

A real-time physics simulation using Verlet integration and SFML! 🌀
Features realistic particle movement, collision detection, gravity, and mouse interactions.

🎮 Live Demo (Coming Soon!)

📌 Features
✔️ Smooth Verlet Integration – More stable than Euler physics.
✔️ Realistic Particle Collisions – Particles interact and bounce off walls.
✔️ Interactive Controls – Pull & push particles using the mouse.
✔️ Optimized Performance – Uses an efficient update loop.
✔️ SFML-based Rendering – Handles visuals in real-time.

📜 Table of Contents
📌 Installation & Setup
📌 How to Compile & Run
📌 Controls
📌 Customization
📌 Project Structure
📌 Contributing

🛠 Installation & Setup
1️⃣ Clone the Repository
sh
Copy
Edit
git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation
2️⃣ Install SFML (Required)
🔹 Linux (Ubuntu/Debian)

sh
Copy
Edit
sudo apt install libsfml-dev
🔹 Mac (Homebrew)

sh
Copy
Edit
brew install sfml
🔹 Windows

Download SFML from SFML Official Site.
Extract it and configure the include and lib paths.
💻 How to Compile & Run
🔹 Compilation
Use g++ to compile with SFML:

sh
Copy
Edit
g++ main.cpp solver.h particle.h renderer.h -o verlet-simulation -lsfml-graphics -lsfml-window -lsfml-system
🔹 Run the Simulation
sh
Copy
Edit
./verlet-simulation
🎮 Controls
Action	Key/Mouse
Move Particles Toward Cursor	🖱️ Left Click
Push Particles Away	🖱️ Right Click
Exit Simulation	⏹️ Escape Key
⚙️ Customization
Modify Solver.h to adjust physics behavior:

cpp
Copy
Edit
sf::Vector2f gravity = {0.0f, 500.0f}; // Adjust gravity strength
int substep = 1; // Increase for more stable physics
float damping = 0.50f; // Controls energy loss over time
📌 Tip: Higher substep values improve stability but reduce performance.

📂 Project Structure
bash
Copy
Edit
verlet-simulation/
│── main.cpp        # Main application loop
│── solver.h        # Verlet physics engine
│── particle.h      # Particle properties & movement
│── renderer.h      # SFML-based rendering system
│── README.md       # Project documentation
<details> <summary>📜 **How Does Verlet Integration Work?** (Click to Expand)</summary>
Unlike traditional Euler integration, which can cause energy drift, Verlet integration:

Uses position instead of velocity for updates.
Is more stable and reduces numerical errors.
Allows smooth and natural motion in physics simulations.
</details>
🔗 Contributing
🙌 Want to improve this project? Fork the repository and submit a PR!

sh
Copy
Edit
git clone https://github.com/abhishekshaarma/verlet-simulation.git
cd verlet-simulation
git checkout -b feature-branch
📌 After making changes:

sh
Copy
Edit
git add .
git commit -m "Added new feature"
git push origin feature-branch
