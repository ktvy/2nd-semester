#include "raylib.h"

#define ROWS 30
#define COLS 60
#define CELL_SIZE 20

int grid[ROWS][COLS];

void init_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = GetRandomValue(0, 1);
        }
    }
}

void draw_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, BLACK);
            } else {
                DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
            }
        }
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

void update_grid() {
    int new_grid[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    InitWindow(COLS * CELL_SIZE, ROWS * CELL_SIZE, "Game of Life");
    SetTargetFPS(60);
    init_grid();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        draw_grid();
        EndDrawing();
        update_grid();
    }
    CloseWindow();
    return 0;
}
