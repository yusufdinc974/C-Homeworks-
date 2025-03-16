#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/* Defining a struct named board */
typedef struct board
{
    
    int arr[3][3];
    int space_x;
    int space_y;
    int move_x;
    int move_y;

} board;

void play_game_as_user(board game, FILE *state, FILE *score, int move_counter);
void solve_with_computer(board game, FILE *state, FILE *score, int move_counter);
void displaying_state(board game);
void writing_state_to_txt(board game, FILE *state);
void show_best_score(FILE *score);

int main(){

    FILE *score;
    FILE *state;

    board game;

    score = fopen("best_score.txt","a+");
    state = fopen("state_of_board.txt","a");
    
    int choice, i, j, r ,c ,temp, d = 1, move_counter = 0;

    /*Creating the board within order 1-8 and mixing it*/
    
    srand(time(NULL)); // to generate different random number 

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            game.arr[i][j] = d;
            d++;

        }

    }

    for (i = 2; i > 0; i--){
        
        for (j = 2; j > 0; j--){
            
            r = rand() % (i + 1);
            c = rand() % (j + 1);
            temp = game.arr[i][j];
            game.arr[i][j] = game.arr[r][c];
            game.arr[r][c] = temp;
        
        }
   
    }

    /* Displaying the menu */

    printf("Welcome to the 8-Puzzle Game!\n");
    printf("Please select an option:\n");
    printf("1. Play game as a user\n");
    printf("2. Finish the game with PC\n");
    printf("3. Show the best score\n");
    printf("4. Exit\n");

    scanf("%d",&choice);

    switch(choice){

        case 1:
        writing_state_to_txt(game,state);
        play_game_as_user(game, state, score, move_counter);
        main();
        break;

        case 2:
        writing_state_to_txt(game,state);
        solve_with_computer(game,state,score,move_counter);
        main();
        break;

        case 3:
        show_best_score(score);
        main();
        break;

        case 4:
        printf("Program terminated...\n");
        exit(0);
        break;


    }


}

void play_game_as_user(board game, FILE *state, FILE *score, int move_counter){

    int i, j, temp, r, c, d=1, temp_x, temp_y;
    char buffer, direction;
    int move;
    int win[3][3];

    /* creating an another array that in order 1-8. It will be used for comparison if the game is win or not */

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            win[i][j] = d;
            d++;

        }

    }

    while(game.arr != win){ //until game is win


        displaying_state(game); //displaying the inital board

        printf("Enter your move (number-direction, e.g., 2-R): ");
        scanf("%d%c%c",&move, &buffer, &direction);

        /* taking coordinates of the number we are going to play and the "_" symbol we are going to comparison with*/
        
        for(i=0; i<3; i++){

            for(j=0; j<3; j++){

                if(game.arr[i][j] == move){

                    game.move_x = j;
                    game.move_y = i;

                }

                else if(game.arr[i][j] == 9){

                    game.space_x = j;
                    game.space_y = i;

                }

            }

        }
        
        switch(direction){

            case 'D':
                
                /* If it's an valid move, change the number you moved and the "_" symbol. If it's an invalid move, give warning and redo the process and do it for every four direction */

                if((game.move_y + 1 == game.space_y) && (game.move_x == game.space_x)){

                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    play_game_as_user(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    printf("Invalid move\n");
                    break;

                }

            case 'U':

                if((game.move_y - 1 == game.space_y) && (game.move_x == game.space_x)){

                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    play_game_as_user(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    printf("Invalid move\n");
                    break;

                }

            case 'R':

                if((game.move_y == game.space_y) && (game.move_x + 1 == game.space_x)){

                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    play_game_as_user(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    printf("Invalid move\n");
                    break;

                }

            case 'L':

                if((game.move_y == game.space_y) && (game.move_x - 1 == game.space_x)){

                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    play_game_as_user(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    printf("Invalid move\n");
                    break;

                }

        }


    }

    fprintf(state,"\n\n\n");
    printf("Congratulations! You finished the game!!\n");
    printf("Total number of the moves: %d\n",move_counter);
    printf("Your score: %d\n",(1000-10*move_counter));
    fprintf(score,"%d\n",(1000-10*move_counter));

}

void displaying_state(board game){

    int i, j;
   
    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            if(game.arr[i][j] == 9){

                printf("_ ");

            }

            else{

                printf("%d ",game.arr[i][j]);

            }


        }

        printf("\n");

    }

    printf("\n");

}

void writing_state_to_txt(board game, FILE *state){

    int i, j;

    fseek(state,SEEK_END,0);

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            if(game.arr[i][j] == 9){

                fprintf(state,"_ ");

            }

            else{

                fprintf(state,"%d ",game.arr[i][j]);

            }


        }

        fprintf(state,"\n");

    }

    fprintf(state,"\n");

}

