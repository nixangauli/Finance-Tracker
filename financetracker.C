#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

char *month;
char _income[20] = "";
char month_1[20]= "";
char _expense[20] = "";
float TotalSaved = 0;

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
	float spendinglimit;
}mot;

struct results {
	float totalExpense;
	float totalIncome;
};

typedef struct results Result;
struct user{
	char username[20];
	char pass[20];
}usr,usr1;

//define Empty struct
//static const struct incomeSources Ein;
//static const struct expenseSources Eex;
//static const struct months Emonth;
//static const struct results Eresult;
//static const struct user Euser;

// Color Coding //
void red () {
  printf("\033[1;31m");
}
void yellow() {
  printf("\033[1;33m");
};
void green() {
  printf("\033[0;32m");
};
void blue (){
  printf("\033[0;34m");
};
void cyan (){
  printf("\033[0;36m");
};
void white (){
printf("\033[0;37m");
};

void menu (int);
void income (int);
void expense (int);
void choosemonth(int n);

int getarrow () {
	int chr1, chr2;
	chr1 = getch();
	if (chr1 == 27) {
		return 27;
	}
	else if (chr1 == 0xE0) { //to check scroll key interrupt
	  	chr2 = getch();  //to read arrow key
	  	switch(chr2) {
		    case 72: return 1; //UP arrow
		      	break;
		    case 80: return 2; //DOWN arrow
		      	break;
		    case 75: return 3; //LEFT arrow
		      	break;
		    case 77: return 4; //RIGHT arrow
		      	break;
		    default: return 0;
		    	break;
	  };
	}
}

void resetvariable () {
	memset (_income, '\0', sizeof (_income));
	memset (month_1, '\0', sizeof (month_1));
	memset (_expense, '\0', sizeof (_expense));
	memset (&in, 0, sizeof (in));
	memset (&ex, 0, sizeof (ex));
	memset (&mot, 0, sizeof (mot));
	memset (&usr, 0, sizeof (usr));
	memset (&usr1, 0, sizeof (usr1));
}

Result addRow(int n){
	Result r1;
	FILE *fp;
	char _month[20]="";
	char name[20]="";
	if(n==1){
		strcat(_month, "Baisakh/main.txt");
		strcat(name, "Baisakh");
	}
	if(n==2){
		strcat(_month, "Jestha/main.txt");
		strcat(name, "Jestha");
	}
	if(n==3){
		strcat(_month, "Ashar/main.txt");
		strcat(name, "Ashar");
	}
	if(n==4){
		strcat(_month, "Shrawan/main.txt");
		strcat(name, "Shrawan");
	}
	if(n==5){
		strcat(_month, "Bhadra/main.txt");
		strcat(name, "Bhadra");
	}
	if(n==6){
		strcat(_month, "Ashwin/main.txt");
		strcat(name, "Ashwin");
	}
	if(n==7){
		strcat(_month, "Kartik/main.txt");
		strcat(name, "Kartik");
	}
	if(n==8){
		strcat(_month, "Mangsir/main.txt");
		strcat(name, "Mangsir");
	}
	if(n==9){
		strcat(_month, "Poush/main.txt");
		strcat(name, "Poush");
	}
	if(n==10){
		strcat(_month, "Magh/main.txt");
		strcat(name, "Magh");
	}
	if(n==11){
		strcat(_month, "Falgun/main.txt");
		strcat(name, "Falgun");
	}
	if(n==12){
		strcat(_month, "Chaitra/main.txt");
		strcat(name, "Chaitra");
	}
	
	
	fp = fopen(_month, "r");
	
	if(fp != NULL){
		fread(&mot, sizeof(struct months), 1,fp);
		printf("\t%s\t\t\t%.3f\t%.3f\t%.3f\n", name, mot.income, mot.expense, mot.income-mot.expense);
		r1.totalExpense = mot.expense;
		r1.totalIncome = mot.income;
		return r1;
	}else{
		r1.totalExpense = 0;
		r1.totalIncome = 0;
		return r1;
	}
}

