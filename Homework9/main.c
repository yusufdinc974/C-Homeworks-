#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct point {
    int row;
    int col;
} point;

typedef struct block {
    char type;
    int value;
} block;

block ***init_board();
void draw_board(block ***board, point *snake, int *n);
void play(block ***board, point *snake, int *n);
int check_status(block ***board, point *snake, int *n);
void move(point *snake, int *n, char *lastmove, int * movecounter);
void update(block ***board, point **snake, int *n, char *lastmove, int * movecounter);

int main() {
    int n = 1;
    int *ptr_n = &n;
    point *snake;
    snake = (point *)malloc(n * sizeof(point));

    play(init_board(), snake, ptr_n);

    free(snake);
    return 0;
}

block ***init_board() {
    int dim1 = 10, dim2 = 10, dim3 = 10;
    int random_y_b, random_x_b, random_y_o, random_x_o;
    int i, j, k;

    block ***board = (block ***)malloc(10 * sizeof(block **));

    for (i = 0; i < 10; i++) {
        board[i] = (block **)malloc(10 * sizeof(block *));

        for (j = 0; j < 10; j++) {
            board[i][j] = (block *)malloc(10 * sizeof(block));
            board[i][j][0].type = 'e';
            board[i][j][0].value = 0;
        }
    }

    srand(time(NULL));
    random_x_b = (rand() % 9) + 1;
    random_y_b = (rand() % 9) + 1;
    random_x_o = (rand() % 9) + 1;
    random_y_o = (rand() % 9) + 1;

    while (random_x_b == random_x_o && random_y_b == random_y_o) {
        random_x_b = (rand() % 9) + 1;
        random_y_b = (rand() % 9) + 1;
    }

    board[random_x_b][random_y_b][0].type = 'b';
    board[random_x_o][random_y_o][0].type = 'o';
    board[random_x_o][random_y_o][0].value = (rand() % 3) + 1;

    return board;
}

void draw_board(block ***board, point *snake, int *n) {
    int i, j, k;
    int flag = 0;

    printf("snake in: %dx %dy %dn\n", snake[0].row, snake[0].col, *n);

    printf(" - - - - - - - - - - \n");

    for (i = 0; i < 10; i++) {
        
        printf("|");

        for (j = 0; j < 10; j++) {
           
            for (k = 1; k < *n; k++) {
                
                if (i == snake[k].row && j == snake[k].col) {
                
                    printf(" X");
                    flag = 1;
                
                }
            }

            if (i == snake[0].row && j == snake[0].col) {
            
                printf(" O");
            
            }
            else if (board[i][j][0].type == 'e' && flag != 1) {
            
                printf("  ");
            
            } 
            else if (board[i][j][0].type == 'o') {
            
                printf(" %d", board[i][j][0].value);
            
            } 
            else if (board[i][j][0].type == 'b') {
            
                printf(" .");
            
            }

            flag = 0;
        }

        printf("|\n");
    }

    printf(" - - - - - - - - - - \n");
}

void play(block ***board, point *snake, int *n) {

    int check, movecounter = 1;
    char lastmove;

    /* Initializing the snake */
    snake[0].col = 0;
    snake[0].row = 0;

    draw_board(board, snake, n);

    while (1) {
        move(snake, n, &lastmove, &movecounter);
        check = check_status(board, snake, n);

        if (check == 1) {
            exit(0);
        } else {
            update(board, &snake, n, &lastmove, &movecounter);
            draw_board(board, snake, n);
        }
    }
}

int check_status(block ***board, point *snake, int *n) {
    int i, j;

    if (snake[0].col < 0 || snake[0].row < 0 || snake[0].col > 9 || snake[0].row > 9) {
        return 1;
    }

    for (i = 1; i < *n; i++) {
        if (snake[0].col == snake[i].col && snake[0].row == snake[i].row) {
            return 1;
        }
    }

    for (i = 0; i < 10; i++) {
        
        for (j = 0; j < 10; j++) {
            
            if (board[i][j][0].type == 'o' && snake[0].col == j && snake[0].row == i) {
                
                if (board[i][j][0].value >= *n) {
                 
                    return 1;
                
                } 
                
                else{
                    
                    return 0;
                
                }
            }
        }
    }

    return 0;
}

