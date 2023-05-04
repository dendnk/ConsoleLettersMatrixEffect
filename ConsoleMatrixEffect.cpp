// Letters Matrix Effect

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    const int WIDTH = 60;
    const int HEIGHT = 25;
    const int NUM_LETTERS = WIDTH;
    const int MAX_VELOCITY = 1;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize the screen
    vector<vector<char>> screen(HEIGHT, vector<char>(WIDTH, ' '));

    // Initialize the letters
    vector<char> letters(NUM_LETTERS);
    for (int i = 0; i < NUM_LETTERS; i++) {
        letters[i] = 'A' + i;
    }

    // Initialize the y-coordinates of the letters
    // Initialize the velocity for every letter
    vector<int> yCoords(NUM_LETTERS, 0);
    vector<int> deltaYCoords(NUM_LETTERS, 0);
    for (int i = 0; i < NUM_LETTERS; ++i)
    {
        yCoords[i] = rand() % HEIGHT;
        deltaYCoords[i] = 1 + (rand() % MAX_VELOCITY);
    }

    // Clear the console
    system("CLS");

    // Start the animation loop
    while (true) {
        // Update the y-coordinates of the letters
        for (int i = 0; i < NUM_LETTERS; i++) {
            yCoords[i] += deltaYCoords[i];
            if (yCoords[i] >= HEIGHT) {
                // Letter has gone out of the screen, store its y-coordinate
                yCoords[i] = rand() % HEIGHT;
                letters[i] = 'A' + (rand() % NUM_LETTERS);
                deltaYCoords[i] = 1 + (rand() % MAX_VELOCITY);
            }
        }

        // Draw the letters on the screen
        for (int i = 0; i < NUM_LETTERS; i++) {
            gotoxy(i * 2, yCoords[i]);
            cout << letters[i];
        }

        // Wait for a short time before updating the screen again
        Sleep(50);
    }

    return 0;
}