//Phoenix Daak
//CSE 103-01
//03/10/2022
//Lab 7


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contacts //initialize the structure and the main inputs for this code
{
	char fname[20]; 
	char lname[20];
	char phone_num[20];
	
}profile;



void show_contacts(profile *contacts, int size);//prototype for show_contacts function
void delete_contact(profile *contacts, int size);//prototype for delete_contact function
void alpha_contacts(profile *contacts, int i, int j, int size);//prototype for alphabeticle contacts
void rand_selection(profile *contacts, int size);//prototype for random selection
void search(profile *contacts, int size); //protoype for search for contact
void delete_all(profile *contacts, int size);//prototype for deleting all contacts
void save_to_file(profile *contacts, int size);//ptrototype for files
void import_file(profile *contacts, int size);//prototype for importing files

int main ()
{
	int choice = 0;
	int size;
	int k = 0;
	int j = 0;
	size = 0;
	//size = ptr_2_contacts[0].w;
	
	profile *ptr_2_contacts;
	ptr_2_contacts = malloc(size*sizeof(profile));//initializes dynamic pointer array
	
	//size = ptr_2_contacts[0].w;
	
	do
	{	
		printf("\n\nChoose an option:");//menu
		printf("\n\n\t1. Add a Contact");
		printf("\n\n\t2. Delete a Contact");
		printf("\n\n\t3. Show Contacts");
		printf("\n\n\t4. Find Phone Number");
		printf("\n\n\t5. Randomly Select Contact");
		printf("\n\n\t6. Delete All Contacts");
		printf("\n\n\t7. Save Contacts");
		printf("\n\n\t8. Load Contacts");
		printf("\n\n\t0. Exit");
		printf("\n\n\tChoice:");
		scanf("%d", &choice);
	
		if (choice == 1)
		{
			int i;
			i = size; 
			
			profile *temp;
			
			temp = realloc(ptr_2_contacts, (size+1) * sizeof(profile));//relocates memory and increases the size everytime its ran. 
			
			
			ptr_2_contacts = temp;//copies the temp to the original memory, increasing the size. 
			
			//assigns string to memory
			printf("\n\nEnter first name:");
			scanf("%s", ptr_2_contacts[i].fname);
			printf("\nEnter last name:");
			scanf("%s", ptr_2_contacts[i].lname);
			printf("\nEnter number:");
			scanf("%s", ptr_2_contacts[i].phone_num);
			printf("\n*************************");
		
			
			size++;
			
			alpha_contacts(ptr_2_contacts, i, j, size); //alphabetizing function

		}
		
		if(choice ==2)
		{
			delete_contact(ptr_2_contacts, size);//removes the contact
			size--;//moves other memory up to replace the removed contact
		}
	
		if(choice == 3)
		{
			show_contacts(ptr_2_contacts, size);
		}
		
		if(choice == 4)
		{
			search(ptr_2_contacts, size);
		}
		
		if(choice == 5)
		{
			rand_selection(ptr_2_contacts, size);
		}
		
		if (choice == 6)
		
		{
			free(ptr_2_contacts);
			
			size = 0;
			
			printf("\n\n***ALL CONTACTS REMOVED***");
			printf("\n\n*************************");
			
			//profile *ptr_2_contacts;
			//ptr_2_contacts = malloc(size*sizeof(profile));
			
			
		}
		
		if(choice == 7)
		{
			save_to_file(ptr_2_contacts, size);
		}
		
		if(choice == 8)
		{
			import_file(ptr_2_contacts, size);
		}
	}
	
	while(choice != 0);
	
	free(ptr_2_contacts);
	
	return 0;
}

void delete_all(profile *contacts, int size)
{
	int i;
	for (i = 0; i <= size; i++)
	{
		//free(contacts[i]);
		size = 0;
	}
	
	
}

void show_contacts(profile *contacts, int size)//shows the inputted contacts

{
	int i;
	for(i = 0; i < size; i++)
	{
		//locates the specified structure element for each i value
		printf("\n\nFirst name: %s", contacts[i].fname);
		printf("\n\nLast name: %s", contacts[i].lname);
		printf("\n\nNumber: %s", contacts[i].phone_num);
		printf("\n\n*************************");
	}

}