void generatereport () {
	int start, end,i;
	Result r2;
	float totalExpense=0, totalIncome=0;
	system ("cls");
	reset:
	
	printf ("\n\n\tHow many months of report would you like?\n\t(1 being Baisakh and 12 being Chaitra)\n");
	printf ("\n\tEnter Starting Month: ");
	scanf ("%d", &start);
	printf ("\n\tEnter Ending Month: ");
	scanf ("%d", &end);
	
	if (start < 1 || end > 12 || start > end || start > 11 || end < 2) {
		red ();
		printf ("\n\n\tInvalid Range.\n\tPress Enter to generate again.");
		white();
		getch ();
		goto reset;
	}
	else {
		yellow ();
		printf("\n\tSN.\tMonth\t\t\tIncome\t\tExpense\t\tSaving\n\n");
		white ();
		for(i = 0; i<=end-start; i++){
			printf("\t%d", i+1);
			r2 = addRow(start+i);
			totalExpense += r2.totalExpense;
			totalIncome +=r2.totalIncome;
					
		}
		printf("\n\tTotal ");
		printf("\t\t\t\t%.2f", totalIncome);
		printf("\t%.2f", totalExpense);
		printf("\t%.2f", totalIncome - totalExpense);
	}
	
	getch();
	choosemonth(1);
}

void choosemonth (int n) {
	
	int ch;
	int check;
	
	system ("cls");
	
	yellow ();
	printf ("\n\tManage Your Finance\n\n");
	white ();
	
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
	
	yellow ();
	printf ("\n\tReport\n");
	white ();
	n==13 ? printf("\t=> "): printf("\t# ");
	printf ("a. Generate Report\n");
	
	blue ();
	printf ("\n\n\n\tUse Arrow key to navigate.");
	white();
	
	do {
		ch = getarrow ();
		switch (ch) {
		case 1:
			n-1 == 0 ? choosemonth (13): choosemonth (n-1);
			break;
		
		case 2:
			n+1 == 14 ? choosemonth (1): choosemonth (n+1);
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
				
				case 13:
					generatereport ();
					break;
			}
			break;

	}	
	}while (true);
}

void updatemonth () {
	FILE *f1, *f2, *f3;
	struct incomeSources temp;
	struct expenseSources temp2;
	
	f1 = fopen (_income, "r");
	f2 = fopen (_expense, "r");
	f3 = fopen (month_1, "w");
	
	mot.income = 0;  // resets income data in menubar //
	mot.expense = 0;  // resets expense data in menubar //
	
	while (fread (&temp, sizeof(struct incomeSources), 1, f1)) {
		mot.income += temp.monay;
	}
	
	while (fread (&temp2, sizeof(struct expenseSources), 1, f2)) {
		mot.expense += temp2.monay;
	}
	
	fwrite (&mot, sizeof (struct months), 1, f3);
	fclose (f1);
	fclose (f2);
	fclose (f3);
}

