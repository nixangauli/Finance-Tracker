#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>

char* month;
char _income[20] = "";
char month_1[20]= "";
char _expense[20] = "";

// structure data for income source name, money and its id //
struct incomeSources {
	char name[20];
	float monay;
	int id;	
}in;

// structure data for expense source name, money and its id //
struct expenseSources {
	char name[20];
	float monay;
	int id;
}ex;

struct months {
	float expense;
	float income;
	float saving;
	
}mot;

struct user{
	char username[20];
	char pass[20];
}usr,usr1;

void menu (int);
void income (int);
void expense (int);
void savings (int);

void choosemonth (int n) {
	
	
	char ch;
	int check;
	
	system ("cls");
	
	n==1 ? printf("\t=> "): printf("\t# ");
	printf ("1. Baisakh\n");
	
	n==2 ? printf("\t=> "): printf("\t# ");
	printf ("2. Jestha\n");
	
	n==3 ? printf("\t=> "): printf("\t# ");
	printf ("3. Ashar\n");
	
	n==4 ? printf("\t=> "): printf("\t# ");
	printf ("4. Shrawan\n");
	
	n==5 ? printf("\t=> "): printf("\t# ");
	printf ("5. Bhadra\n");
	
	n==6 ? printf("\t=> "): printf("\t# ");
	printf ("6. Ashwin\n");
	
	n==7 ? printf("\t=> "): printf("\t# ");
	printf ("7. Kartik\n");
	
	n==8 ? printf("\t=> "): printf("\t# ");
	printf ("8. Mangsir\n");
	
	n==9 ? printf("\t=> "): printf("\t# ");
	printf ("9. Poush\n");
	
	n==10 ? printf("\t=> "): printf("\t# ");
	printf ("10. Magh\n");
	
	n==11 ? printf("\t=> "): printf("\t# ");
	printf ("11. Falgun\n");
	
	n==12 ? printf("\t=> "): printf("\t# ");
	printf ("12. Chaitra\n");
	
	do {
		ch = getch ();
		switch (ch) {
		case 119:
			n-1 == 0 ? choosemonth (12): choosemonth (n-1);
			break;
		
		case 115:
			n+1 == 13 ? choosemonth (1): choosemonth (n+1);
			break;
		
		case '\r':
			switch (n) {
				case 1:
					check = mkdir ("Baisakh");
					if (!check){
						month = (char*) malloc(8*sizeof(char));
				        month = "Baisakh";
				        
				        strcat(month_1, "Baisakh/main.txt");
						strcat(_income, "Baisakh/income.txt");
						strcat(_expense, "Baisakh/expense.txt");
						
						getch ();
				        menu (1);
				        break;
					}
					else {
				        
				        month = (char*) malloc(8*sizeof(char));
						month = "Baisakh";
						
						strcat(month_1, "Baisakh/main.txt");
						strcat(_income, "Baisakh/income.txt");
						strcat(_expense, "Baisakh/expense.txt");
						
				        menu (1);
				        break; 
				    }
				  
				
				case 2:
					check = mkdir ("Jestha");
					if (!check){
						month = (char*) malloc(7*sizeof(char));
				        month = "Jestha";
				        
				        strcat(month_1, "Jestha/main.txt");
						strcat(_income, "Jestha/income.txt");
						strcat(_expense, "Jestha/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(7*sizeof(char));
						month = "Jestha";
						
						strcat(month_1, "Jestha/main.txt");
						strcat(_income, "Jestha/income.txt");
						strcat(_expense, "Jestha/expense.txt");
						
				        menu (1);
					}
				break;
				
				case 3:
					check = mkdir ("Ashar");
					if (!check){
						month = (char*) malloc(6*sizeof(char));
				        month = "Ashar";
				        
						strcat(month_1, "Ashar/main.txt");
						strcat(_income, "Ashar/income.txt");
						strcat(_expense, "Ashar/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(6*sizeof(char));
						month = "Ashar";
						
						strcat(month_1, "Ashar/main.txt");
						strcat(_income, "Ashar/income.txt");
						strcat(_expense, "Ashar/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 4:
					check = mkdir ("Shrawan");
					if (!check){
						month = (char*) malloc(8*sizeof(char));
				        month = "Shrawan";
				        
						strcat(month_1, "Shrawan/main.txt");
						strcat(_income, "Shrawan/income.txt");
						strcat(_expense, "Shrawan/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(8*sizeof(char));
						month = "Shrawan";
						
						strcat(month_1, "Shrawan/main.txt");
						strcat(_income, "Shrawan/income.txt");
						strcat(_expense, "Shrawan/expense.txt");
						
				        menu (1);
					}
				break;
				
				case 5:
					check = mkdir ("Bhadra");
					if (!check){
						month = (char*) malloc(7*sizeof(char));
				        month = "Bhadra";
				        
						strcat(month_1, "Bhadra/main.txt");
						strcat(_income, "Bhadra/income.txt");
						strcat(_expense, "Bhadra/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(7*sizeof(char));
						month = "Bhadra";
						
						strcat(month_1, "Bhadra/main.txt");
						strcat(_income, "Bhadra/income.txt");
						strcat(_expense, "Bhadra/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 6:
					check = mkdir ("Ashwin");
					if (!check){
						month = (char*) malloc(7*sizeof(char));
				        month = "Ashwin";
				        
						strcat(month_1, "Ashwin/main.txt");
						strcat(_income, "Ashwin/income.txt");
						strcat(_expense, "Ashwin/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(7*sizeof(char));
						month = "Ashwin";
						
						strcat(month_1, "Ashwin/main.txt");
						strcat(_income, "Ashwin/income.txt");
						strcat(_expense, "Ashwin/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 7:
					check = mkdir ("Kartik");
					if (!check){
						month = (char*) malloc(7*sizeof(char));
				        month = "Kartik";
				        
						strcat(month_1, "Kartik/main.txt");
						strcat(_income, "Kartik/income.txt");
						strcat(_expense, "Kartik/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(7*sizeof(char));
						month = "Kartik";
						
						strcat(month_1, "Kartik/main.txt");
						strcat(_income, "Kartik/income.txt");
						strcat(_expense, "Kartik/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 8:
					check = mkdir ("Mangsir");
					if (!check){
						month = (char*) malloc(8*sizeof(char));
				        month = "Mangsir";
				        
						strcat(month_1, "Mangsir/main.txt");
						strcat(_income, "Mangsir/income.txt");
						strcat(_expense, "Mangsir/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(8*sizeof(char));
						month = "Mangsir";
						
						strcat(month_1, "Mangsir/main.txt");
						strcat(_income, "Mangsir/income.txt");
						strcat(_expense, "Mangsir/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 9:
					check = mkdir ("Poush");
					if (!check){
						month = (char*) malloc(6*sizeof(char));
				        month = "Poush";
				        
						strcat(month_1, "Poush/main.txt");
						strcat(_income, "Poush/income.txt");
						strcat(_expense, "Poush/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(6*sizeof(char));
						month = "Poush";
						
						strcat(month_1, "Poush/main.txt");
						strcat(_income, "Poush/income.txt");
						strcat(_expense, "Poush/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 10:
					check = mkdir ("Magh");
					if (!check){
						month = (char*) malloc(5*sizeof(char));
				        month = "Magh";
				        
						strcat(month_1, "Magh/main.txt");
						strcat(_income, "Magh/income.txt");
						strcat(_expense, "Magh/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(5*sizeof(char));
						month = "Magh";
						
						strcat(month_1, "Magh/main.txt");
						strcat(_income, "Magh/income.txt");
						strcat(_expense, "Magh/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 11:
					check = mkdir ("Falgun");
					if (!check){
						month = (char*) malloc(7*sizeof(char));
				        month = "Falgun";
				        
						strcat(month_1, "Falgun/main.txt");
						strcat(_income, "Falgun/income.txt");
						strcat(_expense, "Falgun/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(7*sizeof(char));
						month = "Falgun";
						
						strcat(month_1, "Falgun/main.txt");
						strcat(_income, "Falgun/income.txt");
						strcat(_expense, "Falgun/expense.txt");
						
				        menu (1); 
					}
				break;
				
				case 12:
					check = mkdir ("Chaitra");
					if (!check){
						month = (char*) malloc(8*sizeof(char));
				        month = "Chaitra";
				        
						strcat(month_1, "Chaitra/main.txt");
						strcat(_income, "Chaitra/income.txt");
						strcat(_expense, "Chaitra/expense.txt");
						
				        menu (1);
				    }
					else {
				        
				        month = (char*) malloc(8*sizeof(char));
						month = "Chaitra";
						
						strcat(month_1, "Chaitra/main.txt");
						strcat(_income, "Chaitra/income.txt");
						strcat(_expense, "Chaitra/expense.txt");
						
				        menu (1);
					}
				break;
				
			}
			break;
		
	}	
	}while (true);
}

void getdata () {
	FILE *f1;
	f1 = fopen (month_1, "r");
	
	if (f1 == NULL) {
		fclose (f1);
		
		f1 = fopen (month_1, "w");
		mot.expense = 0; 
		mot.income = 0;
		mot.saving = 0;
		
		fwrite (&mot, sizeof(struct months), 1, f1);
		
		fclose (f1);
	}
	else {
		fread (&mot, sizeof(struct months), 1, f1);
		
		fclose (f1);
	}
}

void showtext (char text[100]) {
	int len;
	len = strlen(text);
	
			for (int i = 0; i <= len; i++) {
			printf ("%c", text[i]);
		}
	}

void animatestring (char text[100]) {
	
	printf ("\n\n\t");
	
	for (int i = 0; i <= 8; i++) {
		
		system ("cls");
		showtext (text);
		
		switch (i) {
			case 0:
				printf ("\\");
				break;
			
			case 1:
				printf ("|");
				break;
				
			case 2:
				printf ("/");
				break;
				
			case 3:
				printf ("-");
				break;
				
			case 4:
				printf ("/");
				break;
				
			case 5:
				printf ("|");
				break;
				
			case 6:
				printf ("\\");
				break;
				
			case 7:
				printf ("\\");
				break;
				
			case 8:
				printf ("|");
				break;
		}
		Sleep (100);
	}
}

void error () {
	printf ("\n\n"                                                                                                   
			"\t\tEEEEEEEEEEEEEEEEEEEEEE                                                                             \n"
			"\t\tE::::::::::::::::::::E                                                                             \n"
			"\t\tE::::::::::::::::::::E                                                                             \n"
			"\t\tEE::::::EEEEEEEEE::::E                                                                             \n"
			"\t\t  E:::::E       EEEEEErrrrr   rrrrrrrrr   rrrrr   rrrrrrrrr      ooooooooooo   rrrrr   rrrrrrrrr   \n"
			"\t\t  E:::::E             r::::rrr:::::::::r  r::::rrr:::::::::r   oo:::::::::::oo r::::rrr:::::::::r  \n"
			"\t\t  E::::::EEEEEEEEEE   r:::::::::::::::::r r:::::::::::::::::r o:::::::::::::::or:::::::::::::::::r \n"
			"\t\t  E:::::::::::::::E   rr::::::rrrrr::::::rrr::::::rrrrr::::::ro:::::ooooo:::::orr::::::rrrrr::::::r\n"
			"\t\t  E:::::::::::::::E    r:::::r     r:::::r r:::::r     r:::::ro::::o     o::::o r:::::r     r:::::r\n"
			"\t\t  E::::::EEEEEEEEEE    r:::::r     rrrrrrr r:::::r     rrrrrrro::::o     o::::o r:::::r     rrrrrrr\n"
			"\t\t  E:::::E              r:::::r             r:::::r            o::::o     o::::o r:::::r            \n"
			"\t\t  E:::::E       EEEEEE r:::::r             r:::::r            o::::o     o::::o r:::::r            \n"
			"\t\tEE::::::EEEEEEEE:::::E r:::::r             r:::::r            o:::::ooooo:::::o r:::::r            \n"
			"\t\tE::::::::::::::::::::E r:::::r             r:::::r            o:::::::::::::::o r:::::r            \n"
			"\t\tE::::::::::::::::::::E r:::::r             r:::::r             oo:::::::::::oo  r:::::r            \n"
			"\t\tEEEEEEEEEEEEEEEEEEEEEE rrrrrrr             rrrrrrr               ooooooooooo    rrrrrrr            \n");
}

void menubar () { 
	//Total Income and Expense display at top//
	printf ("\tNet Income: %.2f              Total Expense: - %.2f\n\tSaved Amount: %.2f\n\n", mot.income, mot.expense, mot.saving);
}

void incomesource () {
	
	struct incomeSources temp, temp2;
	
	system ("cls");	
	
	menubar ();
	
	FILE *fin, *fin1;
	fin = fopen (_income, "a+");
	fin1 = fopen (_income, "r");
	
	printf ("\n\tEnter Source Name: ");
	scanf ("%s", &temp.name);
	
	printf ("\n\tEnter Amount: ");
	scanf ("%f", &temp.monay);
	
	temp.id = 0;
	
	while (fread (&temp2, sizeof(struct incomeSources), 1, fin1)) {
		temp.id = temp2.id;
	}
	
	temp.id++;
	
	fwrite (&temp, sizeof(struct incomeSources), 1, fin);
	fclose (fin);
	
	printf ("\n\t Data Successfully stored!\n\t Click Enter to go back.");
	
	getch ();
	
	income (1);
}

void editincomesource () {
	
	struct incomeSources temp;
	int id;
	
	FILE *fin, *fin1;
	fin = fopen (_income, "r");
	fin1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fin);
	
	printf ("\n\n\tEnter id to edit: ");
	scanf ("%d", &id);

	fin = fopen (_income, "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id == id) {
			
			//Shows the existing data//
			printf("\n\tID: \t%d\n\tSource: \t%s\n\tAmount: \t%f", temp.id, temp.name, temp.monay);
			printf ("\n\n\n\tEnter New Data:\n");
			
			//Enter New Source Name//
			printf ("\nEnter new Name: ");
			scanf ("%s", &temp.name);
			
			//Enter New Source Amount//
			printf ("\nEnter new Amount: ");
			scanf ("%f", &temp.monay);
		}

		//Writes the new data from if and existing data from temp variable to temp file//
		fwrite (&temp, sizeof(struct incomeSources), 1, fin1);
	}
	
	fclose (fin1);
	fclose (fin);
	
	fin = fopen (_income, "w");
	fin1 = fopen ("temp.txt", "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin1)) {
		fwrite (&temp, sizeof (struct incomeSources), 1, fin);
	}
	
	fclose (fin1);
	fclose (fin);
	income (1);	
}

void addincomeamount () {
	struct incomeSources temp;
	int id;
	float addmonay;
	
	FILE *fin, *fin1;
	fin = fopen (_income, "r");
	fin1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fin);
	
	printf ("\n\n\tEnter id to add amount: ");
	scanf ("%d", &id);

	fin = fopen (_income, "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id == id) {
			
			//Shows the existing data//
			printf("\n\tID: \t%d\n\tSource: \t%s\n\tAmount: \t%f", temp.id, temp.name, temp.monay);
			printf ("\n\n\n\tEnter New Data:\n");
			
			//Enter additional Amount//
			printf ("\nEnter Amount: ");
			scanf ("%f", &addmonay);
			
			temp.monay += addmonay;
		}

		//Writes the new data from if and existing data from temp variable to temp file//
		fwrite (&temp, sizeof(struct incomeSources), 1, fin1);
	}
	
	fclose (fin1);
	fclose (fin);
	
	fin = fopen (_income, "w");
	fin1 = fopen ("temp.txt", "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin1)) {
		fwrite (&temp, sizeof (struct incomeSources), 1, fin);
	}
	
	fclose (fin1);
	fclose (fin);
	income (1);
}

void deleteincomesource () {
	struct incomeSources temp;
	int id, count;
	
	FILE *fin, *fin1;
	fin = fopen (_income, "r");
	fin1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fin);
	
	printf ("\n\n\tEnter id to delete: ");
	scanf ("%d", &id);

	fin = fopen (_income, "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id != id) {
			
			//Writes the new data from if and existing data from temp variable to temp file//
			fwrite (&temp, sizeof(struct incomeSources), 1, fin1);
		}
	}
	
	fclose (fin1);
	fclose (fin);
	
	fin = fopen (_income, "w");
	fin1 = fopen ("temp.txt", "r");
	
	for (count = 1; fread (&temp, sizeof(struct incomeSources), 1, fin1); count++) {
		temp.id = count;
		
		//Writes the data with new id after deletion//
		fwrite (&temp, sizeof(struct incomeSources), 1, fin);
	}
	
	fclose (fin1);
	fclose (fin);
//	resetincomeid ();
	income (1);	
}

void expensesource () {
	
	struct expenseSources temp, temp2;
	
	system ("cls");	
	
	menubar ();
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "a+");
	fex1 = fopen (_expense, "r");
	
	printf ("\n\tEnter Source Name: ");
	scanf ("%s", &temp.name);
	
	printf ("\n\tEnter Amount: ");
	scanf ("%f", &temp.monay);
	
	temp.id = 0;
	
	while (fread (&temp2, sizeof(struct expenseSources), 1, fex1)) {
		temp.id = temp2.id;
	}
	
	temp.id++;
	
	fwrite (&temp, sizeof(struct expenseSources), 1, fex);
	fclose (fex);
	
	printf ("\n\t Data Successfully stored!\n\t Click Enter to go back.");
	
	getch ();
	
	expense (1);
}

void editexpensesource () {
	
	struct expenseSources temp;
	int id;
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "r");
	fex1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fex);
	
	printf ("\n\n\tEnter id to edit: ");
	scanf ("%d", &id);

	fex = fopen (_expense, "r");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id == id) {
			
			//Shows the existing data//
			printf("\n\tID: \t%d\n\tSource: \t%s\n\tAmount: \t%f", temp.id, temp.name, temp.monay);
			printf ("\n\n\n\tEnter New Data:\n");
			
			//Enter New Source Name//
			printf ("\nEnter new Name: ");
			scanf ("%s", &temp.name);
			
			//Enter New Source Amount//
			printf ("\nEnter new Amount: ");
			scanf ("%f", &temp.monay);
		}

		//Writes the new data from if and existing data from temp variable to temp file//
		fwrite (&temp, sizeof(struct expenseSources), 1, fex1);
	}
	
	fclose (fex1);
	fclose (fex);
	
	fex = fopen (_expense, "w");
	fex1 = fopen ("temp.txt", "r");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex1)) {
		fwrite (&temp, sizeof (struct incomeSources), 1, fex);
	}
	
	fclose (fex1);
	fclose (fex);
	expense (1);
}

void addexpenseamount () {
	struct expenseSources temp;
	int id;
	float addmonay;
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "r");
	fex1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fex);
	
	printf ("\n\n\tEnter id to add amount: ");
	scanf ("%d", &id);

	fex = fopen (_expense, "r");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id == id) {
			
			//Shows the existing data//
			printf("\n\tID: \t%d\n\tSource: \t%s\n\tAmount: \t%f", temp.id, temp.name, temp.monay);
			printf ("\n\n\n\tEnter New Data:\n");
			
			//Enter additional Amount//
			printf ("\nEnter Amount: ");
			scanf ("%f", &addmonay);
			
			temp.monay += addmonay;
		}

		//Writes the new data from if and existing data from temp variable to temp file//
		fwrite (&temp, sizeof(struct expenseSources), 1, fex1);
	}
	
	fclose (fex1);
	fclose (fex);
	
	fex = fopen (_expense, "w");
	fex1 = fopen ("temp.txt", "r");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex1)) {
		fwrite (&temp, sizeof (struct expenseSources), 1, fex);
	}
	
	fclose (fex1);
	fclose (fex);
	expense (1);
}

void deleteexpensesource () {
	
	struct expenseSources temp;
	int id, count;
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "r");
	fex1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {		
		printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
	}
	
	fclose (fex);
	
	printf ("\n\n\tEnter id to delete: ");
	scanf ("%d", &id);

	fex = fopen (_expense, "r");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fex)) {

		//Goes inside to edit data if id matches the input data//
		if (temp.id != id) {
			
			//Writes the new data from if and existing data from temp variable to temp file//
			fwrite (&temp, sizeof(struct incomeSources), 1, fex1);
		}
	}
	
	fclose (fex1);
	fclose (fex);
	
	fex = fopen (_expense, "w");
	fex1 = fopen ("temp.txt", "r");
	
	for (count = 1; fread (&temp, sizeof(struct expenseSources), 1, fex1); count++) {
		temp.id = count;
		
		//Writes the data with new id after deletion//
		fwrite (&temp, sizeof(struct expenseSources), 1, fex);
	}
	
	fclose (fex1);
	fclose (fex);
	
//	resetexpenseid ();
	expense (1);	
}

//Inside Income Menu//
void income (int n) {
	
	char ch;
	struct incomeSources temp;
	int loop = 1;
	
	system ("cls");
	
	menubar ();
	
	FILE *fin;
	fin = fopen (_income, "r");
	if (fin == NULL) {
		fclose (fin);
		
		fin = fopen (_income, "w");
		fclose (fin);
	}
	
	else {
		while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
			printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);
			
		}
		
	}
	
	n==1 ? printf("\t=>"): printf("\t#");	
	printf ("1. Add source \n");
	
	n==2 ? printf("\t=>"): printf("\t#");	
	printf ("2. Edit source \n");
	
	n==3 ? printf("\t=>"): printf("\t#");	
	printf ("3. Add Amount \n");
	
	n==4 ? printf("\t=>"): printf("\t#");	
	printf ("4. Delete source \n");
	
	do {
		ch = getch ();
		switch (ch) {
		
			case 27:
				menu(1);
				break;
				
			case 49:
				income (1);
				break;
			
			case 50:
				income (2);
				break;
			
			case 51:
				income (3);
				break;
			
			case 52:
				income (4);
				break;
			
			case '\r':
				loop = 0;
				n == 1 ? incomesource(): n == 2? editincomesource(): n == 3? addincomeamount () : n == 4? deleteincomesource (): error ();
		}	
	}while (1);
}

