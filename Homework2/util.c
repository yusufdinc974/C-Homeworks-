#include <stdio.h>
#include "util.h"
#include <math.h>

double factorial(double number){

	if(number == 0){
	
		return 1;
		
	}
	
	else{
	
		return number * factorial(number-1);
	
	}
}


void part1(){

	int inputyear;
	
	/* Getting the year from the user to check if it is a leap year or not  */	
	printf("*****************************************************\n");
	printf("Please enter the year you want to check: ");
	scanf("%d",&inputyear);
	printf("\n");
	
	/* Checking the year if it is a leap year */
	if(inputyear % 4 == 0){
	
		printf("%d is a leap year\n", inputyear);
	
	}
	
	else{
	
		printf("%d is not a leap year\n", inputyear);	
	
	}
	
}

void part2(){

	char format,operation;	
	double operand1, operand2;
	int m,n;
	
	/* Getting the type of the format from user */
	printf("******************************\n");
	printf("Enter the format of output (S or I): ");
	scanf("%c",&format);
	printf("\n");
	
	if(format == 'S'){
	
		printf("Enter m and n values: ");
		scanf("%d%d", &m, &n);
		printf("\n");
	
		while(n>m){
		
			printf("n can't be more than m. PLease enter valid values for m and n: ");
			scanf("%d%d", &m, &n);
			printf("\n");
		}
	
	}
	
	/* Getting the operation and two operands from user */
	printf("Enter the operation (+,-,/,*,%%,!,^): ");
	scanf(" %c",&operation);
	printf("\n");
	
	printf("Enter the first operand: ");
	scanf("%lf",&operand1);
	printf("\n");
	
	if(operation == '!'){
	
		printf("%lf! = %lf\n",operand1, factorial(operand1));
	
	}
	
	else{
		printf("Enter the second operand: ");
		scanf("%lf",&operand2);
		printf("\n");
	
		/* Selecting operation by using switch-case*/
		switch(operation){
	
		case '+':
		printf("%d + %d = %d\n",(int)operand1,(int)operand2,(int)operand1+(int)operand2);
		break;
		
		case '-':
		printf("%d - %d = %d\n",(int)operand1,(int)operand2,(int)operand1-(int)operand2);
		break;
		
		case '*':
		printf("%d * %d = %d\n",(int)operand1,(int)operand2,(int)operand1*(int)operand2);
		break;
		
		case '/':
		printf("%d / %d = %d\n",(int)operand1,(int)operand2,(int)operand1/(int)operand2);
		break;
		
		case '%':
		printf("%d %% %d = %d\n",(int)operand1,(int)operand2,(int)operand1%(int)operand2);
		break;
		
		case '^':
		printf("%d ^ %d = %d\n",(int)operand1,(int)operand2,(int)pow(operand1,operand2));
		break;
		
		default:
		printf("You entered an invalid operator.\n");
		break;
		}
	}
	
}

void part3(){

	int exam1, exam2, exam3, assignment1, assignment2;
	double finalgrade;
	
	/* Getting the exam grades from user */
	printf("********************************\n");
	printf("Enter 3 exam grades of student: ");
	scanf("%d%d%d",&exam1,&exam2,&exam3);
	printf("\n");
	
	/* Getting the assignment grades from user */
	printf("Enter 2 assignment grades of student: ");
	scanf("%d%d",&assignment1,&assignment2);
	printf("\n");
	
	/* Calculating the final note */
	finalgrade = (exam1 + exam2 + exam3) / 3 * 0.6 + (assignment1 + assignment2) / 2 * 0.4;
	
	/* Printing if user passed or failed */
	if(finalgrade >= 60 && finalgrade <= 100){
	
		printf("Final Grade: %.1lf Passed!\n",finalgrade);
	
	}
	
	else if(finalgrade < 60 && finalgrade >= 0){
	
		printf("Final Grade: %.1lf Failed!\n",finalgrade);
	
	}	
	
	else{
	
		printf("You entered invalid grades.");
	
	}
}