void getdata () {

	FILE *f1;
	f1 = fopen (month_1, "r");

	if (f1 == NULL) {
		fclose (f1);
		
		f1 = fopen (month_1, "w");
		mot.expense = 0; 
		mot.income = 0;
		mot.spendinglimit = 0;
		
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

void gettotalsavedamount () {
	
	FILE *fp;
	TotalSaved = 0;
	fp = fopen ("Baisakh/main.txt", "r");
	
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Jestha/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Ashar/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Shrawan/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Bhadra/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Ashwin/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Kartik/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Mangsir/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Poush/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Magh/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Falgun/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fp = fopen ("Chaitra/main.txt", "r");
	if (fp != NULL) {
		fread (&mot, sizeof(struct months), 1, fp);
		TotalSaved += mot.income-mot.expense;
	}
	
	fclose (fp);
}

void menubar () { 
	//Total Income and Expense display at top//
	mot.income = 0;
	mot.expense = 0;
	TotalSaved = 0;
	mot.spendinglimit = 0;
	
	updatemonth ();
	gettotalsavedamount ();
	getdata ();
	
	white ();
	printf ("\tNet Income: ");
	green ();
	printf ("%.2f", mot.income);
	white ();
	printf ("\t\tNet Expense: ");
	red ();
	printf ("%.2f", mot.expense);
	white ();
	printf ("\n\tSaved Amount: ");
	cyan ();
	printf ("%.2f", mot.income - mot.expense);
	white ();
	printf ("\t\tTotal Saved Amount: ");
	cyan ();
	printf ("%.2f", TotalSaved);
	white ();
	printf ("\t\tSpending Limit: ");
	cyan ();
	printf ("%.2f", mot.spendinglimit);
	white ();
	
	if (mot.spendinglimit != 0) {
		if (mot.spendinglimit < mot.expense) {
			red ();
			printf ("\n\n\tYou have exceeded your spending limit!");
		}
		else if (0.75 * mot.spendinglimit < mot.spendinglimit){
			yellow ();
			printf ("You are getting close to the limit!");
		}
		printf ("\n\n");
	}
	else {
		printf ("\n\n");
	}
}

int validation (char ch[]) {
	int len = strlen(ch);
	bool valid = true;
	for (int i=0; i < len; i++) {
		if (!isdigit(ch[i])) {
			valid = false;
		}
	}
	return valid;
}

// A user set value to limit the spending of user //
void spendingLimit () {
	float sp;
	int check;
	char ch [20];
	
	FILE *fp, *f1;
	fp = fopen (month_1, "r");
	
	fread (&mot, sizeof (struct months), 1, fp);
	
	system ("cls");
	printf ("\n\n\tCurrent Spending Limit: %.2f", mot.spendinglimit);
	printf ("\n\n\tEnter new Spending Limit: ");
//	scanf ("%s", &ch);
			
//	check = validation(ch);
//	if (!check) {
//		red ();
//		printf ("\n\tINVALID Amount. Please add real amount.");
//		white ();
//		return;
//	}
//	sscanf (ch, "%f", &mot.spendinglimit);
	scanf ("%f", &sp);
	fclose (fp);
	mot.spendinglimit = sp;
	
	f1 = fopen (month_1, "w");
	if (fwrite (&mot, sizeof (struct months), 1, f1)) {
		printf ("SUCCEFFULL");
		printf ("%f", mot.spendinglimit);
	}
	fclose (fp);
	fclose (f1);
	
	yellow ();
	printf ("\n\n\tSuccessfully Created Limit.\n\tPress Enter to go back.");
	getch ();

	menu (1);
	
}

void incomesource () {
	char ch[20];
	struct incomeSources temp, temp2;
	bool valid;
	int check;
	
	system ("cls");	
	
	menubar ();
	
	FILE *fin, *fin1;
	fin = fopen (_income, "a+");
	fin1 = fopen (_income, "r");
	
	printf ("\n\tEnter Source Name: ");
	scanf ("%s", &temp.name);
	
	printf ("\n\tEnter Amount: ");
	scanf ("%s", &ch);
			
			check = validation(ch);
			if (!check) {
				red ();
				printf ("\n\tINVALID Amount. Please add real amount.");
				white ();
				return;
			}
			sscanf (ch, "%f", &temp.monay);
	
	temp.id = 0;
	
	while (fread (&temp2, sizeof(struct incomeSources), 1, fin1)) {
		if (strcmp(strlwr(temp.name), strlwr(temp2.name)) != 0) {
			temp.id = temp2.id;
		}
		else {
			red();
			printf ("\n\tThis source already exists.\n\tClick Enter to go back.");
			valid = false;
			white ();
		}
	}
	
	temp.id++;
	
	if (valid){
		fwrite (&temp, sizeof(struct incomeSources), 1, fin);
		green ();
		printf ("\n\t Data Successfully stored!\n\t Click Enter to go back.");
		white ();
	}
	fclose (fin1);
	fclose (fin);
	getch ();
	
	income (1);
}

void editincomesource () {
	char ch [20];
	struct incomeSources temp;
	int id, check;
	
	FILE *fin, *fin1;
	fin = fopen (_income, "r");
	fin1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
			blue ();
			printf ("\n\n\n\tEnter New Data:\n");
			white ();
			
			//Enter New Source Name//
			printf ("\n\tEnter new Name: ");
			scanf ("%s", &temp.name);
			
			//Enter New Source Amount//
			printf ("\n\tEnter new Amount: ");
			scanf ("%s", &ch);
			
			check = validation(ch);
			if (!check) {
				red ();
				printf ("\n\tINVALID Amount. Please add real amount.");
				white ();
				return;
			}
			sscanf (ch, "%f", &temp.monay);
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
	char ch[20];
	struct incomeSources temp;
	int id, check;
	float addmonay;
	
	FILE *fin, *fin1;
	fin = fopen (_income, "r");
	fin1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct incomeSources), 1, fin)) {		
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
			blue ();
			printf ("\n\n\n\tEnter New Data:\n");
			white ();
			
			//Enter additional Amount//
			printf ("\n\tEnter Amount: ");
			scanf ("%s", &ch);
			
			check = validation(ch);
			if (!check) {
				red ();
				printf ("\n\tINVALID Amount. Please add real amount.");
				white ();
				return;
			}
			sscanf (ch, "%f", &addmonay);
			
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
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
	char ch[20];
	struct expenseSources temp, temp2;
	int check;
	bool valid;
	
	system ("cls");	
	
	menubar ();
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "a+");
	fex1 = fopen (_expense, "r");
	
	printf ("\n\tEnter Source Name: ");
	scanf ("%s", &temp.name);
	
	printf ("\n\tEnter Amount: ");
	scanf ("%s", &ch);

	check = validation(ch);
	if (!check) {
		red ();
		printf ("\n\tINVALID Amount. Please add real amount.");
		white ();
		return;
	}
	sscanf (ch, "%f", &temp.monay);
	
	temp.id = 0;
	
	while (fread (&temp2, sizeof(struct expenseSources), 1, fex1)) {
		if (strcmp(strlwr(temp.name), strlwr(temp2.name)) != 0) {
			temp.id = temp2.id;
		}
		else {
			red();
			printf ("\n\tThis source already exists.\n\tClick Enter to go back.");
			valid = false;
			white ();
		}
	}
	
	temp.id++;
	
	if (valid){
		fwrite (&temp, sizeof(struct expenseSources), 1, fex);
		green ();
		printf ("\n\t Data Successfully stored!\n\t Click Enter to go back.");
		white ();
	}
	fclose (fex1);
	fclose (fex);
	getch ();
	
	expense (1);
}

