# Don't Touch Red

Don't Touch Red is a simple yet elegant game created using the raylib library in C++. This project was built for fun over a couple of hours as an exploration of C++. The core concept of the game is that you have not lost until you touch the red square – though no one is forcing you to, it is the natural curiosity that often leads us to test our limits.

## About the Game

In this game you control a yellow circle, avoiding a red square that moves vertically across the screen. A collision between the two results in an immediate loss, indicated by the message "You lost!".

### Key Features

- **Simple Controls:** Move your character using the `W`, `A`, `S`, `D` keys.
- **Dynamic Animation:** The red square moves at a constant pace, reversing direction when it reaches the boundaries of the window.
- **Minimalist Design:** A clean, uncluttered interface that lets you focus on the main objective.
- **Underlying Concept:** The game symbolises the human inclination to explore, even when the risks are well-known.

## Project Structure

The project consists of the following primary files:

- **main.cpp** – The main source file containing the game logic:
  - **Collision Detection:** The `CheckCollision` function determines whether the boundaries of the character and the red square overlap.
  - **Coordinate Updates:** The functions `UpdateCharacterEdges` and `UpdateAxeEdges` compute the boundaries of the objects to ensure precise collision detection.
  - **Game Loop:** The game window is initialised and maintained at 60 frames per second, handling user input and updating object positions.

- **.vscode/** – A folder containing configuration files for Visual Studio Code. These files ensure that raylib is correctly recognised and that the g++ compiler (provided with raylib) is properly configured for this project.

## Setting Up

### Requirements

- **Raylib:** Ensure that the raylib library is installed in the `C:\raylib` directory. This is crucial, as the configuration files in the `.vscode` folder rely on this path to locate the g++ compiler that comes with raylib.

### Instructions

1. **Install Raylib:**
   - Download and install [raylib](https://www.raylib.com/) in the `C:\raylib` directory.

2. **Clone the Repository:**
   ```bash
   git clone https://github.com/Flammans/dont-touch-red.git

3. **Build and Run:**
   - Open the project in your chosen development environment.
   - Build the project using the configured build task or your IDE's build system.
   - Run the compiled application. The game window (640x480) will appear and you can begin playing.
