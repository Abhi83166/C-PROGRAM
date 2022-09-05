#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	val = 0;
	File* fp; // creates a pointer to a file
	fp = fopen("idnumber.txt", "r+"); //opens file with read-write permissions


	fprintf(fp, "%d", val);         //write contents to file
	fclose(fp);
}