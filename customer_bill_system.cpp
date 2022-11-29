#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************
							CUSTOMER BILLING SYSTEM
************************************************************************************************/
/*	THIS PROGRAM CONTAINS BILLING SYSTEM FOR RESTAURANT		AUTOR: DAVOR BILIC	   */


//static double price = 0;		// global variable for price (this variable can be translated to the function
								// ordering, because it is static, and it will be better

void question_form(int* pick){
	int temp;													// temporary variable which will store 
	printf("Are you a guest or restaurant employee ? \n");		// value of function argument (pointer)
	printf("1. Guest		2. Employee \n");
	scanf("%d", &temp);
	
	*pick = temp;
}
void menu_list(){
	printf("********************************************* \n");
	printf("*	  THIS IS MENU	                    * \n");
	printf("********************************************* \n");
	printf("\n");
	printf("ITEMS:                       PRICES: \n");
	printf("---------------------------------------------- \n");
	printf("1.  coffe with milk          1.25 euro \n");
	printf("2.  coffe without milk       1 euro \n");
	printf("3.  coca cola                2 euro \n");
	printf("4.  fanta                    2 euro \n");
	printf("5.  juice                    2 euro \n");
	printf("6.  standard sandwich        2.5 euro \n");
	printf("7.  hot dog                  3 euro \n");
	printf("8.  donut                    1 euro \n");
	printf("9.  standard omelette        4 euro \n");
	printf("10. omelette with bacon      5 euro \n");
	printf("11. small pizza              5 euro \n");
	printf("12. medium pizza             8 euro \n");
	printf("13. large pizza              12 euro \n");
	printf("14. jumbo pizza              15 euro \n");
	printf("15. EXIT MENU \n");
	printf("\n");
	printf("********************************************** \n");
}
void ordering(){
	int item, amount;
	char m;
	static double price = 0;
	
jump1:											// section for ordering from menu
	printf("\n");
	printf("Pick an item that you want order (press number 1 - 15) : ");
	scanf("%d", &item);
	
	if(item == 15){								// if user types 15 it means that he/she want to exit 
		printf("\n");
		printf("Thank you and goodbye !! \n");
		exit(1);
	}
	else if(item < 0 && item > 15){				// if case for typing not allowed value
		printf("You typed wrong value ! \n");
		exit(1);
	}
	
	printf("Pick amount of that item : ");		// when the right item is finally picked, user must choose
	scanf("%d", &amount);						// amount of that item
	
	// LIST OF ITEMS MULTIPLYING WITH PRICE TO GET FINAL PRICE
	if(item == 1){
		price += amount * 1.25;
	}
	else if(item == 2 || item == 8){
		price += amount * 1.0;
	}
	else if(item == 3 || item == 4 || item == 5){
		price += amount * 1.0;
	}
	else if(item == 6){
		price += amount * 2.5;
	}
	else if(item == 7){
		price += amount * 3.0;
	}
	else if(item == 9){
		price += amount * 4.0;
	}
	else if(item == 10 || item == 11){
		price += amount * 5.0;
	}
	else if(item == 12){
		price += amount * 8.0;
	}
	else if(item == 13){
		price += amount * 12.0;
	}
	else if(item == 14){
		price += amount * 15.0;
	}
	
	printf("\n");	
	printf("Do you want something else ? \n");		// once user has picked item and its amount, he/she is asked does he/she
	printf("a) YES   b) NO \n");					// want another item
	scanf("%s", &m);
	
	switch(m){
		case 'a':									// if user wants another item, program goes to jump section above this
			goto jump1;
			break;
			
		case 'b':
			break;
			
		default:
			printf("You typed wrong value ! \n");
			break;	
	}
	
	printf("\n");
	printf("Your price is : %.2lf euro. \n", price);
}
void password(){
	char pwd[] = {"iamtheemployee123"};			// setting the password
	char pwd_try[20];
	int res;
	int count = 0;						// variable which counts number of password attempts 

jump2:											// section for password
	printf("PASSWORD: \n");
	scanf("%s", &pwd_try);						// scanning the password from the keyboard

	res = strcmp(pwd, pwd_try);					// function to compare two strings... if strings are equal it will return zero
												// otherwise it will return non-zero value
	if(res == 0){
		printf("CORRECT PASSWORD !! \n");
	} 
	else{
		printf("\n");
		printf("INCORRECT PASSWORD !! \n");

		count++;
		
		if(count == 3){
			printf("\n");
			printf("You have entered the wrong password 3 times, so the program has been terminated !! \n");
			exit(1);								// if user write password 3 times incorrect, the program terminates
		}
		printf("Try again !! \n");
		printf("\n");
		goto jump2;								// if password isn't correct, the program will go to jump2 section
	}	
}
void guest_database(){
	char fn[15], ln[15], pn[15];
	double pr;
	FILE* fp;
	

	fp = fopen("user_base.txt", "a");					// opening the file
		
	if(fp == NULL) {			
		printf("Error opening file !! \n");				// checking if there is error	
		exit(1);
		}
	
	fflush(stdin);										// clearing the buffer			
	
	printf("\n");	
	printf("Insert first name: \n");
	scanf("%s", &fn);
	printf("Insert last name: \n");
	scanf("%s", &ln);
	printf("Insert the phone number: \n");
	scanf("%s", &pn);
	printf("Insert the last amount paid: \n");
	scanf("%lf", &pr);
		
	fprintf(fp, "	CUSTOMER \n");						// writing in the file	
	fprintf(fp, "---------------------- \n");			// writing in the file
	fprintf(fp, "First name: %s \n", fn);				// writing in the file				
	fprintf(fp, "Last name:	%s \n", ln);				// writing in the file
	fprintf(fp, "Phone number: %s \n", pn);				// writing in the file		
	fprintf(fp, "Amount of debt: %.2lf euro\n", pr);	// writing in the file
	fprintf(fp, "\n");									// writing in the file
	
	fclose(fp);											// closing the file	
}

int main(){
	int a;									// value whose address will be send to function question_form
	
	system("cls");							// clearing the screeen
	question_form(&a);						// calling a function for picking guest/employee form
	
	if(a == 1){
		system("cls");						// clearing the screeen
		menu_list();						// calling a function for menu list
		ordering();							// calling a function for ordering	
	}
	else if(a == 2){
		system("cls");						// clearing the screeen
		password();							// calling a function for password
		guest_database();					// calling a function for writing in data file
	}
	else{
		printf("You typed the wrong value ! \n");
	}
	
}
