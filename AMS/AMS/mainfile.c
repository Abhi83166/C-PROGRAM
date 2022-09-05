
//Standard header files required for C program
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include <stdbool.h>
//Structure created to store 
struct creation
{
	int id;
	char partname[15];
	int quantity;
}c;


struct supplier
{
	int id;
	char supplier[10];
	char partname[15];
	int quantity;
}s;

const char* write_format = "%d %s %d\n";
const char* read_format = "%d %s %d";
const char* write_format_s = "%d %s %s %d\n";
const char* read_format_s = "%d %s %s %d";

char buffer[500];

//creation of structure for parts
void creation()
{

	FILE* f;
	system("cls");
	printf("Enter the part name\n");
	scanf("%s", c.partname);
	printf("Enter the part id\n");
	scanf("%d", &c.id);
	printf("Enter the quantity\n");
	scanf("%d", &c.quantity);
	f = fopen("partsinventory.txt", "a+");
	if(f == 0)
	{
		f = fopen("partsinventory.txt", "w+");
		system("cls");
		printf("HOLD ON setting up!!");
		printf("\n Process completed press any key to continue!! ");
		_getch();
	}
	fprintf(f, write_format, c.id, c.partname,c.quantity);
	fclose(f);
	system("cls");
	_getch();
}


void partsinventorycreation()
{
	int warehousenumber;
	system("cls");
	printf("\n\n SELECT WAREHOUSE:-\n1) W1\n2)W2 \n3)W3\n:-");
	scanf("%d", &warehousenumber);
	FILE* f;

	switch (warehousenumber)
	{
	case 1:

		f = fopen("W1parts.txt", "a+");
		if (f == 0)
		{
			f = fopen("W1parts.txt", "w+");
			system("cls");
			printf("setting up!!");
			printf("\n Process completed press any key to continue!! ");
			_getch();
		}
		creation();
		fprintf(f, write_format, c.id, c.partname, c.quantity);
		fclose(f);

		break;

	case 2:

		f = fopen("W2parts.txt", "a+");
		if (f == 0)
		{
			f = fopen("W2parts.txt", "w+");
			system("cls");
			printf("setting up!!");
			printf("\n Process completed press any key to continue!! ");
			_getch();
		}
		creation();
		fprintf(f, write_format, c.id, c.partname, c.quantity);
		fclose(f);

		break;
	case 3:

		f = fopen("W3parts.txt", "a+");
		if (f == 0)
		{
			f = fopen("W3parts.txt", "w+");
			system("cls");
			printf("setting up!!");
			printf("\n Process completed press any key to continue!! ");
			_getch();
		}
		creation();
		fprintf(f, write_format, c.id, c.partname, c.quantity);
		fclose(f);

		break;
	}

}


void suppliercreation()
{
	FILE* f;
	f = fopen("suppliers.txt", "a+");
	if (f == 0)
	{
		f = fopen("suppliers.txt", "w+");
		system("cls");
		printf("setting up!!");
		printf("\n Process completed press any key to continue!! ");
		_getch();
	}
	printf("Enter the part name\n");
	scanf("%s", s.partname);
	printf("Enter the part id\n");
	scanf("%d", &s.id);
	printf("Enter the part quantity\n");
	scanf("%d", &s.quantity);
	printf("Enter the supplier name\n");
	scanf("%s", s.supplier);
	fprintf(f, write_format_s, s.id, s.supplier, s.partname, s.quantity);
	fclose(f);

}

void supplierdetails()
{
	system("cls");
	FILE* f;

	f = fopen("suppliers.txt", "r+");

	if ((f = fopen("suppliers.txt", "r")) == NULL)
		exit(0);
	while (fgets(buffer, 500, f))
	{

		sscanf(buffer, read_format_s, &s.id,s.supplier, s.partname, &s.quantity );
		printf("\nSupplier\t\tPartname\t\tID\tQUANTITY");
		printf("\n%s \t\t\t%s \t\t\t%d \t%d", s.supplier, s.partname, s.id, s.quantity);

	}
	fclose(f);
	_getch();

}


void suppliersdetails()
{
	char choice;
	printf("\n\t1) Supplier inventory creation");
	printf("\n\t2) Supplier details");
	printf("\nINPUT:-");
	choice = _getche();
	choice = toupper(choice);
	system("cls");
	switch (choice)
	{
	case '1':
		suppliercreation();
		break;
	case '2':
		supplierdetails();
		break;
	default:
		printf("\n Wrong input");
		system("cls");
		_getch();
		supplierdetails();

	}
}


void partsavailaibility(int* value, int* partcode)
{
	printf("I m In");

	FILE* f;

	f = fopen("suppliers.txt", "r+ ");

	if ((f = fopen("suppliers.txt", "r")) == NULL)
		exit(0);
	while (fgets(buffer, 500, f))
	{

		sscanf(buffer, read_format_s, s.id, s.supplier, s.partname, s.quantity);

		if (s.id == partcode ) {
			*value = 0;

		}

	}
	fclose(f);



}


