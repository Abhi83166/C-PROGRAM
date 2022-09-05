//Standard header files required for C program
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include <stdbool.h>
//Structure created to srore the data in the vaccine.txt file
struct inventory
{
	char Vaacinecode[3];
	char vaccinename[13];
	char ProducingCountry[6];
	char DosageRequired[2];
	char PopulationCovered[5];
	int quantity;	
}i;
//structure for distribution 
struct distribution
{
	char vaccinecode[3];
	char hospitalname[10];
	int distributedquanitiy;
}d;
// Structure for listing
typedef struct listing
{
	char vaccinecode[3];
	char hospitalname[10];
	int distributedquanitiy;

}listing;
const char* write_format = "%s %s %s %s %s %d\n";
const char* read_format = "%s %s %s %s %s %d";

char buffer[500];
/*
distlist function is for 4th requirement of the assignment
it creates another instance of the structure name temp, create the file pointer for performing 
operation on dist.txt file open in read mode. Read the file until the last data in the file
stores the file in the structure array, icrement the array index variable after every iteration
Once the data is stored it apply the Bubble sort algorithm to the data and provide the ouptut
*/
//void distlist()
//{
//	struct listing temp;
//	FILE* fp;
//	int i = 0, size, j;
//	
//	fp = fopen("dist.txt", "r");
//	
//	if (fp == NULL)
//	{
//		printf("\n Cannot open the file \n");
//		
//	
//	}
//
//	while (fread(&l, sizeof(l), 1, fp) == 1)
//	{
//
//		printf("%s%s%s", l[i].vaccinecode, l[i].hospitalname, l[i].distributedquanitiy);
//		i++;
//		printf("IN");
//	}
//	fclose(fp);
//	size = i - 1;
//	printf("Size %d", &size);
//	for (i = 1; i < size; ++i)
//	{
//		printf("in");
//		for (j = 0; j < size - i; j++)
//		{
//			if (l[j + 1].distributedquanitiy < l[j].distributedquanitiy)
//			{
//				temp = l[j];
//				l[j] = l[j + 1];
//				l[j + 1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < size; i++) {
//	
//		printf("%s %s %s \n", l[i].vaccinecode, l[i].hospitalname, l[i].distributedquanitiy);
//		
//	}
//	
//	_getch();
//	
//}

/*
creation function is used to take inputs for the detials of the vaccine and store the data in the
vaccine.txt file, the file pointer check whether the file is availaible or not if availaible the 
file is open in append mode else in write mode.

*/



void creation()
{

	printf("\n Enter Vaccine name:-");
	scanf("%s", &i.vaccinename);
	printf("\n Enter Vaccine Code:-");
	scanf("%s", &i.Vaacinecode);
	printf("\nEnter Producing Country:-");
	scanf("%s", &i.ProducingCountry);
	printf("\n Enter Dosage required:-");
	scanf("%s", &i.DosageRequired);
	printf("\n Enter Population Covered:-");
	scanf("%s", &i.PopulationCovered);
	printf("\n Enter Initial Quantity:-");
	scanf("%d", &i.quantity);
	FILE* f;
	f = fopen("vaccine.txt", "a+");
	if (f == 0)
	{
		f = fopen("vaccine.txt", "w+");
		system("cls");
		printf("HOLD ON setting up!!");
		printf("\n Process completed press any key to continue!! ");
		_getch();
	}
	fprintf(f, write_format, i.Vaacinecode, i.vaccinename, i.ProducingCountry, i.DosageRequired, i.PopulationCovered, i.quantity);
	
	fclose(f);
	system("cls");
	_getch();
}

/*
vaccinecodeavailibility function takes two variables as parameters, one variabel which will acts
as condition for the availaibliliy of the vaccine and another is the name of the vaccine. 

*/
void vaccinecodeavailaibility(int *value,char *vaccinecodeu)
{
	

	FILE* f;
	
	f = fopen("vaccine.txt", "r+");
	
	if ((f = fopen("vaccine.txt", "r")) == NULL)
		exit(0);
	while (fgets(buffer, 500, f))
	{
		
		sscanf(buffer, read_format, i.Vaacinecode, i.vaccinename, i.ProducingCountry, i.DosageRequired, i.PopulationCovered, &i.quantity);

		if (strcmp(i.Vaacinecode, vaccinecodeu) == 0) {
			*value = 0;
			
		}
	
	}
	fclose(f);



}	