void editexpensesource () {
	char ch[20];
	struct expenseSources temp;
	int id;
	int check;
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "r");
	fex1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {		
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
			printf ("\n\tEnter new Name: ");
			scanf ("%s", &temp.name);
			
			//Enter New Source Amount//
			printf ("\n\tEnter new Amount: ");
			scanf ("%s", &ch);
			
			check = validation(ch);
			if (!check) {
				red ();
				printf ("\n\tINVALID Amount. Please add real amount.");
				white ();
				return;
			}
			sscanf (ch, "%f", &temp.monay);
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
	char ch[20];
	struct expenseSources temp;
	int id;
	int check;
	float addmonay;
	
	FILE *fex, *fex1;
	fex = fopen (_expense, "r");
	fex1 = fopen ("temp.txt", "w");
	
	system ("cls");
	
	while (fread (&temp, sizeof(struct expenseSources), 1, fex)) {		
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
			blue ();
			printf ("\n\n\n\tEnter New Data:\n");
			white ();
			
			//Enter additional Amount//
			printf ("\n\tEnter Amount: ");
			scanf ("%s", &ch);
			
			check = validation(ch);
			if (!check) {
				red ();
				printf ("\n\tINVALID Amount. Please add real amount.");
				white ();
				return;
			}
			sscanf (ch, "%f", &addmonay);
			
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
		printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
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
	
	int ch;
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
			printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);
			
		}
		
	}
	
	printf ("\n\n");
	
	n==1 ? printf("\t=>"): printf("\t#");	
	printf ("1. Add source \n");
	
	n==2 ? printf("\t=>"): printf("\t#");	
	printf ("2. Edit source \n");
	
	n==3 ? printf("\t=>"): printf("\t#");	
	printf ("3. Add Amount \n");
	
	n==4 ? printf("\t=>"): printf("\t#");	
	printf ("4. Delete source \n");
	
	blue ();
	printf ("\n\n\n\tUse the Arrow key to navigate.");
	white();
	
	do {
		ch = getarrow ();
		fflush (stdin);
		switch (ch) {
			case 27:
				menu (1);
				break;
				
			case 1:
				n-1 == 0 ? income (4): income (n-1);
				break;
		
			case 2:
				n+1 == 5 ? income (1): income (n+1);
				break;
			
			case '\r':
				loop = 0;
				n == 1 ? incomesource(): n == 2? editincomesource(): n == 3? addincomeamount () : n == 4? deleteincomesource (): error ();
		}	
	}while (1);
}

