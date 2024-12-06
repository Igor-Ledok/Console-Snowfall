#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread> 
void populateSnowflakes(std::string** grid, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = " ";
        }
    }

    int snowflakesCount = (rows * cols) / 5; 

    while (snowflakesCount > 0) {
        int x = std::rand() % rows;
        int y = std::rand() % cols;

        if (grid[x][y] == " " &&
            (x == 0 || grid[x - 1][y] == " ") &&
            (y == 0 || grid[x][y - 1] == " ") &&
            (x == rows - 1 || grid[x + 1][y] == " ") &&
            (y == cols - 1 || grid[x][y + 1] == " ")) {
            grid[x][y] = "*";
            --snowflakesCount;
        }
    }
}

void displayGrid(std::string** grid, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(std::time(nullptr));

    int rows, cols;

    std::cout << "Enter number of rows (vertical): ";
    std::cin >> rows;
    std::cout << "Enter number of columns (horizontal): ";
    std::cin >> cols;

    std::string** grid = new std::string * [rows];
    for (int i = 0; i < rows; ++i) {
        grid[i] = new std::string[cols];
    }

    populateSnowflakes(grid, rows, cols);

    while (true) {
        displayGrid(grid, rows, cols);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif

        delete[] grid[rows - 1];
        for (int i = rows - 1; i > 0; --i) {
            grid[i] = grid[i - 1];
        }

        grid[0] = new std::string[cols];
        for (int j = 0; j < cols; ++j) {
            grid[0][j] = " ";
        }

        int snowflakesInTopRow = cols / 6;
        while (snowflakesInTopRow > 0) {
            int y = std::rand() % cols;
            if (grid[0][y] == " ") {
                grid[0][y] = "*";
                --snowflakesInTopRow;
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
