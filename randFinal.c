#include <stdio.h>
#include <stdlib.h>

char getAdj();
char getNoun();
//creates functions for getting random adjectives and nouns

char randNoun[20];
char randAdj[20];
//creates global variables for random adjectives and nouns

int main(int argc, char *argv[]) {

int i;	
for(i=1; i<=7; i++){
//repeats proceeding actions 7 times
	
	srand(time(0));
	//seeds random number generator 	
	
	getAdj();
	printf("%s", randAdj);
	//reads a new adjective and prints it
	
	getNoun();
	printf("%s\n", randNoun);
	//reads a new noun and prints it
	
	sleep(2);
	//small wait period to make words more random (rng is based on internal clock)
}

	getNoun();
	printf("%s", randNoun);
	sleep(2);
	getNoun();
	printf("%s???", randNoun);
	//reads and prints two consequitive nouns with a short space for rng and question marks for accuracy???
	
	return 0;		
}

char getAdj(){
	
	int lineNum;
	int count;
	int x;
	
		count = (rand()%1347);
		x = (rand()%1347);
		count = count + x;
		//creates a random number and performs operations to ensure a more random outcome after many repetitions
	
		if(count>1347){
			count = (count-1347);	
		}
		//keeps the random result within the 1347 lines of adjectives
	
	char line[20];
	
	static const char filename[] = "englishAdj.txt";
	FILE *file = fopen(filename, "r");
	//defines the text file and opens it for reading in the program
	
	while(fgets(line, sizeof(line), file) != NULL)
	//while loop that continues until the end of the file
	{
		if(count==lineNum)
		//test to see if we have reached the desired line
		{
			strcpy(randAdj, line);
			//copies line to global variable
			lineNum++;
			//moves on to next line
		}
		else
		{
			lineNum++;
			//moves on to next line
		}
	}
	fclose(file);
	
	return 1;
}

char getNoun(){
	
	int lineNum;
	int count;
	int x;
	
		count = (rand()%1525);
		x = (rand()%1525);
		count = count + x;
		//creates a random number and performs operations to ensure a more random outcome after many repetitions
	
		if(count>1525){
			count = (count-1525);	
		}
		//keeps the random result within the 1525 lines of nouns
	
	char line[20];
	
	static const char filename[] = "englishNoun.txt";
	FILE *file = fopen(filename, "r");
	//defines the text file and opens it for reading in the program
	
	while(fgets(line, sizeof(line), file) != NULL)
	//while loop that continues until the end of the file
	{
		if(count==lineNum)
		//test to see if we have reached the desired line
		{
			strcpy(randNoun, line);
			//copies line to global variable
			lineNum++;
			//moves on to next line
		}
		else
		{
			lineNum++;
			//moves on to next line
		}
	}
	fclose(file);
	
	return 1;
}