//Inside Expense Menu//
void expense (int n) {
	
	int ch;
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
			
			printf ("\n\t%d. %s :\t%.3f\n", temp.id, temp.name, temp.monay);	
			
		}
		
	}
	
	printf ("\n\n");
	
	n==1 ? printf("\t=>"): printf("\t#");	
	printf ("1. Add source \n");
	
	n==2 ? printf("\t=>"): printf("\t#");	
	printf ("2. Edit source \n");
	
	n==3 ? printf("\t=>"): printf("\t#");	
	printf ("3. Add Amount \n");
	
	n==4 ? printf("\t=>"): printf("\t#");	
	printf ("4. Delete source \n");
	
	blue ();
	printf ("\n\n\n\tUse the Arrow keys to navigate.");
	white();
	
	do {
		ch = getarrow ();
		fflush (stdin);
		switch (ch) {
			case 27:
				menu (1);
				break;
				
			case 1:
				n-1 == 0 ? expense (4): expense (n-1);
				break;
		
			case 2:
				n+1 == 5 ? expense (1): expense (n+1);
				break;
			
			case '\r':
				loop = 0;
				n == 1 ? expensesource (): n == 2? editexpensesource (): n == 3? addexpenseamount () : n == 4? deleteexpensesource (): error ();
		}	
	}while (1);
	
}


//Homescreen / Menu Screen//
void menu (int n) {
	int ch;
	system ("cls");
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
	
	yellow ();
	n==3 ? printf("\t=> "): printf("\t# ");
	printf ("3. Set Spending Limit\n");
	white ();
	
	blue ();
	printf ("\n\n\n\tUse the Arrow keys to navigate.");
	white();
	
	do {
		ch = getarrow ();
		fflush (stdin);
		switch (ch) {
			case 27:
				resetvariable ();
				choosemonth (1);
				break;
				
			case 1:
				n-1 == 0 ? menu (3): menu (n-1);
				break;
		
			case 2:
				n+1 == 4 ? menu (1): menu (n+1);
				break;
			
			case '\r':
				n == 1 ? income(1): n == 2 ? expense (1): n == 3 ? spendingLimit () : error ();
				break;	
		}	
	}while (1);
	
}


int requestLogin(){
	char ch;
	int i;
	FILE *fp;
	fp = fopen("password.txt", "rb");
	white();
	if(fp != NULL){
		printf("\n\tLOGIN\n\n");
		fread(&usr, sizeof(struct user), 1, fp);
		green();
		printf("\n\tEnter Username: ");
		cyan();
		scanf("%s", &usr1.username);
		green();
		printf("\n\tEnter Password: ");
		cyan();
		ch = getch();
		
		for(i = 0; ch!='\r'; i++){
			usr1.pass[i] = ch;
			printf("*");
			ch = getch();
		}
		
		white ();
		if(strcmp(usr1.pass, usr.pass) == 0 && strcmp(usr1.username, usr.username) == 0)
			{
				system ("cls");
							
				animatestring("Logged in ... Bonjour ");
				
				return 1;
			}
		
		else {
			printf("\n\n\t\tINKORREKT credentials....\n\t\tPress Enter to Try Again.\n");
				
			getch ();
				
			system ("cls");
			return 0;
		}
		
	}else{
		printf("\n\tREGISTER\n\n");
		printf("\tLets register your account");
		fclose(fp);
		fp = fopen("password.txt", "wb");
		
		green ();
		printf("\n\tEnter Username:\t");
		cyan ();
		scanf("\t%s", &usr.username);
		green ();
		printf("\n\tEnter Password:\t");
		
		cyan ();
		ch = getch();
		for(i = 0; ch!='\r'; i++){
			usr.pass[i] = ch;
			printf("*");
			ch = getch();
		}

		fwrite(&usr, sizeof(struct user), 1, fp);
		fclose(fp);
		green ();
		animatestring("\n\tRegister successfull! try logging in again....");
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

	choosemonth(1);
	return 0;
}