//Inside Expense Menu//
void expense (int n) {
	
	char ch;
	struct expenseSources temp;
	int loop = 1;
	
	system ("cls");
	
	menubar ();
	
	FILE *fex;
	fex = fopen (_expense, "r");
	if (fex == NULL) {
		fclose (fex);
		
		fex = fopen (_expense, "w");
		fclose (fex);
	}
	
	else {
		while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {
			
			printf ("\n\t%d. %s :\t%f\n", temp.id, temp.name, temp.monay);	
			
		}
		
	}
	
	n==1 ? printf("\t=>"): printf("\t#");	
	printf ("1. Add source \n");
	
	n==2 ? printf("\t=>"): printf("\t#");	
	printf ("2. Edit source \n");
	
	n==3 ? printf("\t=>"): printf("\t#");	
	printf ("3. Add Amount \n");
	
	n==4 ? printf("\t=>"): printf("\t#");	
	printf ("4. Delete source \n");
	
	do {
		ch = getch ();
		switch (ch) {
		
			case 27:
				menu(1);
				break;
				
			case 49:
				expense (1);
				break;
			
			case 50:
				expense (2);
				break;
			
			case 51:
				expense (3);
				break;
			
			case 52:
				expense (4);
				break;
			
			case '\r':
				loop = 0;
				n == 1 ? expensesource (): n == 2? editexpensesource (): n == 3? addexpenseamount () : n == 4? deleteexpensesource (): error ();
		}	
	}while (1);
	
}

