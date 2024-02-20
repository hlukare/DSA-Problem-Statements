/*  Problem Statement : Knight’s tour: The problem is to move the knight, beginning from any given square on the 
                        chessboard, in such a manner that it travels successively to all 64 squares, touching each
                        square once and only once. It is convenient to represent a solution by placing the numbers
                        1,2, ...,64 in the squares of the chessboard indicating the order in which the squares are 
                        reached. Note that it is not required that the knight be able to reach the initial position 
                        by one more move; if this is possible the knight's tour is called re-entrant. One of the more 
                        ingenious methods for solving the problem of the knight's tour is that given by J. C. Warnsdorff
                        in 1823. His rule is that the knight must always be moved to one of the squares from which there
                        are the fewest exits to squares not already traversed. Write a C++ program to implement Warnsdorff's
                        rule and show it graphically.

*/

#include <iostream>
using namespace std;

// chessboard size
const int N = 8; 
const int M = 8; 

int board[N][M];

// Possible moves for the Knight
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

// A function to check if a move is valid
bool valid(int x, int y) 
{
    if(x >= 0 && y >= 0 && x < N && y < M) 
    {
        if(board[x][y] == -1) 
        {
            return true; // if valid then return true
        }
    }
    return false; // if not valid then return false
}


// Function to solve the actual Knight's Tour problem
bool knightTour(int x, int y, int step) 
{
    // condition to check All squares have been visited or not
    if(step == N * M) 
    {
        return true; 
    }

    // incrementing the x and y values
    for(int i = 0; i < 8; i++) 
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        // valid function is called to check whether the step is valid or not
        if(valid(nextX, nextY)) 
        {
            // incrementing the step variable value
            board[nextX][nextY] = step;
            // it is the recursive call to the knightTour function for the new position 
            if(knightTour(nextX, nextY, step + 1)) 
            {
                return true;
            }
            // if no further cells found then backtrack
            board[nextX][nextY] = -1;
        }
    }
    // if it returns false then algorithm will backtrack to find other possibilities
    return false;
}

int main() 
{
    // Initialize the board and mark all squares as unvisited
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] = -1;
        }
    }

    // Initializing the knight's tour cell
    int startX = 0;
    int startY = 0;
    board[startX][startY] = 0;

    if(knightTour(startX, startY, 1)) 
    {
        // If knight's found, print the solution
        for(int i = 0; i < N; i++) 
        {
            for(int j = 0; j < M; j++) 
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } 
    else 
    {
        cout << "No solution exists." << endl;
    }
    return 0;
}