#include <iostream>
using namespace std;

// Function to check if the current position (x, y) is safe for the rat to move
bool isSafe(int** maze, int x, int y, int n) {
    if (x < n && y < n && maze[x][y] == 1) {
        return true;
    }
    return false;
}

// Recursive function to solve the maze
bool solveMaze(int** maze, int x, int y, int n, int** solution) {
    // Base case: If the rat reaches the bottom-right corner
    if (x == n - 1 && y == n - 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y, n)) {
        // Mark the current cell as part of the solution path
        solution[x][y] = 1;

        // Move down in the x direction
        if (solveMaze(maze, x + 1, y, n, solution)) {
            return true;
        }

        // Move right in the y direction
        if (solveMaze(maze, x, y + 1, n, solution)) {
            return true;
        }

        // If neither direction works, backtrack
        solution[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int n;
    
    // Input: size of the maze
    cout << "Enter the size of the maze: ";
    cin >> n;

    // Create the maze dynamically
    int** maze = new int*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
    }

    // Input: maze matrix
    cout << "Enter the maze matrix (1 for open path, 0 for blocked): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    // Create the solution matrix and initialize it to 0
    int** solution = new int*[n];
    for (int i = 0; i < n; i++) {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }

    // Call the solveMaze function and print the solution if one exists
    if (solveMaze(maze, 0, 0, n, solution)) {
        cout << "Solution path:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;

    return 0;
}