//Inside Savings Menu//
void savings (int n) {
	char ch;
	
	system ("cls");
	
	menubar ();
	
	n==1 ? printf("\t=> "): printf("\t# ");
	printf ("1. Add your Wishlist\n");
	
	do {
		ch = getch ();
		switch (ch) {
		
		case 49:
			savings(1);
			break;
			
		case 27:
			menu(1);
			break;
	}	
	}while (true);
}



//Homescreen / Menu Screen//
void menu (int n) {
	
	system ("cls");
	
	char ch;
	printf ("\n\n\t\t"
			"MMMMMMMM               MMMMMMMM                                                        \n"
			"\t\tM:::::::M             M:::::::M                                                        \n"
			"\t\tM::::::::M           M::::::::M                                                        \n"
			"\t\tM:::::::::M         M:::::::::M                                                        \n"
			"\t\tM::::::::::M       M::::::::::M    eeeeeeeeeeee    nnnn  nnnnnnnn    uuuuuu    uuuuuu  \n"
			"\t\tM:::::::::::M     M:::::::::::M  ee::::::::::::ee  n:::nn::::::::nn  u::::u    u::::u  \n"
			"\t\tM:::::::M::::M   M::::M:::::::M e::::::eeeee:::::een::::::::::::::nn u::::u    u::::u  \n"
			"\t\tM::::::M M::::M M::::M M::::::Me::::::e     e:::::enn:::::::::::::::nu::::u    u::::u  \n"
			"\t\tM::::::M  M::::M::::M  M::::::Me:::::::eeeee::::::e  n:::::nnnn:::::nu::::u    u::::u  \n"
			"\t\tM::::::M   M:::::::M   M::::::Me:::::::::::::::::e   n::::n    n::::nu::::u    u::::u  \n"
			"\t\tM::::::M    M:::::M    M::::::Me::::::eeeeeeeeeee    n::::n    n::::nu::::u    u::::u  \n"
			"\t\tM::::::M     MMMMM     M::::::Me:::::::e             n::::n    n::::nu:::::uuuu:::::u  \n"
			"\t\tM::::::M               M::::::Me::::::::e            n::::n    n::::nu:::::::::::::::uu\n"
			"\t\tM::::::M               M::::::M e::::::::eeeeeeee    n::::n    n::::n u:::::::::::::::u\n"
			"\t\tM::::::M               M::::::M  ee:::::::::::::e    n::::n    n::::n  uu::::::::uu:::u\n"
			"\t\tMMMMMMMM               MMMMMMMM    eeeeeeeeeeeeee    nnnnnn    nnnnnn    uuuuuuuu  uuuu\n\n\n");
	
	
	getdata ();
	
	menubar ();
	
	n==1 ? printf("\t=> "): printf("\t# ");
	printf ("1. Income\n");
	
	n==2 ? printf("\t=> "): printf("\t# ");
	printf ("2. Expense\n");
	
	n==3 ? printf("\t=> "): printf("\t# ");
	printf ("3. Savings\n");
	
	do {
		ch = getch ();
		switch (ch) {
		case 49:
			menu (1);
			break;
		
		case 50:
			menu (2);
			break;
			
		case 51:
			menu (3);
			break;
		
		case '\r':
			n == 1 ? income(n): n == 2 ? expense (n): n == 3 ? savings (n) : error ();
			break;
	}	
	}while (1);
	
}

