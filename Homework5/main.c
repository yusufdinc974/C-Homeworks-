#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Defining new type named color for part2 */
typedef enum{RED,GREEN,BLUE,YELLOW,ORANGE} color; 

void part1();
void part2();
void part3();
void board_display(char board[3][3]);
int win_check(char board[3][3], char player_symbol, int player_number);
void player_choice(char board[3][3], char player_symbol, int player_number);
color determine_color(char color);
color color_maker(color color1, color color2);
void colorMixer(color color1, color color2, color (*fun_pnt)(color, color));


int main(){

    part1();
    part2();
    part3();

}

void part1(){

    char input, character = 65, file_name[64];
    int alphabet[26];
    int i;

    FILE *file;

    /* Getting file name from user */
    printf("Enter the file name: ");
    scanf("%s",file_name);
    printf("\n");
   
    /* Opening the file for reading purposes */
    file = fopen(("%s",file_name),"r");

    /* initializing the terms of array as 0 */
    for(i=0 ; i<26; i++){

        alphabet[i] = 0;

    }

    while(input != EOF){ //read until end of the file

        input = fgetc(file);

        if(input != ' ' && input != '\n'){

            /* Since array is 0 up to 25, substract the letters ascii number from A/a and base them 0. So the new A/a will be 0 in ascii and it will match with alphabet array in order. */

            if(input >= 97 && input <= 122){ // if the letter is lower case

                alphabet[input - 97]++;

            }

            else if(input >= 65 && input <= 90){ // if the letter is upper case

                alphabet[input - 65]++;

            }

        }

    }

    printf("Letter Frequency:\n");

    /* Displaying characters and their frequency */
    for(i=0 ; i<26 ; i++){

        printf("%c: %d\n",character,alphabet[i]);
        character++;

    }

    fclose(file);

}

void part2(){

    color color1, color2, new_color;
    char temp1, temp2;
    double vector1[3], vector2[3];

    /* Getting first color from the user */
    printf("Enter Color 1 (r,g,b,y,o): ");
    scanf(" %c",&temp1);
    printf("\n");

    color1 = determine_color(temp1);

    /* Getting second color from the user */
    printf("Enter Color 2 (r,g,b,y,o): ");
    scanf(" %c",&temp2);
    printf("\n");

    color2 = determine_color(temp2);

    /* making the new color */
    colorMixer(color1,color2,&color_maker);

}

color determine_color(char color){

    switch(color){

        case 'r':
        return RED;
        break;

        case 'g':
        return GREEN;
        break;

        case 'b':
        return BLUE;
        break;

        case 'y':
        return YELLOW;
        break;

        case 'o':
        return ORANGE;
        break;

    }

}

color color_maker(color color1, color color2){

    double vector1[3], vector2[3], new_vector[3];
    int i, counter=0;
    double distance_red, distance_green, distance_blue, distance_yellow, distance_orange;
    double closest_color_distance = 1000;

    /* Determening the vectors of the colors */
    switch(color1){

    case RED:
        vector1[0] = 1;
        vector1[1] = 0;
        vector1[2] = 0;
    break;

    case GREEN:
        vector1[0] = 0;
        vector1[1] = 1;
        vector1[2] = 0;
    break;

    case BLUE:
        vector1[0] = 0;
        vector1[1] = 0;
        vector1[2] = 1;
    break;

    case YELLOW:
        vector1[0] = 0.5;
        vector1[1] = 0.5;
        vector1[2] = 0;
    break;

    case ORANGE:
        vector1[0] = 0.5;
        vector1[1] = 0.4;
        vector1[2] = 0.2;
    break;

    }

    switch(color2){

    case RED:
        vector2[0] = 1;
        vector2[1] = 0;
        vector2[2] = 0;
    break;

    case GREEN:
        vector2[0] = 0;
        vector2[1] = 1;
        vector2[2] = 0;
    break;

    case BLUE:
        vector2[0] = 0;
        vector2[1] = 0;
        vector2[2] = 1;
    break;

    case YELLOW:
        vector2[0] = 0.5;
        vector2[1] = 0.5;
        vector2[2] = 0;
    break;

    case ORANGE:
        vector2[0] = 0.5;
        vector2[1] = 0.4;
        vector2[2] = 0.2;
    break;

    }

    /* giving the values to the new array for new color */
    for(i=0; i<3; i++){

        new_vector[i] = (vector1[i] + vector2[i]) / 2;

    }

    /* determining the which color is closest to the new color */
    distance_red = sqrt(pow((new_vector[0] - 1),2) + pow((new_vector[1] - 0),2) + pow((new_vector[2] - 0),2));
    distance_green = sqrt(pow((new_vector[0] - 0),2) + pow((new_vector[1] - 1),2) + pow((new_vector[2] - 0),2));
    distance_blue = sqrt(pow((new_vector[0] - 0),2) + pow((new_vector[1] - 0),2) + pow((new_vector[2] - 1),2));
    distance_yellow = sqrt(pow((new_vector[0] - 0.5),2) + pow((new_vector[1] - 0.5),2) + pow((new_vector[2] - 0),2));
    distance_orange = sqrt(pow((new_vector[0] - 0.5),2) + pow((new_vector[1] - 0.4),2) + pow((new_vector[2] - 0.2),2));

    double distance_array[5] = {distance_red, distance_green, distance_blue, distance_yellow, distance_orange};

    for(i=0; i<5; i++){

        if(closest_color_distance>distance_array[i]){

            closest_color_distance = distance_array[i];
            counter = i;

        }

    }

    switch (counter){

    case 0:
    return RED;
    break;

    case 1:
    return GREEN;
    break;

    case 2:
    return BLUE;
    break;

    case 3:
    return YELLOW;
    break;

    case 4:
    return ORANGE;
    break;
    
    
    }
    
}

