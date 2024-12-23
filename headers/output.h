#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "game.h"

void output(Game &game) {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    system("cls");  // Clear the console

    // Print the x indicies (only units digits; I'll think of something later)
    std::cout << "x ";
    for(int i = 0; i < game.xDim; i ++) {
        std::cout << (i % 10) << " ";
    }
    std::cout << std::endl;

    // Now let's loop throught and print the current state 
    for(int i = 0; i < game.yDim; i++) {
        std::cout << (i % 10) << " ";   // Print the y indices (units digit only)

        for(int j = 0; j < game.xDim; j++) {
            if(game.gameState[i][j]) {
                std::cout << game.alive << ' ';   // Print any character for an alive cell
            } 
            else {    
                std::cout << game.dead << ' ';   // And leave blank for dead block
            }
        }
        std::cout << std::endl;     // Go to the nex line
    }
}