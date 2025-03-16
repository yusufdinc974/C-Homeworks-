#include "util.h"
#include <stdio.h>
#include <stdlib.h>

void part1(){

	int gcd,input1,input2;
	int temp1,temp2;	
		
	/* Getting first integer from user */
	printf("Please enter the first integer: ");
	scanf("%d",&input1);
	printf("\n");

	/* Getting second integer from user */
	printf("Please enter the second integer: ");
	scanf("%d",&input2);
	printf("\n");

	/* Saving input1 and input2 for reusage */
	temp1 = input1;
	temp2 = input2;

	while(input1 != 0 && input2 != 0){
	
		if(input1 > input2){
		
			input1 = input1 % input2;	
		
		}
		
		else if(input2 > input1){
		
			input2 = input2 % input1;
		
		}
		
	
	}


	if(input1 == 0){
	
		gcd = input2;
	
	}
	
	else{
	
		gcd = input1;
	
	}

	printf("The great common divisor of %d and %d is %d.\n",temp1,temp2,gcd);
	
}


void part2(){
	
	int numb1, numb2;
	
	/* Getting first number from user */
	printf("First number : ");
	scanf("%d",&numb1);
	printf("\n");

	/* Getting second number from user */
	printf("Second number : ");
	scanf("%d",&numb2);
	printf("\n");

	printf("Result:\n");
	printf("\t%4d\n",numb1);
	printf("\t%4d\n",numb2);
	printf("      +\n");
	printf("      %6s\n","------");
	printf("       %5d\n",numb1+numb2);

}


void part3(){
	
	int numb1, numb2;
	int stepnumber;
	
	/* Getting first number from user */
	printf("First number : ");
	scanf("%d",&numb1);
	printf("\n");

	/* Getting second number from user */
	printf("Second number : ");
	scanf("%d",&numb2);
	printf("\n");
	
	/* Determining how many there will be addition steps in multiplicition */
	if((abs(numb2) < 10) && (abs(numb2) >= 0)){
	
		stepnumber = 1;
	
	}
	
	else if((abs(numb2) < 100) && (abs(numb2) >= 10)){
	
		stepnumber = 2;
	
	}
	
	else if((abs(numb2) < 1000) && (abs(numb2) >= 100)){
	
		stepnumber = 3;
	
	}
	
	printf("%d\n",stepnumber);
	
	/* Printing numbers and calculatig line */
	printf("Result:\n");
	printf("\t%3d\n",numb1);
	printf("\t%3d\n",numb2);
	printf("  *\n");
	printf("  %9s\n","---------");
	
	/* Calculating and printing the first step */
	printf("       %4d\n",numb1*(numb2%10));
	
	/* Calculating and printing the second step */
	if(numb1*((numb2%100)/10) != 0){	
		
		printf("      %4d0\n",numb1*((numb2%100)/10));
	
	}
	
	else if(stepnumber != 1){

		printf("      %4s\n","000");
	
	}
	
	
	/* Calculating and printing the second step */
	if(numb1*((numb2/100) != 0)){	
		
		printf("     %4d00\n",numb1*(numb2/100));
	
	}
	
	else if(stepnumber != 1 && stepnumber != 2){
			
		printf("      %4s\n","000");
	
	}
	
	/* Printing the final addition line and conclusion*/
	if(stepnumber == 2 || stepnumber == 3){
		
		printf("  +\n");
		printf("  %9s\n","---------");
		printf("     %6d\n",numb1*numb2);
	
	}
}

void part4(){

	int input;
	
	/* Getting a integer from user */
	printf("Please enter a integer between 1 and 10 'inclusive': ");
	scanf("%d",&input);
	printf("\n");
	
	if(input<=5 && input>=1){
	
		printf("The integer you entered is less than or equal to 5\n");
	
	}
	
	else if(input>5 && input<=10){
	
		printf("The integer you entered is greater than 5\n");
	
	}

	else{
	
		printf("invalid input\n");
	
	}







}
