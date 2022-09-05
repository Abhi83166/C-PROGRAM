//below are the header files that were used in the program

#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
//Below is the structure named record where there are different data types are used to store the values for required parameters.
struct record
{
	char name[20];
	char servicedate[20];
	char registeration[20];
	int ser;
	int type;
	int id;

}r;



// Below function is the void type named menu where the functionality of the function is to show the menu to the user and take the input
//and store the values in the assigned variables.
void menu()
{
	int option;
	int fee;
Loop1:
	printf("---------------------------------------------------------------------------------\n");
	printf("|Number|		Service Type		| Time needed |   Service Fee	|\n");
	printf("|      |					| (minutes)   | Normal(1) | Urgent(2) |\n");
	printf(" 1       Repair punctured car tyre/piece	    10		 RM 5	  RM 6\n");
	printf(" 2       Car tyre change/ piece			    15		 RM 150   RM 160\n");
	printf(" 3       Mineral Oil change			    20		 RM 80    RM 90\n");
	printf(" 4       Synthetic oil change			    20		 RM 130   RM 140\n");
	printf(" 5       Battery change				     5		 RM 200   RM 210\n");
	printf(" 6       Head light Bulb change/ piece	             5		 RM 6     RM 8\n");
	printf(" 7       Tail light Bulb change/ piece	             5		 RM 6     RM 8\n");
	printf(" 8       Car wash	                            10		 RM 10    RM 12\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("Enter your service :- ");
	scanf("%d", &option);
	printf("Enter your Service type :- ");
	scanf("%d", &fee);
	
	//below if condition make sure that the user input is valid if invalid the program will ask for correct output.

	if (option > 0 && option <= 8)
	{
		switch (option)
		{
		case 1:
			
			r.ser = 1;
	
			if (fee == 1)
				r.type = 5;
			else
				r.type = 6;
			break;
		case 2:
		
			r.ser = 2;
	
			if (fee == 1)
				r.type = 150;
			else
				r.type = 160;
			break;
		case 3:
		
			r.ser = 3;
	
			if (fee == 1)
				r.type = 80;
			else
				r.type = 90;
			break;
		case 4:
		
			r.ser = 4;
	
			if (fee == 1)
				r.type = 130;
			else
				r.type = 140;
			break;
		case 5:
		
			r.ser = 5;
	
			if (fee == 1)
		
				r.type = 200;
			else
				r.type = 210;
			break;
		case 6:
	
			r.ser = 6;
	
			if (fee == 1)
				r.type = 6;
			else
				r.type = 8;
			break;
		case 7:
			r.ser = 6;
			//r.serv = "Tailight bulb change";
			if (fee == 1)
				r.type = 6;
			else
				r.type = 8;
			break;
		case 8:
			r.ser = 6;
			//r.serv = "Car wash";
			if (fee == 1)
				r.type = 10;
			else
				r.type = 12;
			break;


		default:
			break;
		}
	}
	else
	{
		printf("Wrong choice");
		_getch();
		system("cls");
		goto Loop1;

	}
}



/*
below function performs the file handling and generates a seperate invoice for each user
*/

void booking()
{
	FILE* fp; int value;
	printf("\n Enter Customer name:-");
	scanf("%s", &r.name);
	printf("\n Enter Service date:-");
	scanf("%s", &r.servicedate);
	fflush(stdin);
	printf("\nEnter registeration number:-");
	scanf("%s", &r.registeration);
	fflush(stdin);
	menu();
	fp = fopen("idnumber.txt", "r+"); // read mode

	if (fp == NULL)//if there will be no file and no data inside the file it will show the error
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	fscanf(fp, "%d", &value);//reading the id from the file
	fclose(fp);

	value++;
	printf("\n value is :- %d", value);

	r.id = value;
	
	fp = fopen("idnumber.txt", "w");
	//writing operation
	fprintf(fp, "%d", value);
	fclose(fp);
	
	printf("\n%s, %s, %s, %d, %d, %d\n", &r.name, &r.servicedate, &r.registeration, r.ser, r.type, r.id);//
	
	char filename[30];
	strcpy(filename, r.name);
	strcat(filename, ".txt");
	FILE* invoice;
	invoice = fopen(filename, "w");
	fprintf(invoice, "%d %s %s %s %d %d", r.id, &r.name, &r.registeration, &r.servicedate, r.ser, r.type);
	fclose(invoice);

}


void main()
{
	int contchoice=1;
	while (contchoice == 1)
	{
		booking();
		/*int value = 0;
		FILE* f;
			f=fopen("idnumber.txt","a+");
				if(f==0)
			{   f=fopen("idnumber.txt","w+");
			system("cls");
		   }

			//fwrite(&r,sizeof(r),1,f);
			fprintf(f, "%d", value);
			fflush(stdin);
			fclose(f);
			exit(0);

		*/
		printf("Do you want to continue? 1 for yes 2 for no");
		scanf("%d", &contchoice);
		
	}
	system("pause");
}

