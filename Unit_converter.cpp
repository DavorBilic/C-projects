#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*****************************************************************************************************/
								/* UNIT CONVERTER */ 
/******************************************************************************************************
THIS PROGRAM CONTAINS A SIMPLE UNIT CONVERTER. YOU CAN PUT THE VALUE REPRESENTED IN ONE UNIT, AND 
CONVERT IT IN ANOTHER UNIT. UNITS IN THIS PROGRAM ARE: DISTANCE, TEMPERATURE AND MASS
******************************************************************************************************/
/*																AUTOR: DAVOR BILIC			*/

void distance() {
	int a;
	double b, mile_res, km_res;
	
	system("cls");
	printf("Choose unit which you want to convert: \n");
	printf("1. Mile to kilometer \n");
	printf("2. Kilometer to mile \n");
	scanf("%d", &a);					
	
	switch(a){
		case 1:
			printf("How much miles you want to convert ? \n");
			scanf("%lf", &b);											// scanning the value to convert
			mile_res = b * 1.609344;									// 1 mile = 1.609344 km
			printf("%.3lf miles is %.3lf kilometers \n", b, mile_res);		
			break;
			
		case 2:
			printf("How much kilometers you want to convert ? \n");
			scanf("%lf", &b);											// scanning the value to convert
			km_res = b / 1.609344;									// 1 mile = 1.609344 km
			printf("%.3lf kilometers is %.3lf miles \n", b, km_res);		// printing the values
			break;
			
		default:
			printf("You typed the wrong value !!");						// if user type different value from 1 or 2
			break;
	}	
}
void temperature(){
	int c, d;
	double e, res11, res12, res13, res14;
	
	system("cls");						// clearing the screen content
	
	printf("Choose unit which you want to convert: \n");
	printf("1. Celsius \n");
	printf("2. Kelvin \n");
	printf("3. Fahrenheit \n");
	scanf("%d", &c);				
	
	printf("Choose unit to which you want to convert: \n");
	printf("1. Celsius \n");
	printf("2. Kelvin \n");
	printf("3. Fahrenheit \n");
	scanf("%d", &d);					
	
	printf("Insert amount: \n");
	scanf("%lf", &e);
	
	if(c == 1 && d == 1){				// converting celsius to celsius
		printf("%.3lf celsius is %.3lf celsius \n", e, e);
	}
	else if(c == 1 && d == 2){			// converting celsius to kelvin
		res11 = e + 273.15;				
		printf("%.3lf celsius is %.3lf kelvin \n", e, res11);
	}
	else if(c == 1 && d == 3){			// converting celsius to fahrenheit
		res12 = e * (9 / 5) + 32 ;				
		printf("%.3lf celsius is %.3lf fahrenheit \n", e, res12);
	}
	else if(c == 2 && d == 1){			// converting kelvin to celsius
		res13 = e - 273.15;				
		printf("%.3lf kelvin is %.3lf celsius \n", e, res13);
	}
	else if(c == 2 && d == 2){			// converting kelvin to kelvin				
		printf("%.3lf kelvin is %.3lf kelvin \n", e, e);
	}	
	else if(c == 2 && d == 3){			// converting kelvin to fahrenheit
		res14 = 1.8 * (e - 273.15) + 32;				
		printf("%.3lf kelvin is %.3lf fahrenheit \n", e, res14);
	}
	else if(c == 3 && d == 1){			// converting fahrenheit to celsius
		res14 = (e - 32) * (5 / 9);				
		printf("%.3lf fahrenheit is %.3lf celsius \n", e, res14);
	}
	else if(c == 3 && d == 2){			// converting fahrenheit to kelvin
		res14 = (e - 32) / 1.8 + 273.15;				
		printf("%.3lf fahrenheit is %.3lf kelvin \n", e, res14);
	}
	else if(c == 3 && d == 3){			// converting fahrenheit to fahrenheit			
		printf("%.3lf fahrenheit is %.3lf fahrenheit \n", e, e);
	}
	else 
		printf("You typed the wrong value !!");		// if user type different value from 1 - 3
}
void mass(){
	int f;
	double g, res21, res22;
	
	system("cls");
	printf("Choose unit which you want to convert: \n");
	printf("1. Kilograms to tones \n");
	printf("2. Tones to kilograms \n");
	scanf("%d", &f);					
	
	switch(f){
		case 1:
			printf("How much kilograms you want to convert ? \n");
			scanf("%lf", &g);										
			res21 = g / 1000;								
			printf("%.3lf kilograms is %.3lf tones \n", g, res21);	
			break;
			
		case 2:
			printf("How much tones you want to convert ? \n");
			scanf("%lf", &g);											
			res22 = g * 1000;									
			printf("%.3lf tones is %.3lf kilograms \n", g, res22);		
			break;
			
		default:
			printf("You typed the wrong value !!");						// if user type different value from 1 or 2
			break;
	}
	
}


int main() {
	int x;
	
	printf("\n");
	printf("********************** UNIT CONVERTER ************************** \n");
	printf("---------------------------------------------------------------- \n");
	
	printf("From which measure do you want to convert units ? \n");
	printf("1. Temperature \n");
	printf("2. Distance \n");
	printf("3. Mass \n");
	printf("4. Exit program \n");
	
	scanf("%d", &x);
	
	switch(x){
		case 1:
			temperature();		
			break;
			
		case 2:
			distance();			
			break;
			
		case 3:
			mass();				
			break;
			
		case 4:
			exit(1);					
			break;
			
		default:
			printf("You typed the wrong value !!");				
			break;
	}
	
	main();				// calling main function again for converting more values
	
	
}
