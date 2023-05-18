#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

int grid[ROWS][COLS];

void init_grid(int num_lives) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (num_lives > 0) {
                grid[i][j] = 1;
                num_lives--;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// void init_grid() {
//     int i, j;
//     for (i = 0; i < ROWS; i++) {
//         for (j = 0; j < COLS; j++) {
//             grid[i][j] = rand() % 2;//количество жизней на игровом поле определяется случайно; grid[0][0] = 1;
//         }
//     }
// }

void draw_grid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                mvprintw(i, j, "X");
            } else {
                mvprintw(i, j, " ");
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
    srand(time(NULL));
    initscr();//инициализация ncurses
    cbreak();//отключение буферизации ввода
    noecho();//отключение вводимых символов
    curs_set(0);//скрытие курсора на экране
    int num_lives;
    printf("Enter the number of lives: ");
    scanf("%d", &num_lives);
    init_grid(num_lives);//инициализация игрового поля
    while (1) {//бесконечный цикл для обновления игрового поля
        clear();//очищение экрана перед отрисовкой нового кадра
        draw_grid();//отрисовка игрового поля
        refresh();//обновление экрана при новом кадре
        update_grid();//обновление состояния игрового поля
        napms(100);//приостановление выполнения программы на 100мс
    }
    endwin();//завершение работы с библиотекой
    return 0;
}

// int main() {
//     srand(time(NULL));
//     initscr();//инициализация ncurses
//     cbreak();//отключение буферизации ввода
//     noecho();//отключение вводимых символов
//     curs_set(0);//скрытие курсора на экране
//     init_grid();//инициализация игрового поля
//     while (1) {//бесконечный цикл для обновления игрового поля
//         clear();//очищение экрана перед отрисовкой нового кадра
//         draw_grid();//отрисовка игрового поля
//         refresh();//обновление экрана при новом кадре
//         update_grid();//обновление состояния игрового поля
//         napms(100);//приостановление выполнения программы на 100мс
//     }
//     endwin();//завершение работы с библиотекой
//     return 0;
// }