void move(point *snake, int *n, char *lastmove, int *movecounter) {
    int i;
    char move;
    int head_row = snake[0].row;
    int head_col = snake[0].col;

    printf("Enter a move: ");
    scanf(" %c", &move);
    printf("\n");

    switch (move) {
        case 'w':
            if (!((head_row - 1 == snake[1].row) && (head_col == snake[1].col))) {
                for (i = 0; i < *n; i++) {
                    snake[i].row--;
                }
            }
            *lastmove = 'w';
            (*movecounter)++;
            break;

        case 's':
            if (!((head_row + 1 == snake[1].row) && (head_col == snake[1].col))) {
                for (i = 0; i < *n; i++) {
                    snake[i].row++;
                }
            }
            *lastmove = 's';
            (*movecounter)++;
            break;

        case 'd':
            if (!((head_col + 1 == snake[1].col) && (head_row == snake[1].row))) {
                for (i = 0; i < *n; i++) {
                    snake[i].col++;
                }
            }
            *lastmove = 'd';
            (*movecounter)++;
            break;

        case 'a':
            if (!((head_col - 1 == snake[1].col) && (head_row == snake[1].row))) {
                for (i = 0; i < *n; i++) {
                    snake[i].col--;
                }
            }
            *lastmove = 'a';
            (*movecounter)++;
            break;
    }
}

void update(block ***board, point **snake, int *n, char *lastmove, int *movecounter) {
    int i, j, temp_r, temp_c, blockcounter = 0,k,l;
    int random_x_b, random_y_b;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (board[i][j][0].type == 'b' && (*snake)[0].col == j && (*snake)[0].row == i) {
                
                board[i][j][0].type = 'e';

                random_x_b = (rand() % 9) + 1;
                random_y_b = (rand() % 9) + 1;

                board[random_x_b][random_y_b][0].type = 'b';

                (*n)++;

                *snake = (point *)realloc(*snake, (*n) * sizeof(point));
                
                for (i = *n - 1; i > 0; i--) {
                
                    (*snake)[i].col = (*snake)[i - 1].col;
                    (*snake)[i].row = (*snake)[i - 1].row;
                
                }

                switch (*lastmove) {
                case 'a':
                
                for (i = *n - 1; i > 0; i--) {
                
                    (*snake)[i].col--;
                    (*snake)[i].row = (*snake)[i - 1].row;
                
                }
                
                break;
        
                case 'd':
                for (i = *n - 1; i > 0; i--) {
                
                    (*snake)[i].col++;
                    (*snake)[i].row = (*snake)[i - 1].row;
                
                }
                break;
        
                case 'w':
                for (i = *n - 1; i > 0; i--) {
                
                    (*snake)[i].col = (*snake)[i - 1].col;
                    (*snake)[i].row--;
                
                }
                break;
        
                case 's':
                for (i = *n - 1; i > 0; i--) {
                
                    (*snake)[i].col = (*snake)[i - 1].col;
                    (*snake)[i].row++;
                
                }
                break;
                }


                printf("snake in: %dx %dy\n", (*snake)[1].row, (*snake)[1].col);
            }

            else if (board[i][j][0].type == 'o' && (*snake)[0].col == j && (*snake)[0].row == i) {
                
                if (board[i][j][0].value < *n) {

                    board[i][j][0].type = 'e';
                    
                    random_x_b = (rand() % 9) + 1;
                    random_y_b = (rand() % 9) + 1;

                    board[random_x_b][random_y_b][0].type = 'o'; 
                    board[random_x_b][random_y_b][0].value = (rand() % 3) + 1;
                
                }

            }

        }
    }

            for (k = 0; k < 10; k++){
                
                for (l = 0; l < 10; l++){
                    
                    if(board[k][l][0].type == 'o'){

                        blockcounter++;

                    }

                }
                

            }
            

            if(*movecounter % 5 == 0){

                if(blockcounter == 3){

                    for(k=0; k<10; k++){

                        for(l=0; l<10; l++){

                            if(board[k][l][0].type == 'o'){

                                board[k][l][0].value++;
                                break;

                            }

                        }

                    }

                }

                else{

                    random_x_b = (rand() % 9) + 1;
                    random_y_b = (rand() % 9) + 1;

                    board[random_x_b][random_y_b][0].type = 'o'; 
                    board[random_x_b][random_y_b][0].value = (rand() % 3) + 1;                


                }

            }


}