// A user set value to limit the spending of user //
void spendinglimit () {
	
}

int requestLogin(){
	char ch;
	int i;
	FILE *fp;
	fp = fopen("password.txt", "rb");
	if(fp != NULL){
		printf("\n\tLOGIN\n\n");
		fread(&usr, sizeof(struct user), 1, fp);
				
		printf("\n\tUsername:\t");
		scanf("%s", &usr1.username);
		printf("\n\n\tPassword:\t");
		
		ch = getch();
		for(i = 0; ch!='\r'; i++){
			usr1.pass[i] = ch;
			printf("*");
			ch = getch();
		}
		
		if(strcmp(usr1.pass, usr.pass) == 0 && strcmp(usr1.username, usr.username) == 0){
			printf("\n\n\tSuccessfully Logged In!\n\tpress any key to continue...");
			getch();
			return 1;
			
		}else{
			printf("\nPassword Incorrect!\n press any key to try again...");
			return 0;
			
		}
	}else{
		printf("\n\tREGISTER\n\n");
		printf("\tLets register your account");
		fclose(fp);
		fp = fopen("password.txt", "wb");
		
		printf("\n\tUsername:\t");
		scanf("\t%s", &usr.username);
		printf("\n\n\tPassword:\t");
		
		ch = getch();
		for(i = 0; ch!='\r'; i++){
			usr.pass[i] = ch;
			printf("*");
			ch = getch();
		}

		fwrite(&usr, sizeof(struct user), 1, fp);
		fclose(fp);
		printf("\nRegister successfull! try logging in again....");
		return 0;
	}
}
int main() {
	int loginCheck;
	askAgain:	
    system("cls");
	loginCheck = requestLogin();   
    if(!loginCheck){
		goto askAgain;
	}
	//password (); // Goes to password function for security //
	choosemonth(1);
	return 0;
}

