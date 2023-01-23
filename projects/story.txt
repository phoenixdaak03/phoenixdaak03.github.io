//Phoenix Daak
//CSE 103-01
//Lab 5
//02/18/22


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int choice;
	do 
	{
		//menu
		printf("\n\n\t\tThe Code of Stories");
		printf("\n\n1. Generate Story");
		printf("\n\n0. Exit The Code of Stories");
		printf("\n\nPick your poison:");
		scanf("%d", &choice);
		
		if (choice ==1)
		{
		
		//inputs
		char name[50];
		char eyecolor[50];
		char color[50];
		char car[50];
	
		//gathering inputs
		printf("\n\nEnter your name:");
		scanf("%s", name);
		printf("Enter your eye color:");
		scanf("%s", eyecolor);
		printf("Enter your favorite color:");
		scanf("%s", color);
		printf("Enter your dream car:");
		scanf("%s", car);
	
		//arrys of strings with pointers
		char *phrase1[3] = {"clown", "ogre", "grimlin"};
		char *phrase2[3] = {"castle", "dungeon", "doghouse"};
		char *phrase3[3] = {"burgers", "sushi", "pizza"};
		char *phrase4[3] = {"a Computer Science Engineer for Dr. Roman V. Yampolskiy", "a fry cook for Mr. Krabs", "a NBA basketball player for the Heat" };
		char *phrase5[3] = {"The Big Bang Theory", "The Office", "Friends"};
		char *phrase6[3] = {"flies", "drives", "sails"};
	
		//gathering a random number to generate a story
		srand(time(0));
		int randchoice1 = rand()%3;
		int randchoice2 = rand()%3;
		int randchoice3 = rand()%3;
		int randchoice4 = rand()%3;
		int randchoice5 = rand()%3;
		int randchoice6 = rand()%3;
		int randchoice7 = rand()%3;
		
		//formatting the story
		printf("\n\n\tOnce apon a time there was a %s %s named %s. ", eyecolor, phrase1[randchoice1], name);
		printf("%s grew up and lived in a %s their whole life.", name, phrase2[randchoice2]);
		printf(" Everyday for dinner, they would eat %s ", phrase3[randchoice3]);
		printf("while watching %s.", phrase5[randchoice4]);
		printf(" %s's daily job was %s. ", name, phrase4[randchoice5]);
		printf("Everyday after work, %s %s their %s back home to their %s to get a good night's rest.", name, phrase6[randchoice6], car, phrase2[randchoice7]);
		printf("\n\n\t\tThe end...\n\n");
		}		
	
	}
	while (choice != 0);
	return 0;

}