void delete_contact(profile *contacts, int size)//removes the selected number
{
	int i;
	int selection;
	for(i = 0; i < size; i++)
	{
		
		printf("\n\n%d. First name: %s", i, contacts[i].fname);
		printf("\n\n   Last name: %s", contacts[i].lname);
		printf("\n\n   Number: %s", contacts[i].phone_num);
		
	}
	printf("\n\nSelect profile to delete:");
	scanf("%d", &selection);
	printf("\n\nProfile #%d removed", selection);
	printf("\n\n*************************");
	for (selection; selection < size; selection++)
	{
		contacts[selection] = contacts[selection + 1];
	}
	
}


void alpha_contacts(profile *contacts, int i, int j, int size)//function to alphabetize contacts
{
	//strings to copy the new strings in alphabetical order
	char temp2[20];
	char temp3[20];
	char temp4[20];
			
	for (i = 0; i < size - 1; i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if(strcmp(contacts[i].fname, contacts[j].fname) > 0) //compares the two strings with i and j
				{
					//copying the conacts to the temp strings
					strcpy(temp2, contacts[i].fname);
					strcpy(temp3, contacts[i].lname);
					strcpy(temp4, contacts[i].phone_num);
					
					//redefines the i string to the j string if the comparison is true
					strcpy(contacts[i].fname, contacts[j].fname);
					strcpy(contacts[i].lname, contacts[j].lname);
					strcpy(contacts[i].phone_num, contacts[j].phone_num);
					
					//copies new strings to the temp string
					strcpy(contacts[j].fname, temp2);
					strcpy(contacts[j].lname, temp3);
					strcpy(contacts[j].phone_num, temp4);
				}
				
			}
		
		}
}

void rand_selection(profile *contacts, int size)
{

		srand(time(0));
		
		int random_selection = rand()%size; //assigns a random number from size to random_selection
		
		//prints the structure that the random number points to
		printf("\n\n%d. First name: %s", random_selection, contacts[random_selection].fname);
		printf("\n\n   Last name: %s", contacts[random_selection].lname);
		printf("\n\n   Number: %s", contacts[random_selection].phone_num);
		printf("\n\n*************************");
		
}

void search(profile *contacts, int size)
{
	char first_input[20];
	char second_input[20];
	
	printf("\n\nWho's number are you looking for?");
	printf("\n\nFirst name:");
	scanf("%s", &first_input);
	printf("\n\nLast name:");
	scanf("%s", &second_input);
	
	int i;
	for(i = 0; i < size; i++)
	{
		//compares the inputted value to each string value already inputted
		if(strcmp(contacts[i].fname, first_input) == 0 && strcmp(contacts[i].lname, second_input) == 0) 
		{
			printf("\n\nPhone Number: %s", contacts[i].phone_num);
			printf("\n\n*************************");
		}
	}
}

void save_to_file(profile *contacts, int size)
{
	char choice[5];
	
	printf("\n\nDo you want to name your phonebook file?\n\n");
	
	scanf("%s", choice);
	
	char name[20];
	
	if(strcmp(choice, "yes") == 0)
	{
		printf("\n\nWhat is the file name?\n\n");
		
		scanf("%s", name);
	}
	else
	{
		strcpy(name, "PhoneBook.txt");
	}
	
	FILE* outFile = fopen(name, "w");
	fprintf(outFile, "%d\n", size);

	if(outFile == NULL)
	{
		printf("*****CONTACTS WERE NOT SAVED*****");
	}
	else
	{
	int i;
	for (i = 0; i < size; i++)
	{
		fprintf(outFile, "%s\t", contacts[i].fname);
		fprintf(outFile, "%s\t", contacts[i].lname);
		fprintf(outFile, "%s\n\n", contacts[i].phone_num);
	}
	printf("\n\n*****CONTACTS SAVED*****");
	}
	fclose(outFile);
}

void import_file(profile *contacts, int size)
{
	char choice[5];
	
	printf("\n\nDo you want to pick a file to load from?\n\n");
	
	scanf("%s", choice);
	
	printf("\n");
	
	char name[20];
	
	if(strcmp(choice, "yes") == 0)
	{
		printf("\n\nWhat is the file name?\n\n");
		
		scanf("%s", name);
		
	}
	else
	{
		strcpy(name, "PhoneBook.txt");
	}
	
	char line[255];
	
	FILE* inFile = fopen(name, "r");
	
	fscanf(inFile, "%d", &size);
	
	
	int i;
	if(inFile == NULL)
	{
		printf("*****FILE NOT FOUND*****");
	}
	else
	{
	for (i = 0; i < size; i++)
	{
		while(!feof(inFile))
		{
			fgets(line, 255, inFile);
			printf("%s", line);
		}
	}
	}
	fclose(inFile);
	
}
