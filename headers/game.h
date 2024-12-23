#include <iostream>
#include <vector>

/*
    ============================================================================================
    Rules of the Game of Life by John Conway
    ============================================================================================

    1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    2. Any live cell with two or three live neighbours lives on to the next generation
    3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

    Defination of neighbour: Any cell horizontally, vertically or diagonally adjacent.

    ~ Wikipedia
*/

class Game {
    public:
    
    int xDim, yDim;

    char dead, alive;

    std::vector<std::vector<bool>> gameState;
    std::vector<std::vector<bool>> gameStateOld;

    bool notStable;

    Game(int xDim, int yDim) {
        this->xDim = xDim;
        this->yDim = yDim;
        gameState.resize(yDim, std::vector<bool>(xDim, false)); // Set the size, and everything to false
        
        gameStateOld = gameState;   // Initialize the gameState backup

        notStable = true;

        dead = '+';
        alive = 'O';
    }

    int numOfNeighbours(int x, int y) {
        int neighbours = 0;

        // First try: Brute force it !!!
        // TODO: make it a bit more elegant
        
        // x - Axis neighbours
        if(x != 0) {
            if(gameStateOld.at(y).at(x - 1)) {
                neighbours ++;
            }
        }
        if(x != xDim - 1) {
            if(gameStateOld.at(y).at(x + 1)) {
                neighbours ++;
            }
        }

        // y - Axis and diagonal neighbours
        if(y != 0) {
            if(gameStateOld.at(y - 1).at(x)) {
                neighbours ++;
            }

            if(x != 0) {
                if(gameStateOld.at(y - 1).at(x - 1)) {
                    neighbours ++;
                }
            }
            if(x != xDim - 1) {
                if(gameStateOld.at(y - 1).at(x + 1)) {
                    neighbours ++;
                }
            }
        } 
        if(y != yDim - 1) {
            if(gameStateOld.at(y + 1).at(x)) {
                neighbours++;
            }

            if(x != 0) {
                if(gameStateOld.at(y + 1).at(x - 1)) {
                    neighbours ++;
                }
            }
            if(x != xDim - 1) {
                if(gameStateOld.at(y + 1).at(x + 1)) {
                    neighbours ++;
                }
            }
        }

        return neighbours;
    } 

    void update() {
        gameStateOld = gameState;   // Create a copy of GameState

        for(int y = 0; y < yDim; y ++) {
            for(int x = 0; x < xDim; x ++) {

                int neighbours = numOfNeighbours(x, y); // Get the Number of Neighbours

                // Rule 1 and 3
                if(neighbours < 2 || neighbours > 3) {
                    gameState.at(y).at(x) = false;
                }

                // Rule 2
                else if(neighbours == 2) {
                    continue;
                }

                // Rule 3
                else if(neighbours == 3) {
                    gameState.at(y).at(x) = true;
                }

                else {
                    std::cout << "Unknown Case Reached... Fatal Error" << std::endl;
                    return;
                }
                
            }
        }

        if(gameStateOld == gameState) {
            notStable = false;
            return;
        }
    }

};