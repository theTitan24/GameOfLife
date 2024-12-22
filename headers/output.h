#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void output(std::vector<std::vector<bool>> &gameState) {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    system("cls");  // Clear the console


    // Now let's loop throught and print the current state 
    for(int i = 0; i < gameState.size(); i++) {
        for(int j = 0; j < gameState[i].size(); j++) {
            if(gameState[i][j]) {
                std::cout << 'O' << ' ';   // Print any character for an alive cell
            } 
            else {    
                std::cout << '+' << ' ';   // And leave blank for dead block
            }
        }
        std::cout << std::endl;     // Go to the nex line
    }
}

// Same thing but n number of times
// Probably not requred; Maybe I'll remove it.
void output(std::vector<std::vector<bool>> gameState, int times) {
    for(int i = 0; i < times; i ++) {
        output(gameState);
    }
}