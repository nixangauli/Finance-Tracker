#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

void menu (int);

void showtext (char text[100]) {
	int len;
	len = strlen(text);
	
			for (int i = 0; i <= len; i++) {
			printf ("%c", text[i]);
		}
	}

void animatestring (char text[100]) {
	
	printf ("\n\n\t");
	
	for (int i = 0; i <= 13; i++) {
		
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
				
			case 9:
				printf ("/");
				break;
				
			case 10:
				printf ("-");
				break;
				
			case 11:
				printf ("/");
				break;
				
			case 12:
				printf ("|");
				break;
				
			case 13:
				printf ("\\");
				break;
				
		}
		Sleep (300);
	}
}

int  password () {
	char user[20];
	char pwd[20];
	char ch;
	int passhide;
	
	printf ("          -------------Finance Tracker---------------            \n\n");
	
	printf("\n\tEnter Username : ");
	scanf("%s",&user);
	printf("\n\tEnter Secret Key : ");
	
	for(passhide=0; passhide <= 20; passhide++) {
					
		ch = getch();
		
		if (ch == '\r') {
			break;
		}
		
		pwd[passhide] = ch;
		ch = '*' ;
					
		printf("%c",ch);
	}

	
	if(strcmp(user,"nixan")==0)
	{
		if(strcmp(pwd,"12345678")==0)
			{		
				system ("cls");
				
				animatestring("Logged in ... Bonjour ");
				
				menu (1);
			}
		
		else {
			printf("\n\n\t\tINKORREKT credentials....\n\t\tPress Enter to Try Again.\n");
		
			getch ();
		
			system ("cls");
		
			password ();
		}
	}
	
	else
	{
		printf("\n\n\t\tINKORREKT credentials....\n\t\tPress Enter to Try Again.\n");
		
		getch ();
		
		system ("cls");
		
		password ();
	}
	
	getch();
	return 0;
}

// Error Page //
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
	printf ("\tNet Income: 50,000              Total Expense: 30,000\n\tSaved Amount: 20,000\n\n");
}

void incomesource (int n) {
	system ("cls");
	printf ("You can edit income source");
}

void expensesource (int n) {
	system ("cls");
	printf ("You can edit expense source");
}

//Inside Income Menu//
void income (int n) {
	char ch;
	
	system ("cls");
	
	menubar ();
			
	printf ("\tSalary: \t30000 \n"
			"\tCommission: \t5000 \n"
			"\tInvestment: \t10000 \n"
			"\tGift: \t\t5000 \n\n\n");
	
	n==0 ? printf("\t=>"): printf("\t#");
	
	printf ("0. Add custom source \n");
	
	do {
		ch = getch ();
		switch (ch) {
		
		case 27:
			menu(1);
			break;
			
		case 48:
			income (0);
			break;
		
		case '\r':
			n == 0 ? incomesource(n): error ();
			
	}	
	}while (true);
}

//Inside Expense Menu//
void expense (int n) {
	
	char ch;
	
	system ("cls");
	
	menubar ();
	
	printf ("\tSalary: \t30000 \n"
			"\tCommission: \t5000 \n"
			"\tInvestment: \t10000 \n"
			"\tGift: \t\t5000 \n\n\n");
	
	n==0 ? printf("\t=>"): printf("\t#");
	
	printf ("0. Add custom source \n");
	
	do {
		ch = getch ();
		switch (ch) {
		
		case 27:
			menu(1);
			break;
		
		case 48:
			expense (0);
			break;
		
		case '\r':
			n == 0 ? expensesource(n): error ();
	}	
	}while (true);
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
	}while (true);
	
}



int main() {
	
	password ();
	
	return 0;
}

