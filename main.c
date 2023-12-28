// C program to implement
// the above approach
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Declaring all the functions
void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);
void menuForUser(void);
void menuForAdmin(void);
void updateAcc(char*);
void accountUpdated(void);
void listUsers(void);
int deleteUser(char *fileName, char *username);
void deleteAccount(void);


// Declaring gotoxy
// function for setting
// cursor position
void gotoxy(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}


// Creating a structure to store
// data of the user
struct pass {
	char username[50];
	char cardNum[50];
	int date, month, year;
	char pnumber[15];
	char fname[20];
	char lname[20];
	char address[50];
	char typeaccount[20];
};

// Structure to keep track
// of amount transfer
struct money {
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass {
	char password[50];
};

// Driver Code
int main()
{
    // Creating a Main
    //menu to choose user or admin

	int choice1;
    gotoxy(25, 3);
	printf("BANK ACCOUNT SYSTEM\n\n");

	gotoxy(18, 5);
	printf("==================================");

	gotoxy(25, 7);
	printf("DEVELOPER-Rayen Jenhani");

	gotoxy(20, 10);
	printf("[1] ADMIN \n");

	gotoxy(20, 12);
	printf("[2] USER \n\n");

	printf("\n\n ENTER YOUR CHOICE..");
	scanf("%d",&choice1);

	if(choice1==2){
        menuForUser();


	}
	if(choice1==1){
        menuForAdmin();


	}


}

void menuForAdmin(){

    //Confirm the admin
    system("cls");
    char admin1[50];
    char password[50];


    gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	// Take input
	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &admin1);

	gotoxy(35, 14);
	printf("PASSWORD..");


    for (int i = 0; i < 50; i++) {
        char ch;
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}
	if(strcmp(admin1,"admin")==0){
    //menu for the admin
    system("cls");
	int i, a, b, choice1;
	int passwordlength;

	gotoxy(20, 3);
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");

	gotoxy(18, 5);
	printf("**********************************");

	gotoxy(20, 10);
	printf("1.... LIST OF USERS");

	gotoxy(20, 12);
	printf("2.... DELETE AN ACCOUNT");
	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");
	scanf("%d", &choice1);

    switch (choice1) {
	case 1:
		listUsers();
		break;

	case 2:
		deleteAccount();
		break;

	case 3:
		exit(0);
		break;

		getch();
	}

   }else{

       gotoxy(30,20);
       printf("YOU ARE NOT AN ADMIN !");

       getch();
       system("cls");
       main();
   }
}

//Function for users'list
void listUsers(){
    system("cls");


    FILE *fuu;
    struct pass ligne;

    gotoxy(20, 3);
    printf("===LIST OF USERS===\n\n");

    fuu = fopen("username.txt", "rb");
    if (fuu == NULL) {
        printf("list vide.\n");
        return 1;
    }

    //print the list of users
    int i=0;
    while (fread(&ligne, sizeof(struct pass), 1, fuu) == 1) {
        i++;
        printf(" [%d]--> ",i);
        printf("USERNAME: %s\n",ligne.username);
        printf("FIRST and LAST NAME: %s", ligne.fname);
        printf(" %s", ligne.lname);
        printf("\n\n\n");

  }
    fclose(fuu);
    getch();
    menuForAdmin();

}

int deleteUser(char *fileName, char *username) {
    FILE *file, *tempFile;
    struct pass line;

    // Open the file in read mode
    file = fopen(fileName, "r+b");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Open a temporary file in write mode
    tempFile = fopen("tempfile.txt", "w+b");

    if (tempFile == NULL) {
        printf("Unable to open the temporary file.\n");
        fclose(file);
        return 1;
    }

    while (fread(&line, sizeof(line),1, file) != NULL) {
        if (strstr(line.username, username) == NULL) {
            fwrite(&line, sizeof(line), 1, tempFile);

        }
    }

    // Close the files
    fclose(file);
    fclose(tempFile);

    // Delete the original file
    if (remove(fileName) != 0) {
        printf("Error deleting the original file.\n");
        return 1;
    }

    // Rename the temporary file to replace the original file
    if (rename("tempfile.txt", fileName) != 0) {
        printf("Error renaming the temporary file.\n");
        return 1;
    }

    return 0; // Operation successful
}

