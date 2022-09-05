//header files
#include<stdio.h>//stdio.h is used in several different functions of c eg:- for file handling and etc
#include<conio.h>//conio.h header file provides input and output functions in  C
#include<ctype.h>// The ctype.h header file of the C Standard Library declares several functions that are useful for testing and mapping characters.
#include<windows.h>//windows.h header file used for windows api function in this program it is Sleep function
#include<stdlib.h>//stdlin.h is used in c programming in conversion of one data type to another

struct logindetails
{
	char name[10];
	char password[10];
}l;

struct book
{   
	char idname[10];
	char roomnumber[5];
	char username[10];
	char age[5];
	char id[10];
	char date[20];	
	char days[5];
	
}b;


int room;
int loginvalue=0;

void details()
{
	system("cls");
	FILE *f;
	char name[10];
	int flag=1;
	f=fopen("booking.txt","r+");
	if(f==0)
		exit(0);
	system("cls");
	while(fread(&b,sizeof(b),1,f)==1)
	
	{
		getch();
		if(strcmp(b.idname,l.name)==0){
			flag=0;
       	printf("Your details are \n");      
		printf("\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
		printf("\n \t%s\t\t%s\t%s\t%s\t%s\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);
		
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
	welcome();
}


void cancellation()
{
	FILE *f,*t;
	int i=1;
	char name[10];
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("booking.txt","r"))==NULL)
	exit(0);
	system("cls");
	
	while(fread(&b,sizeof(b),1,f)==1)
	{	
		if(strcmp(b.idname,l.name)==0)
		{
		
		printf("Your details are \n");      
		printf("\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
		printf("\n%s\t\t%s\t%s\t%s\t%s\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);
		getch();
		i=0;
		continue;
		}
		else
			fwrite(&b,sizeof(b),1,t);
	}
	if(i==1)
	{       
		printf("\n\n There is no booking yet from your account!!");
		getch();
		fclose(f);
		fclose(t);
		existinguser();
	}
	fclose(f);
	fclose(t);
	remove("booking.txt");
	rename("temp.txt","booking.txt");
	printf("\n\nYour data has been successfully removed");
	fclose(f);
	fclose(t);
	getch();
}



void adminloginbook()
{	char confirmation[10];
	int p=0,i=0;
    char adminname[10],c=' '; 
    char password[10],code[10];
    char admin[10]="abhi";
    char adminpass[10]="1234";
    char yes[]="yes";
    char no[]="no";
	do
{
	system("cls");
	
 Label6:   printf("\n\t\t\t  WELCOME ADMIN ");
    printf(" \n\nENTER ADMINNAME:-");
	scanf("%s", &adminname); 
	printf(" \n\nENTER PASSWORD:-");
	while(i<10)
	{
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';//end of the string, values are stored in password variable.if we remove this it will not work

	i=0;//resetting the value again to zero to make it store values since first character
		if(strcmp(adminname,admin)==0 && strcmp(password,adminpass)==0)
	{ itoa(room++,b.roomnumber,10);
	strcpy(b.idname,l.name);
	printf("\n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
	printf("The details of the current user is\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
	printf("\n%s\t%s\t%s\t%s\t%s\t\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);
	printf("Do u want to save the booking ?");
	scanf("%s",confirmation);
	if(stricmp(confirmation,yes)==0)
	{
		FILE *f;
		f=fopen("booking.txt","a+");
		fflush(stdin);	
		fwrite(&b,sizeof(b),1,f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		getch();
		system("cls");
		welcome();
	}
	
	
	
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		p=1;
		
		getch();
		goto Label6;
	}
}while(p==1);
}

void admindetails()
{	
	FILE *f,*t;	
	if((t=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((f=fopen("booking.txt","r"))==NULL)
	exit(0);
	system("cls");
	int i=0;	
	int value;		
	int choice;
	int k;
Label8:	printf("Select an option:-\n1)View Records 2)Delete Records 3)Search Record 4)Exit");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			printf("The details of the current user is\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
			
			while(fread(&b,sizeof(b),1,f)>0)
			{			
			printf("\n %s\t\t%s\t%s\t%s\t%s\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);
						
			}
			
			
			fclose(f);
			getch();
			break;
		case 2:
			i=1;
			printf("Enter the username to be deleted from the database:-\n");
			scanf("%s",l.name);
			while(fread(&b,sizeof(b),1,f)==1)
			{	
				if(strcmp(b.idname,l.name)==0)
				{
				printf("The details are \n");      
				printf("\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
				printf("\n \t%s\t%s\t%s\t%s\t%s\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);				
				getch();
				i=0;
				continue;
				}
				else
					fwrite(&b,sizeof(b),1,t);
			}
			if(i==1)
			{       
				printf("\n\n There is no booking yet from this account!!");
				getch();
				fclose(f);
				fclose(t);
				goto Label8;
			}
			fclose(f);
			fclose(t);
			remove("booking.txt");
			rename("temp.txt","booking.txt");
			printf("\n\nThe data has been successfully removed");
			fclose(f);
			fclose(t);
			getch();
			break;
		case 3:
			printf("Enter the username of the customer to search its details: \n");
			scanf("%s", l.name);
			while(fread(&b,sizeof(b),1,f)==1)
			{
				if(strcmp(b.idname,l.name)==0){
					value=0;
					printf("The details are \n");      
					printf("\n Username \tRoomnumber\tName\tAge\tId\tDate\t\tNo of Days");
					printf("\n \t%s\t%s\t%s\t%s\t%s\t%s\t%s",b.idname,b.roomnumber,b.username,b.age,b.id,b.date,b.days);				
				
					break;
				}
			}
			if(value==1){	
				printf("\n\tRequested Customer could not be found!");
			}
			getch();
			fclose(f);
			break;

			case 4:
				system("cls");
				printf("Closing the system");
				getch();
				exit(0);
			default:
				system("cls");
				printf("Wrong Choice");
				getch();
				goto Label8;
		}
		system("cls");
		goto Label8;	
}


void booking()
{
	printf("\n Enter your name:-");
	scanf("%s",b.username);
	fflush(stdin);
	printf("\n Enter your age:-");
	scanf("%s",&b.age);
	fflush(stdin);
	printf("\nEnter your Passport or ID Number:-");
	scanf("%s",&b.id);
	fflush(stdin);
	printf("\n Enter the date in(MM/DD/YYYY) format:-");
	scanf("%s",&b.date);
	printf("\n Enter the number of days u want to stay:-");
	scanf("%s",&b.days);

	getch();
}

void avail()
{   int choice=0;
	 FILE *f;
	 FILE *t;
 	
    char ch;
    char confirmation[10];
    char yes[]="yes";
    char no[]="no";
Label2:	system("cls");
	printf("\n\t\tENTER ROOM TYPE");
	printf("\nSelect from 1 to 3");
	printf("\n1)-DELUXE");
	printf("\n2)-MEDIUM");
	printf("\n3)-SMALL");
	printf("\n4)-EXIT\n");
	scanf("%d",&choice);
 	switch(choice)
 	{
 		case 1:		
 			f=fopen("delxueroom.txt","r");
 			t=fopen("TempFile.txt","w");
		
			ch=fgetc(f);
			room=atoi(&ch);
			getch();
			if(room>0)
				{
Label3:		     printf("\nThere are %d rooms are available.  Would you like to proceed Yes or No?",room);
				 scanf("%s",confirmation);
				 if(stricmp(confirmation,yes)==0)
				 {				 
				 --room;	 				 
				 itoa(room,&ch,10);				 
			     fputc(ch,t);
			     booking();
			     system("cls");
				 printf("\nYour booking has been confirmed .Your room number will be %d",room++);
				 getch();
				}
				else if(stricmp(confirmation,no)==0)
				{
				 goto Label2;	
				}
				else
				{printf("Wrong Input");
				 system("cls");
				 goto Label3;
				}
			}
			else
				{
					printf("ROOM NOT AVAILABLE .Please select another room");
					goto Label2;
				}
			
			fclose(f);
			fclose(t);
			remove("delxueroom.txt");
			rename("TempFile.txt","delxueroom.txt");
			fclose(f);
			fclose(t);
			break;
		case 2:		
			f=fopen("medium.txt","r");
			t=fopen("TempFile.txt","w");
	
			ch=fgetc(f);
			room=atoi(&ch);
			
			if(room>3 )
				{
Label4:			printf("\nThere are %d rooms are available.  Would you like to proceed Yes or No?",room-3);
				 scanf("%s",confirmation);
				 if(stricmp(confirmation,yes)==0)
				 {				 
				 --room;	 				 
				 itoa(room,&ch,10);				 
			     fputc(ch,t);
			     booking();
			     system("cls");
				 printf("\nYour booking has been confirmed .Your room number will be %d",room++);
				}
				else if(stricmp(confirmation,no)==0)
				{
				 goto Label2;	
				}
				else
				{printf("Wrong Input");
				 system("cls");
				 goto Label4;
				}
				
				}
				else
				{
					printf("ROOM NOT AVAILABLE .Please select another room");
					goto Label2;
				}
			
			fclose(f);
			fclose(t);
			remove("medium.txt");
			rename("TempFile.txt","medium.txt");
			fclose(f);
			fclose(t);
			break;
		case 3:
			f=fopen("small.txt","r");
			t=fopen("TempFile.txt","w");

			ch=fgetc(f);
			room=atoi(&ch);
			getch();
			if(room>6)
				{			
Label5:				 printf("\nThere are %d rooms are available.  Would you like to proceed Yes or No?",room-6);
				 scanf("%s",confirmation);
				 if(stricmp(confirmation,yes)==0)
				 {				 
				 --room;	 				 
				 itoa(room,&ch,10);				 
			     fputc(ch,t);
			     booking();
			     system("cls");
				 printf("\nYour booking has been confirmed .Your room number will be %d",room++);
				}
				else if(stricmp(confirmation,no)==0)
				{
				 goto Label2;	
				}
				else
				{printf("Wrong Input");
				 system("cls");
				 goto Label5;
				}
				}
			else
				{
					printf("ROOM NOT AVAILABLE .Please select another room");					
					goto Label2;
				}
			
			fclose(f);
			fclose(t);
			remove("small.txt");
			rename("TempFile.txt","small.txt");
			fclose(f);
			fclose(t);
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong choice");
			goto Label2;
	
	}
	adminloginbook();
}

void existinguser()
{
		int value=0;
	do
	{		
		FILE *f;
		char username[20];
		char userpassword[20];
		long int size=sizeof(l);
		if((f=fopen("login.txt","r+"))==NULL)
			exit(0);
			fflush(stdin);
		system("cls");
		printf("Enter Username\n");
		scanf("%s",username);
		fflush(stdin);
		printf("Enter password\n");
		scanf("%s",userpassword);
			
			while(fread(&l,sizeof(l),1,f)==1)
			{
				if((strcmp(l.name,username)==0)&&(strcmp(l.password,userpassword)==0))
				{
					value=1;
					int choice=1;
					printf("\nLogin success");
					getch();
					do{
					printf("\n\t\t**************************************************");
     				printf("\n\t\t Select one of the options:- ");
  	 				printf("\n\t\t 1)Booking ");
  	 				printf("\n\t\t 2)Cancellation");
  	 				printf("\n\t\t 3)View ur details");
  	 				scanf("%d",&choice);
  	 				switch(choice)
  	 				{
  	 				case 1:
  	 					printf("case 1");
						avail();
					    break;
					case 2:
						cancellation();
						break;
					case 3:
						details();
						break;	
				    default:
				    	printf("Wrong selection");
					}
					}while(choice>3);
					break;
				}
			}
		if(value==0)
		{
		 printf("\nWrong Credentials");
		 printf("\nPlease try again");
		 fclose(f);
		 getch();
		}
	}while(value==0);
}


void newuser()
{
	FILE *f;
	f=fopen("login.txt","a+");
	if(f==0)
	{   f=fopen("login.txt","w+");
		system("cls");
		printf("HOLD ON setting up!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	printf("\n\t Enter your desired username");
	scanf("\n%s",l.name);
	fflush(stdin);
	printf("\n\t Enter your desired password");
	scanf("\n%s",l.password);	
	fwrite(&l,sizeof(l),1,f);
	fflush(stdin);
	fclose(f);	
	existinguser();
}

void adminlogin()
{
	int p=0,i=0;
    char adminname[10],c=' '; 
    char password[10],code[10];
    char admin[10]="abhi";
    char adminpass[10]="1234";
    do
{
	system("cls");
	
    printf("\n\t\t\t  WELCOME ADMIN ");
    printf(" \n\nENTER ADMINNAME:-");
	scanf("%s", &adminname); 
	printf(" \n\nENTER PASSWORD:-");
	while(i<10)
	{
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';//end of the string, values are stored in password variable.if we remove this it will not work

	i=0;//resetting the value again to zero to make it store values since first character
		if(strcmp(adminname,admin)==0 && strcmp(password,adminpass)==0)
	{
	printf("\n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
	admindetails();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		p=1;
		
		getch();
		
	}
}while(p==1);
}





void userlogin()
{
		char choice;
		printf("\t\t\tLOGIN SCREEN");
		printf("\n\n\tPress 1 If you are a New User");
		printf("\n\tPress 2 If you are an Existing User\n");
		printf("\n\tINPUT:-");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				newuser();				
				break;
			case '2':
				existinguser();
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\n Press any key to continue");
				getch();
		}
}

void welcome()
{	
	char choice;
	Label1:printf("\n\t\tLOGIN:-");
    printf("\n\t1)USER");
    printf("\n\t2)ADMIN");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case '1':
				userlogin();
				break;
			case '2':
				adminlogin();
				break;
			default:
				system("cls");
				printf("Wrong input");
				printf("\n Press any key to continue");
				getch();
				goto Label1;
		}
    getch();
   
}

int main()
{ 	
	system("cls"); 
 	printf("\t\t*************************************************\n");
 	printf("\t\t*************************************************\n");
	printf("\t\t*       Introduction to C programming           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        Hotel Management System.           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t\t\t BY-");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n");
	printf("\t\t*************************************************\n");
	printf(" \n Press any key to continue:");	
	getch();	
    system("cls");
    welcome();
 
}

