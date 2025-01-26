#include "raylib.h"

// Function to check collision between character and axe
bool CheckCollision(int lAxeX, int rAxeX, int uAxeY, int dAxeY, int lCharacterX, int rCharacterX, int uCharacterY, int dCharacterY) {
    return (dAxeY >= uCharacterY) && 
           (uAxeY <= dCharacterY) && 
           (rAxeX >= lCharacterX) && 
           (lAxeX <= rCharacterX);
}

// Function to update character edges
void UpdateCharacterEdges(int characterX, int characterY, int characterRadius, int &lCharacterX, int &rCharacterX, int &uCharacterY, int &dCharacterY) {
    lCharacterX = characterX - characterRadius;
    rCharacterX = characterX + characterRadius;
    uCharacterY = characterY - characterRadius;
    dCharacterY = characterY + characterRadius;
}

// Function to update axe edges
void UpdateAxeEdges(int axeX, int axeY, int axeLength, int &lAxeX, int &rAxeX, int &uAxeY, int &dAxeY) {
    lAxeX = axeX;
    rAxeX = axeX + axeLength;
    uAxeY = axeY;
    dAxeY = axeY + axeLength;
}

int main() {
    // Window dimensions
    const int width = 640; 
    const int height = 480;

    // Character coordinates
    int characterRadius = 50;
    int characterX = width / 2 - characterRadius;
    int characterY = height / 2 - characterRadius;

    // Character edges coordinates
    int lCharacterX, rCharacterX, uCharacterY, dCharacterY;
    UpdateCharacterEdges(characterX, characterY, characterRadius, lCharacterX, rCharacterX, uCharacterY, dCharacterY);

    // Axe coordinates
    int axeX = height / 2 + 100; 
    int axeY = 0; 
    int axeLength = 50;

    // Axe edges coordinates
    int lAxeX, rAxeX, uAxeY, dAxeY;
    UpdateAxeEdges(axeX, axeY, axeLength, lAxeX, rAxeX, uAxeY, dAxeY);

    int direction = 10;

    // Create window
    InitWindow(width, height, "Don't Touch Red");

    // Set frames per second
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Update the edges coordinates
        UpdateCharacterEdges(characterX, characterY, characterRadius, lCharacterX, rCharacterX, uCharacterY, dCharacterY);
        UpdateAxeEdges(axeX, axeY, axeLength, lAxeX, rAxeX, uAxeY, dAxeY);

        // Check for collision
        bool colisionWithAxe = CheckCollision(lAxeX, rAxeX, uAxeY, dAxeY, lCharacterX, rCharacterX, uCharacterY, dCharacterY);

        if (colisionWithAxe) {
            DrawText("You lost!", width / 2 - 50, height / 2, 20, RED);
        } else {
            // Game logic begins here

            DrawText("Don't Touch Red", 10, 10, 20, LIGHTGRAY);
            DrawCircle(characterX, characterY, characterRadius, YELLOW);
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);

            // Move the axe
            axeY += direction;       
            if (axeY > height - axeLength || axeY < 0) {
                direction = -direction;
            }

            // Move the character
            if (IsKeyDown(KEY_D) && characterX < width - characterRadius) {
                characterX += 10;           
            }
            if (IsKeyDown(KEY_A) && characterX > characterRadius) {
                characterX -= 10;
            }
            if (IsKeyDown(KEY_W) && characterY > characterRadius) {
                characterY -= 10;
            }
            if (IsKeyDown(KEY_S) && characterY < height - characterRadius) {
                characterY += 10;
            }
        }

        // Game logic ends here
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
}
