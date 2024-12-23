#include <iostream>
#include <vector>

// Include the headers
// #include "headers/game.h" // Not required as already in output.h
#include "headers/output.h"

void config(Game &game) {
    char ch;
    int x = 0, y = 0;

    while(true) {
        output(game); // Output the Current Game State

        std::cout << "\n> ";  // Create a CLI Prompt
        std::cin >> ch;     // Get the option

        switch(ch) {
            case 'h':   // Help
                std::cout << "Availible Optiions: " << std::endl;
                std::cout << "'c' - Change display Characters" << std::endl;
                std::cout << "'s' - Toggle State of a Cell" << std::endl;
                std::cout << "'x' - Exit Configurator" << std::endl;

                system("pause");
                break;

            case 'r':
            case 'x':   // Exit
                std::cout << "Exitting Utility, Beginning Simulation." << std::endl;
                return;
                break;

            case 's':   // Set
                std::cout << "Please Enter the x and y Coordinates of the cell to toggle." << std::endl;
                std::cout << "x: ";
                std::cin >> x;
                std::cout << "y: ";
                std::cin >> y;

                // Check for Out of bounds
                if(x >= game.xDim || y >= game.yDim) {
                    std::cout << "Out of Bounds !!" << std::endl;
                    system("pause");
                    break;
                }

                game.gameState.at(y).at(x) = !(game.gameState.at(y).at(x));
                break;

            case 'c':
                std::cout << "Please Enter the alternative Characters for the UI:" << std::endl;
                std::cout << "Cell Dead: ";
                std::cin >> game.dead;
                std::cout << "Cell Alive: ";
                std::cin >> game.alive;

                break;

            default:    // Default Case
                std::cout << "Incorrect Option Entered." << std::endl;
                std::cout << "Type 'h' for Help." << std::endl;

                system("pause");
                break;

        }

    }

}

int main() {

    int xDim, yDim;
    int cap = 100;  // Max cap of the dimensions

    // Get the Canvas Dimensions from the Player
    std::cout << "Please Enter the Dimensions of the Game Canvas: " << "\nx: ";
    std::cin >> xDim;
    std::cout << "y: ";
    std::cin >> yDim; 

    Game game((xDim >= cap) ? cap : xDim , (yDim >= cap) ? cap : yDim);  // Create a new game with dimensions capped (for safety)

    // Configure the game environment
    config(game);

    int times;
    while(true) {

        if(game.notStable == false) {
            std::cout << "Game has Stabilized..." << std::endl;
            system("pause");
            game.notStable = true;
        }

        std::cout << "Run Times: ";
        std::cin >> times;

        if (times > 0) {
            for(int i = 0; i < times && game.notStable; i ++) {
                output(game);
                game.update();
            }
        }
        else if (times == 0){
            std::cout << "Exitting!" << std::endl;

            system("pause");
            break;
        }
        else {
            std::cout << "Please Check your Input!" << std::endl;
            std::cout << "Enter '0' to Exit." << std::endl;
            system("pause");
        }

    }
    
    return 0;
}