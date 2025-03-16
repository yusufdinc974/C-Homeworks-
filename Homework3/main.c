#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

void drawingwall(int roomsize);
void menu();

int main(){

	int roomsize, game_status = 0;
	char door = 'D', character = 'C', control_key;
	int door_x, door_y, character_x, character_y;
	int steps=0, escape_steps=0;
	int i,j;
	
	/* Determining room size */
	printf("Please enter room size between [5,10]: ");
	scanf("%d",&roomsize);
	printf("\n");
	
	/* Checking if the room size is valid */
	while(roomsize<5 || roomsize>10){
	
		printf("Invalid input. Please enter room size between [5,10]: ");
		scanf("%d",&roomsize);
		printf("\n");
	
	}
	
	srand(time(NULL));
	
	do{	
		/* Replacing the door with random number coordinates */
		door_x = rand()%roomsize+1;
		door_y = rand()%roomsize+1;
	
		/* Replacing the character with random number coordinates */
		character_x = rand()%roomsize+1;
		character_y = rand()%roomsize+1;
	
	} while((door_x == character_x) && (door_y == character_y));
	
	
	while(game_status == 0){
		/* Printing the upper wall */
		drawingwall(roomsize);
	
		/* Printing room */
		for(i = roomsize; i>0; i--){
	
			for(j = roomsize; j>0; j--){
		
				printf("|");
			
				if(j == door_x && i == door_y){
			
					printf("D");
			
				}
		
				else if(j == character_x && i == character_y){
			
					printf("C");
			
				}
		
				else{
			
					printf(" ");
				
				}
		
			}
		
			printf("|");
			printf("\n");
	
		}

		/* Printing the lower wall */
		drawingwall(roomsize);

		printf("Enter a control key [a,s,d,w]: ");
		scanf(" %c",&control_key);
	
		switch(control_key){
	
		case LEFT:
		character_x = character_x + 1;
		if(character_x > roomsize || character_x < 1){
		
			printf("You are trying to escape! Please don't do that.\n");
			character_x = character_x - 1;
			escape_steps ++;
		}
		break;
	
		case DOWN:
		character_y= character_y - 1;
		if(character_y > roomsize || character_y < 1){
		
			printf("You are trying to escape! Please don't do that.\n");
			character_y = character_y + 1;
			escape_steps ++;
		}
		steps ++;
		break;
	
		case RIGHT:
		character_x = character_x - 1;
		if(character_x > roomsize || character_x < 1){
		
			printf("You are trying to escape! Please don't do that.\n");
			character_x = character_x + 1;
			escape_steps ++;
		}
		steps ++;
		break;
	
		case UP:
		character_y = character_y + 1;
		if(character_y > roomsize || character_y < 1){
		
			printf("You are trying to escape! Please don't do that.\n");
			character_y = character_y - 1;
			escape_steps ++;
		}
		steps ++;
		break;
	
		}
		
		if((door_x == character_x) && (door_y == character_y)){
			
			for(i = roomsize; i>0; i--){
	
			for(j = roomsize; j>0; j--){
		
				printf("|");
			
				if(j == door_x && i == door_y){
			
					printf("*");
			
				}
		
				else{
			
					printf(" ");
				
				}
		
			}
		
			printf("|");
			printf("\n");
	
		}
			
			printf("\n!!!! YOU WON !!!!\n\n");
			printf("You completed the game with %d steps and you tried to escape %d times.\n\n",steps, escape_steps);
			game_status = 1;
			menu();
		
		}
		

	}

}

void drawingwall(int roomsize){
	
	int wallsize;
	int i;

	/* Calculating wall size by using room size */
	wallsize = roomsize*2 + 1;
	
	/* Printing the wall */
	for(i = wallsize; i>0; i--){
		
		printf("-");
	
		
	}
	
	printf("\n");

}

void menu(){

	int choice;
	
	/* Printing the menu */
	printf("Welcome to the 2D puzzle game!\n");
	printf("1. New Game\n");
	printf("2. Help\n");
	printf("3. Exit\n");

	scanf("%d",&choice);

	/* Making options in menu */	
	switch(choice){
	
	case 1:
	main();
	break;
	
	case 2:
	printf("------------- GAMEPLAY -----------------\n");
	printf("The character is able to move one space in any of the four cardinal directions: up, down, left, and right. Diagonal moves are not allowed. The user will input their desired move using the following keys: 'a' for left, 'd' for right, 'w' for up, and 's' for down. These moves should be defined at the beginning of the codewith  direction  names  as  the  keys.Any  control  or  selection  with  [a,  d,  w,  s]  characters will  result  in  a missgrading. The game will prompt the user for a new move after each move is made until the game is over.\n\n");
	printf("The current state of the room should be printed after each move, except when the character reaches the door.  If  the  character  attempts  to  move  through  a  wall,  a  warning  message  should  be  displayed.  The game ends when the character reaches the door, and a message should be displayed to notify the user that the game is over and how many moves were made during the game.\n\n");
	menu();
	break;
	
	case 3:
	exit(0);	
	break;
	}
}