/*
update function update the vaccine quanity based on the user selection. when user selects receive
the new quantity is added to the previous while for distribution the overall qunatiy is substraced. 
*/
void update()
{
	int value = 1;
	FILE* fpt;
	FILE* fpo;
	char vaccinecodeu[3];
//	char comparevaccine[3];
	bool selection = true;
	int inner = 0;
	int choice, amount, prevamount, newamount;
	printf("Enter the Vaccine code to update: \n");
	scanf("%s", vaccinecodeu);
	fflush(stdin);
	vaccinecodeavailaibility(&value, vaccinecodeu);
;
	if (value == 1)
	{
		printf("vaccine code %s is not available in the file", vaccinecodeu);
	}
	else
	{
		while (selection)
		{
			printf("\nSelect: \n 1:Vaccine received \n 2:Distribution received \n:-");
			scanf("%d", &choice);
			
			if (choice == 1 || choice == 2)
			{
				if (choice == 1)
				{
					selection = false;
					printf("Enter the amount received:-");
					scanf("%d", &amount);
					fpt = fopen("vaccine.txt", "r+");
					long int size = sizeof(fpt);
					while (fgets(buffer, 500, fpt))
					{
						sscanf(buffer, read_format, i.Vaacinecode, i.vaccinename, i.ProducingCountry, i.DosageRequired, i.PopulationCovered, &i.quantity);
						if (strcmp(i.Vaacinecode, vaccinecodeu) == 0)
						{
					
							prevamount = i.quantity;
							newamount = prevamount + amount;
							i.quantity = newamount;
							fseek(fpt, -size, SEEK_CUR);
							fwrite(&i, size,1,fpt);
							fclose(fpt);
							break;
							
						}
					}

				}
				else
				{
					selection = false;
					printf("Enter the amount needs to be distributed:-");
					scanf("%d", &amount);
					fpt = fopen("vaccine.txt", "r+");
					
					while (fread(&i, sizeof(i), 1, fpt) == 1)
					{
						if (strcmp(i.Vaacinecode, vaccinecodeu) == 0)
						{
							
							prevamount = i.quantity;
							if (prevamount < amount)
							{
								inner = 1;
								printf("The amount entered is greater than the reserved amount. The operation cannot be performed try again\n");
								break;
							}
							else {
								newamount = prevamount - amount;
								i.quantity = newamount;
								fseek(fpt, -20, SEEK_CUR);
								fputs(i.quantity, fpt);
								fclose(fpt);
								break;
								
							}
						}
					}
					
					
					if (inner == 0)
					{
						fpo = fopen("dist.txt", "a+");
						if (fpo == 0)
						{
							fpo = fopen("dist.txt", "w+");
							system("cls");
							printf("HOLD ON setting up!!");
							printf("\n Process completed press any key to continue!! ");
							_getch();
						}

						printf("Enter the Hospital name where the vaccine will be distributed:-");
						scanf("%s", &d.hospitalname);
						d.distributedquanitiy = amount;
						strcpy(d.vaccinecode, vaccinecodeu);
						fwrite(&d, sizeof(d), 1, fpo);
					
						fclose(fpo);
						system("cls");
						_getch();
					}
				}
			}
			else
			{
				printf("Please enter 1 or 2");
			
			}
			
		}
		
		
	}
	_getch();
	system("cls");
}
/*


*/

void searchvaccine()
{
	FILE* f;
	char vaccinecode[3];
	
	f = fopen("vaccine.txt", "r");
	int value = 1;
	if ((f = fopen("vaccine.txt", "r")) == NULL)
		exit(0);
	printf("Enter the Vaccine code to search for the vaccine: \n");
	scanf("%s",vaccinecode);


	while (fgets(buffer, 500, f))
	{
		sscanf(buffer, read_format, i.Vaacinecode, i.vaccinename, i.ProducingCountry, i.DosageRequired, i.PopulationCovered, &i.quantity);
		if (strcmp(i.Vaacinecode, vaccinecode) == 0) {
			value = 0;
			printf("The details are \n");
			printf("\n Name of Vaccine \tVaccineCode \tProducing Country \tDosage required \tPopulation Covered \tDosage left");
			printf("\n \t%s \t\t%s \t\t%s \t\t\t%s \t\t\t%s \t\t\t%d", i.vaccinename,i.Vaacinecode,i.ProducingCountry,i.DosageRequired,i.PopulationCovered,i.quantity);
		
		}
	
	}

	fclose(f);
	
	if (value == 1) {
		printf("\n\tRequested Vaccine could not be found!");
		
	}

	_getch();
	system("cls");


}
void mainmenu()
{
	system("cls");
	printf("\t\t*****************\n");
	printf("\t\t*****************\n");
	printf("\t\t*       Introduction to C programming           *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*        Vaccine inventory Management System.   *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t\t\t BY-");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*****************\n");
	printf("\t\t*****************\n");
	printf(" \n Press any key to continue:");
	_getch();
	system("cls");
	while (TRUE)
	{
		int choice;    /* The user input choice */
		do {
			printf("MENU\n"
				"1. Inventory Creation\n"
				"2. Update Vaccine Quantities\n"
				"3. Search Vaccine\n"
				"4. List Vaccine\n"
				"5. Exit\n"
				"Enter your option: ");
		} while (scanf("%d", &choice) == 0 && choice >= 1 && choice <= 4);

		switch (choice)
		{
		case 1:
			creation();
			break;
		case 2:
			update();
			break;
		case 3:
			searchvaccine();
			break;
		case 4:
		/*	FILE* f;
			char file[20][4];
			int i = 0;
			f = fopen("dist.txt", "r");
			if ((f = fopen("dist.txt", "r")) == NULL)
				exit(0);
			while (fread(&d, sizeof(d), 1, f) == 1)
			{
				printf("%s %s %d \n",d.vaccinecode,d.hospitalname,d.distributedquanitiy );
				file[i][0] = d.vaccinecode;
				file[i][1] = d.hospitalname;
				file[i][2] = d.distributedquanitiy;
				i++;
				printf(" %s %s %d", file[i][0], file[i][1], file[i][2]);
			}*/
	/*		for (i = 0; file[i] != '\0'; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					printf("%s", file[i][j]);

				}
				}*/
		//	fclose(f);
		
			
			break;
		case 5:
			exit(0);
			break;


		}


	}
}

void main()
{
mainmenu();



}