void partsordering()
{

	int value = 1;

	FILE* fpt;
	
	int partcode;

	bool selection = true;

	int inner = 0;
	int choice, amount, prevamount, newamount;
	system("cls");
	printf("Enter the part id to be order(deliver or received: \n");
	scanf("%d", &partcode);
	fflush(stdin);
	partsavailaibility(&value, &partcode);

	if (value == 1)
	{
		printf("Part id %d is not available in the file", partcode);
	}

	else

	{
		while (selection)
		{
			printf("\n\t1)Receiving Parts");
			printf("\n\t2)Delivering Parts");
			scanf("%d", &choice);

			if (choice == 1 || choice == 2)
			{
				if (choice == 1)
				{
					selection = false;
					printf("Enter the amount received:-");
					scanf("%d", &amount);
					fpt = fopen("supplier.txt", "r+");
					long int size = sizeof(fpt);
					while (fgets(buffer, 500, fpt))
					{
						sscanf(buffer, read_format_s, &s.id, s.supplier, s.partname, &s.quantity);

						if (s.id == partcode)
						{

							prevamount = s.quantity;
							newamount = prevamount + amount;
							s.quantity = newamount;
							fseek(fpt, -size, SEEK_CUR);
							fwrite(&s, size, 1, fpt);
							fclose(fpt);
							break;

						}
					}


				}
				else {

					selection = false;
					printf("Enter the amount needs to be distributed:-");
					scanf("%d", &amount);
					fpt = fopen("suppliers.txt", "r+");

					while (fread(&s, sizeof(s), 1, fpt) == 1)
					{
						if (s.id == partcode)
						{

							prevamount = s.quantity;
							if (prevamount < amount)
							{
								inner = 1;
								printf("The amount entered is greater than the reserved amount. The operation cannot be performed try again\n");
								break;
							}
							else {
								newamount = prevamount - amount;
								s.quantity = newamount;
								fseek(fpt, -20, SEEK_CUR);
								fputs(&s.quantity, fpt);
								fclose(fpt);
								break;

							}
						}


					}

				}


			}
			else
			{
				printf("Please enter 1 or 2");

			}


		}
		_getch();
		system("cls");

	}


}

void partsinventoryupdate()
{
	char choice;
	
	printf("\n\t1) Supplier Details");
	printf("\n\t2) Parts ordering");
	printf("INPUT:-");
	choice = _getche();
	choice = toupper(choice);
	system("cls");

	switch (choice)
	{
	case '1':
		suppliersdetails();
		break;
	case '2':
		partsordering();
		break;
	default:
		printf("\n Wrong input");
		system("cls");
		_getch();
		partsinventoryupdate();
	
	}
}

void partsinventorytracking()
{
//	/*
//	it creates another instance of the structure name temp, create the file pointer for performing
//		operation on suppliers.txt file open in read mode.Read the file until the last data in the file
//		stores the file in the structure array, icrement the array index variable after every iteration
//		Once the data is stored it apply the Bubble sort algorithm to the dataand provide the ouptut
//		*/
//			struct supplier temp;
//			FILE* fp;
//			int i = 0, size, j;
//			
//			fp = fopen("suppliers.txt", "r");
//			
//			if (fp == NULL)
//			{
//				printf("\n Cannot open the file \n");
//				
//			
//			}
//		
//			while (fread(&s, sizeof(s), 1, fp) == 1)
//			{
//		
//				printf("%d %s %s %d", s[i].id, s[i].supplier, s[i].partname, s[i].quantity);
//				i++;
//				
//			}
//			fclose(fp);
//
//			size = i - 1;
//			printf("Size %d", size);
//			for(i = 1; i < size; ++i)
//			{
//				printf("in");
//				for (j = 0; j < size - i; j++)
//				{
//					if (s[j + 1].quanitiy < s[j].quanitiy)
//					{
//						temp = s[j];
//						s[j] = s[j + 1];
//						s[j + 1] = temp;
//					}
//				}
//			}
//			for (i = 0; i < size; i++) {
//			
//				printf("%d %s %s %d\n", s[i].id, s[i].supplier, s[i].partname, s[i].quantity);
//				
//			}
//			
//			_getch();
//			
//		
//
//
}

void searchfunctionalities()
{
	FILE* f;
	int partscode;
	f = fopen("suppliers.txt", "r");
	int value = 1;
	if ((f = fopen("suppliers.txt", "r")) == NULL)
		exit(0);
	printf("Enter the id to search : \n");
	scanf("%d", &partscode);


	while (fgets(buffer, 500, f))
	{
		sscanf(buffer, read_format_s, &s.id, s.supplier, s.partname,&s.quantity);
		if (s.id == partscode) {
			value = 0;
			printf("The details are \n");
			printf("\n Name of suppliers \tParts Name \tParts ID \tParts quantity");
			printf("\n \t%s \t\t%s \t\t%d \t\t\t%d", s.supplier, s.partname, s.id, s.quantity);

		}

	}

	fclose(f);

	if (value == 1) {
		printf("\n\tRequested id could not be found!");

	}

	_getch();
	system("cls");






}





void menu()

{
	char choice;
	system("cls");
	printf("\t\t\tMENU SELECTION");
	printf("\n\t1)Parts inventory Creation. ");
	printf("\n\t2) Parts inventory Update.\n");
	printf("\n\t3) Parts inventory Tracking.\n");
	printf("\n\t4) Searching Functionalities.\n");
	printf("\n\t5) Exit.\n");

	printf("\n\tINPUT:-");
	choice = _getche();
	choice = toupper(choice);
	switch (choice)
	{
	case '1':
		partsinventorycreation();
		break;
	case '2':
		partsinventoryupdate();
		break;
	case '3':
		partsinventorytracking();
		break;
	case '4':
		searchfunctionalities();
		break;
	case '5':
		exit(1);
	default:
		system("cls");
		printf("Incorrect Input");
		printf("\n Press any key to continue");
		_getch();
	}
	menu();

}


void main()
{

	menu();

}