void deleteAccount(void){
    system("cls");

    char usernameToD[50];
    gotoxy(20, 3);
	printf("===DELETE AN ACCOUNT===");

	gotoxy(22, 7);
	printf("ENTER USERNAME TO DELETE..");

	scanf("%s",&usernameToD);

    if (deleteUser("username.txt", usernameToD) == 0) {
        printf("Username deleted successfully.\n");
        getch();
        menuForAdmin();
    } else {
        printf("Error deleting the username.\n");
        getch();
        menuForAdmin();
    }




}



void menuForUser(void){

	// menu for the user
	system("cls");
	int i, a, b, choice2;
	int passwordlength;

	gotoxy(20, 3);
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");

	gotoxy(18, 5);
	printf("==================================");

	gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");

	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");

	scanf("%d", &choice2);

	switch (choice2) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		account();
		break;

	case 2:
		login();
		break;

	case 3:
		exit(0);
		break;

		getch();
	}
}

// Function to create accounts
// of users
void account(void)
{
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;

	struct userpass u2;

	// Opening file to
	// write data of a user
	fp = fopen("username.txt", "ab");

	// Inputs
	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME..");
	scanf("%s", &u1.fname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u1.lname);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u1.typeaccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nCARD NUMBER");
	scanf("%s", &u1.cardNum);

	printf("\n\nPHONE NUMBER");
	scanf("%s", &u1.pnumber);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD..");

	// Taking password in the form of
	// stars
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	// Writing to the file
	fwrite(&u1, sizeof(struct pass),
		1, fp);

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountcreated();
}

// Successful account creation
void accountcreated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	menuForUser();
}

// Login function to check
// the username of the user
void login(void)
{
	system("cls");

	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	// Opening file of
	// user data
	fp = fopen("username.txt", "rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	// Take input
	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	gotoxy(35, 14);
	printf("PASSWORD..");

	// Input the password
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	// Checking if username
	// exists in the file or not
	while (fread(&u1, sizeof(struct pass), 1, fp)) {
		if (strcmp(username,
				u1.username)
			== 0) {
			loginsu();
			display(username);
		}

	}
    printf("\n\n username doesn't exist !! \n\n");

	// Closing the file
	fclose(fp);
}

// Redirect after
// successful login
void loginsu(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 2000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(30, 20);
	printf("Press enter to continue");

	getch();
}

// Display function to show the
// data of the user on screen
void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	struct pass u1;

	if (fp == NULL) {
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username1,
				u1.username)
			== 0) {
			gotoxy(30, 1);
			printf("WELCOME, %s %s",
				u1.fname, u1.lname);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME..%s %s", u1.fname,
				u1.lname);

            gotoxy(55, 12);
			printf("CARD NUMBER..%s",
				u1.cardNum);

			gotoxy(55, 14);
			printf("MOBILE NUMBER..%s",
				u1.pnumber);

			gotoxy(55, 16);
			printf("DATE OF BIRTH.. %d-%d-%d",
				u1.date, u1.month, u1.year);

			gotoxy(55, 18);
			printf("ADDRESS..%s", u1.address);

			gotoxy(55, 20);
			printf("ACCOUNT TYPE..%s",
				u1.typeaccount);
		}
	}

	fclose(fp);

	gotoxy(0, 6);

	// Menu to perform different
	// actions by user
	printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1....CHECK BALANCE");
	gotoxy(0, 11);
	printf(" 2....TRANSFER MONEY");
	gotoxy(0, 13);
	printf(" 3....UPDATE ACCOUNT\n\n");
	gotoxy(0, 15);
	printf(" 4....LOG OUT\n\n");
	gotoxy(0, 17);
	printf(" 5....EXIT\n\n");

	printf(" ENTER YOUR CHOICES..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkbalance(username1);
		break;

	case 2:
		transfermoney();
		break;
    case 3:
        updateAcc(username1);
        break;
	case 4:
		logout();
		login();
		break;

	case 5:
		exit(0);
		break;
	}
}