void show_best_score(FILE *score){

    int temp, best_score=0;

    while(feof(score) == 0){
   
        fscanf(score,"%d",&temp);

        if(temp > best_score){

            best_score = temp;

        }

    }

    printf("Best Score: %d\n",best_score);

}

void solve_with_computer(board game, FILE *state, FILE *score, int move_counter){

    int i, j, temp, r, c, d=1, temp_x, temp_y;
    int move;
    int win[3][3];
    char direction_arr[4] = {'U','D','R','L'};
    int direction_numb;
    char direction, last_move;

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            win[i][j] = d;
            d++;

        }

    }

    while(game.arr != win){

        /* The only difference between this and solve with user is, in this part computer generates a random number for move. Also there is an array includes every four direction. Computer generates a random number between 0-3 and it choose the direction with that number. */
        
        move = (rand() % 8) + 1;

        direction_numb = (rand() % 4);
        direction = direction_arr[direction_numb];


        for(i=0; i<3; i++){

            for(j=0; j<3; j++){

                if(game.arr[i][j] == move){

                    game.move_x = j;
                    game.move_y = i;

                }

                else if(game.arr[i][j] == 9){

                    game.space_x = j;
                    game.space_y = i;

                }

            }

        }

        switch(direction){

            case 'D':
                
                if((game.move_y + 1 == game.space_y) && (game.move_x == game.space_x) && (last_move != 'U')){

                    displaying_state(game);
                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    last_move = 'D';
                    solve_with_computer(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    solve_with_computer(game,state,score,move_counter);
                    break;

                }

            case 'U':

                if((game.move_y - 1 == game.space_y) && (game.move_x == game.space_x) && (last_move != 'D')){

                    displaying_state(game);
                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    last_move = 'U';
                    solve_with_computer(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    solve_with_computer(game,state,score,move_counter);
                    break;

                }

            case 'R':

                if((game.move_y == game.space_y) && (game.move_x + 1 == game.space_x) && (last_move != 'L')){

                    displaying_state(game);
                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    last_move = 'R';
                    solve_with_computer(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    solve_with_computer(game,state,score,move_counter);
                    break;

                }

            case 'L':

                if((game.move_y == game.space_y) && (game.move_x - 1 == game.space_x) && (last_move != 'R')){

                    displaying_state(game);
                    temp = game.arr[game.move_y][game.move_x];
                    game.arr[game.move_y][game.move_x] = game.arr[game.space_y][game.space_x];
                    game.arr[game.space_y][game.space_x] = temp;
                    writing_state_to_txt(game,state);
                    move_counter++;
                    last_move = 'L';
                    solve_with_computer(game,state,score,move_counter);
                    break;
                    

                }

                else{

                    solve_with_computer(game,state,score,move_counter);
                    break;

                }

        }


    }

    fprintf(state,"\n\n\n");
    printf("Congratulations! You finished the game!!\n");
    printf("Total number of the moves: %d\n",move_counter);
    printf("Your score: %d\n",(1000-10*move_counter));
    fprintf(score,"%d\n",(1000-10*move_counter));
   

}