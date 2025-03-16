#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define STONE 1
#define PAPER 2
#define SCISSORS 3

void part1();
void part2();

int main(){

part1();
part2();

}

void part1(){
 
    char input,student;
    int choice, product_number;
    double price, total_price = 0, student_discount, additional_discount,vat;
    int i,j,k;

    FILE *menu;
    FILE *bill;

    /*opening menu for reading and bill for writing purposes*/
    menu = fopen("menu.txt","r");
    bill = fopen("bill.txt","w");

    /*Printing the menu*/
    printf("Yemek listesi:\n");
    for(i=0;i<=10;i++){ // with title it will read 11 lines

        /* it will ignore the first row in the menu cause there is no food name but the title */
        if(i != 0){
            printf("%d. ",i); // for each line except 0, it will print the number of the food
        }

        for(j=0;j<10;j++){ // this will read 10 character for each line so the prices will not be printed.

            input = fgetc(menu);

            /* don't print the first line cause there will be no food name but the title */  
            if(i != 0){

                printf("%c",input);

            }
        }

        /*after reading 10 characters and printing them, program will only read but not will print the input until the new line character*/

        while(input != '\n' && input != EOF){ 
            
            input = fgetc(menu);

        }
        
        if(i != 0){
            printf("%c",input); // in this part the input has \n so when we printed it will going to new line
        }
    }
    
    printf("\n");

    fclose(menu);
    printf("\n");

    /* Getting the current time and date and printing in bill.txt*/
    time_t date;
    time(&date);
    fprintf(bill,"20180000001\t\t\t%s\n",ctime(&date));

    fprintf(bill,"--------------------------------------------\n");

    menu = fopen("menu.txt","r");

    while(input != '\n'){

        input = fgetc(menu);
        fprintf(bill,"%c",input);

    }

    fprintf(bill,"--------------------------------------------\n\n");

    do{

        input = 'a';
        menu = fopen("menu.txt","r");

        printf("Please choose a product (1-10): ");
        scanf(" %d",&choice);
        printf("\n");

        printf("How many servings do you want: ");
        scanf(" %d",&product_number);
        printf("\n");

        /* Printing the number of product */
        if(product_number != 0 && product_number != 1){

            fprintf(bill,"%d* ",product_number);

        }

        /* Searching on the menu for wanting item */
        for (i = 0; i < choice; i++)
        {
            while(input != '\n' && input != EOF){ 
            
            input = fgetc(menu);

            }

            input = fgetc(menu); // it will read \n so a line will be read completely

        }

        /* Printing the wanted item on bill.txt */
        for(k=0 ; k<29 && product_number != 0;k++){ 
            
            fprintf(bill,"%c",input);
            input = fgetc(menu);

        }
 
        /* Reading the price */
        fscanf(menu,"%lf",&price);

        /* Printing price on the bill */
        if(product_number != 0 && product_number != 1){
            
            fprintf(bill,"%.2lf",price*product_number);

        }

        else if(product_number == 1){

            fprintf(bill,"   %.2lf",price);

        }

        if(product_number != 0){
            
            /* Calculating the total price */
            total_price = total_price + price*product_number;
            
            fprintf(bill,"\n\n");

        }

        fclose(menu);

    } while(product_number != 0);

    printf("Are you a Student: ");
    scanf(" %c",&student);

    while(student != 'Y' && student != 'N'){
        
        printf("Please enter a valid answer!\n");
        printf("Are you a Student: ");
        scanf(" %c",&student);
        printf("\n");
        
    }

    fprintf(bill,"Total:   \t\t\t%.2lf\n\n",total_price);

    /* Calculating student discount */
    if(student == 'Y'){

        student_discount = -(total_price * 125) / 1000;
        fprintf(bill,"Student discount   \t\t%.2lf\n\n",student_discount);

    }
    
    /* if total price is equal or bigger than 150 apply %10 discount*/
    if(total_price >= 150){

        additional_discount = -(total_price * 10) / 100;
        fprintf(bill,"additional discount:    \t%.2lf\n\n",additional_discount);

    }

    fprintf(bill,"--------------------------------------------\n\n");
    
    /* Calculating final price */
    if(total_price >= 150){

        total_price = total_price + additional_discount + student_discount;

    }

    else{

        total_price = total_price + student_discount;

    }

    /* calculating VAT */
    vat = (total_price * 18) / 100;

    /* printing total price */
    fprintf(bill,"Price:   \t\t\t%.2lf\n\n",total_price);

    /* printing final price including vat */
    fprintf(bill,"Price + VAT:     \t\t%.2lf\n\n",total_price + vat);

    /* displaying bill.txt on terminal */
    fclose(bill); // closing the bill.txt for writing purposes

    bill = fopen("bill.txt", "r"); // opening bill.txt for reading purposes

    input = 'a';

    while(input != EOF){

        input = fgetc(bill);
        printf("%c",input);

    }

    fclose(bill); // closing the bill.txt for reading purposes

}

void part2(){

    int human_choice, computer_choice;
    char play;

    do{

        /* Displaying the menu */
        printf("Please make a choice!\n");
        printf("1: Stone, 2: Paper, 3: Scissors\n");

        /* Getting choice from user */
        scanf("%d",&human_choice);
        printf("\n");

        srand(time(0)); // for generate different random number every time

        computer_choice = (rand() % 3) + 1; // to get a random number between 1-3

        switch(computer_choice){

            case STONE:
                if(human_choice == STONE){

                    printf("You chose Stone. I chose Stone. It's a tie!\n");

                }

                else if(human_choice == PAPER){

                    printf("You chose Paper. I chose Stone. You won!\n");

                }

                else if(human_choice == SCISSORS){

                    printf("You chose Scissors. I chose Stone. I won!\n");

                }
                break;

                case PAPER:
                if(human_choice == STONE){

                    printf("You chose Stone. I chose Paper. I won!\n");

                }

                else if(human_choice == PAPER){

                    printf("You chose Paper. I chose Paper. It's a tie!\n");

                }

                else if(human_choice == SCISSORS){

                    printf("You chose Scissors. I chose Paper. You won!\n");

                }
                break;

                case SCISSORS:
                if(human_choice == STONE){

                    printf("You chose Stone. I chose Scissors. You won!\n");

                }

                else if(human_choice == PAPER){

                    printf("You chose Paper. I chose Scissors. I won!\n");

                }

                else if(human_choice == SCISSORS){

                    printf("You chose Scissors. I chose Scissors. It's a tie!\n");

                }
                break;
        }

        printf("Do you want to play again? (Y/N): ");
        scanf(" %c",&play);

    } while(play == 'Y');


}