void updateAcc(char username3[]){



    struct pass u11;
    char password[50];
    char usernameToD[50];
    FILE *fpp;


	// UPDATE Inputs

     system("cls");
	printf("\n\n    !!!!!UPDATE %s ACCOUNT!!!!! \n\n",username3);



    fpp = fopen("username.txt", "ab");
	printf("\n\nFIRST NAME..");
	scanf("%s", &u11.fname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u11.lname);

	printf("\n\nADDRESS..");
	scanf("%s", &u11.address);

	printf("\n\nACCOUNT TYPE");
	scanf("%s", &u11.typeaccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u11.date);
	printf("\nMONTH-");
	scanf("%d", &u11.month);
	printf("\nYEAR-");
	scanf("%d", &u11.year);

	printf("\n\nPHONE NUMBER");
	scanf("%s", u11.pnumber);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u11.username);

	printf("\n\nPASSWORD..");

	// Taking password in the form of
	// stars
	for (int i = 0; i < 50; i++) {
		char ch;
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	// Writing to the file
	fwrite(&u11, sizeof(u11),
		1, fpp);

	fclose(fpp);
	DeToUpAccount();





}

void DeToUpAccount(void){
    system("cls");

    char usernameToD[50];
    gotoxy(20, 3);
	printf("===Update AN ACCOUNT===");

	gotoxy(22, 7);
	printf("CONFIRM USERNAME TO UPDATE..");

	scanf("%s",&usernameToD);
    accountUpdated();





}

void accountUpdated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT UPDATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login");

	getch();
	login();
}

// Function to transfer
// money from one user to
// another
void transfermoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	// Opening file in read mode to
	// read user's username
	fp = fopen("username.txt", "rb");

	// Creating a another file
	// to write amount along with
	// username to which amount
	// is going to be transferred
	fm = fopen("mon.txt", "ab");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 13);

	// Taking amount input
	printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
	scanf("%d", &m1.money1);

	gotoxy(33, 16);
	printf("FROM (your username).. ");
	scanf("%s", &usernamet);

	gotoxy(33, 18);
	printf(" TO (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username if it
	// is present in file or not
	while (fread(&u1, sizeof(u1),
				1, fp))

	{
		if (strcmp(usernamep,
				u1.username)
			== 0) {
			strcpy(m1.usernameto, u1.username);
			strcpy(m1.userpersonfrom, usernamet);
		}
	}


	// Writing to the file
	fwrite(&m1, sizeof(m1),
		1, fm);


	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);
	printf("transferring amount, Please wait..");



	gotoxy(10, 27);
	for (i = 0; i < 70; i++) {
		for (j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	// Close the files
	fclose(fp);
	fclose(fm);

	// Function to return
	// to the home screen
	display(usernamet);
}

// Function to check balance
// in users account
void checkbalance(char username2[])
{
	system("cls");
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;

	// Opening amount file record
	fm = fopen("mon.txt", "rb");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("***************************");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(m, n);
	printf("TRANSACTION ID");
	gotoxy(u, v);
	printf("AMOUNT");

	// Reading username to
	// fetch the correct record
	while (fread(&m1, sizeof(m1),
				1, fm)) {
		if (strcmp(username2,
				m1.usernameto)
			== 0) {
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%d", m1.money1);
			// Adding and
			// finding total money
			summoney = summoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 12);
	printf("%d", summoney);

	getch();

	// Closing file after
	// reading it
	fclose(fm);
	display(username2);
}

// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue..");

	getch();
}