void colorMixer(color color1, color color2, color (*fun_pnt)(color, color)){

    color new_color = fun_pnt(color1,color2);

    switch(new_color){

        case RED:
        printf("Mixed color: RED [1,0,0]\n");
        break;

        case GREEN:
        printf("Mixed color: GREEN [0,1,0]\n");
        break;

        case BLUE:
        printf("Mixed color: BLUE [0,0,1]\n");
        break;

        case YELLOW:
        printf("Mixed color: YELLOW [0.5,0.5,0]\n");
        break;

        case ORANGE:
        printf("Mixed color: ORANGE [0.5,0.4,0.2]\n");
        break;

    }

}

void part3(){

    char board[3][3];
    char player_symbol;
    int player_number;
    int i, j;

    /* initializing all elements as "_" */
    for(i=0 ; i<3 ; i++){

        for(j=0 ; j<3 ; j++){

            board[i][j] = '_';

        }

    }

    while(1){
        
        player_number = 1;
        player_symbol = 'X';

        /* Getting first player's choice */
        player_choice(board, player_symbol, player_number);

        board_display(board);

        win_check(board, player_symbol, player_number);

        player_number = 2;
        player_symbol = 'O';

        /* Getting second player's choice */
        player_choice(board, player_symbol, player_number);

        board_display(board);

        win_check(board, player_symbol, player_number);        

    }

}

void board_display(char board[3][3]){

    int i,j;
        
    for(i=0 ; i<3 ; i++){

        for(j=0 ; j<3 ; j++){

            printf("%c ",board[i][j]);

        }

        printf("\n");

    }
    
    printf("\n");

}

int win_check(char board[3][3], char player_symbol, int player_number){

    int i, j;
    char play_again;

    for(i=0; i<3; i++){

        if(    (board[i][0] == ("%c",player_symbol) && board[i][1] == ("%c",player_symbol) && board[i][2] == ("%c",player_symbol)) || // checking the rows
               (board[0][i] == ("%c",player_symbol) && board[1][i] == ("%c",player_symbol) && board[2][i] == ("%c",player_symbol)) || // checking the coloumns
               (board[0][0] == ("%c",player_symbol) && board[1][1] == ("%c",player_symbol) && board[2][2] == ("%c",player_symbol)) || // checking the leftop to rightbottom
               (board[2][0] == ("%c",player_symbol) && board[1][1] == ("%c",player_symbol) && board[0][2] == ("%c",player_symbol)) ){ // checking the leftbottom to righttop

                printf("Player %d (%c) Wins !\n",player_number,player_symbol);
                
                /* Asking the user if he/she wants to play again */
                printf("Do you want to play again (Y/N): ");
                scanf(" %c",&play_again);

                if(play_again == 'Y'){

                    part3(); // if yes repeat the whole proccess

                }

                else{

                    exit(0); // if no exit

                }

        }

    }

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            if(board[i][j] == '_'){

                return 0;

            }
            
        }

    }

    printf("No one won. It is a draw!\n");

    /* Asking the user if he/she wants to play again */
    printf("Do you want to play again (Y/N): ");
    scanf(" %c",&play_again);

    if(play_again == 'Y'){

        part3(); // if yes repeat the whole proccess

    }

    else{

        exit(0); // if no exit

    }




}

void player_choice(char board[3][3], char player_symbol, int player_number){

    int row, col;   
    int i, j; 

    printf("Player %d (%c), enter your move (row, col): ",player_number,player_symbol);
    scanf("%d%d",&row, &col);

    for(i=0 ; i<3; i++){

        for(j=0 ; j<3; j++){

            if(row == i && col == j){

                if(board[i][j] == 'X' || board[i][j] == 'O'){

                    printf("It is already marked there. Try different place.\n");
                    player_choice(board, player_symbol, player_number);

                }    
                    
                else{    
                    
                    board[i][j] = ("%c",player_symbol);

                }

            }

            else if(board[i][j] != 'O' && board[i][j] != 'X' ){

                board[i][j] = '_';

            }

        }

    }


}
