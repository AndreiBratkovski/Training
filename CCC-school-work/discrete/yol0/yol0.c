/////////////////////////////////////////////
//
// Andrei Bratkovski - YOLO! Card processing
// 11/6/17
//
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Declaring our prototype card functions
// If, algorithmic, and ternary versions of card name to number
// and number to card name
//
char *num2name_if(unsigned char);
char *num2name_tern(unsigned char);
char *num2name_algo(unsigned char);
unsigned char name2num_if(char *);
unsigned char name2num_tern(char *);
unsigned char name2num_algo(char *);


//
// Initialize an array of the List of cards in order as specified in project
// specifications.  Clubs, Diamonds, Hearts, Spades, 1-King for each suit
//
char *cardList[] = {
	"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC",
	    "KC",
	"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD",
	    "KD",
	"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH",
	    "KH",
	"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS",
	    "KS"
};

//
// Main function used to drive the program as well as offer the user
// a menu
//
int main()
{
	///////////////////////////////////////////////
	// MENU
	// Prompt user with menu for which asks which 
	// function they want to run
	//
	unsigned char userInput;
	unsigned char output;
	char userString[5];
	char *nameString;
	int functionChoice;

	//
	// Display Menu of function choices for the user
	//
	fprintf(stdout, "WELCOME TO YOLO- YOU ONLY LIVE ONCE- CARD LOGIC PROJECT\n");
	fprintf(stdout, "-Andrei Bratkovski 11/7/17 \n\n");
	fprintf(stdout, "====yol0====\n");
	fprintf(stdout, "1. num2name - if\n");
	fprintf(stdout, "2. num2name - tern\n");
	fprintf(stdout, "3. num2name - algo\n");
	fprintf(stdout, "4. name2num - if\n");
	fprintf(stdout, "5. name2num - tern\n");
	fprintf(stdout, "6. name2num - algo\n");
	fprintf(stdout, "Pick a function betweeen 1 and 6 >>> ");
	scanf("%d", &functionChoice);
	getchar();

	//
	// Check for which function the user wants to use, using
	// a switch case, read in the string or number. Print out the resulting
	// string , representing card name, or unsigned char, representing
	// card number
	//

	switch (functionChoice)
	{
	case 1:
		fprintf(stdout, "Enter a number between 1 and 52 >>> ");
		fscanf(stdin, "%hhu", &userInput);
		nameString = num2name_if(userInput);
		fprintf(stdout, "%s\n", &nameString[0]);
		break;
	case 2:
		fprintf(stdout, "Enter a number between 1 and 52 >>> ");
		fscanf(stdin, "%hhu", &userInput);
		nameString = num2name_tern(userInput);
		fprintf(stdout, "%s\n", &nameString[0]);
		break;
	case 3:
		fprintf(stdout, "Enter a number between 1 and 52 >>> ");
		fscanf(stdin, "%hhu", &userInput);
		num2name_algo(userInput);
		nameString = num2name_algo(userInput);
		fprintf(stdout, "%s\n", &nameString[0]);
		break;
	case 4:
		fprintf(stdout, "Enter a card name >>> ");
		fscanf(stdin, "%s", userString);
		output = name2num_if(userString);
		fprintf(stdout, "%d\n", output);
		break;
	case 5:
		fprintf(stdout, "Enter a card name >>> ");
		fscanf(stdin, "%s", userString);
		output = name2num_tern(userString);
		fprintf(stdout, "%d\n", output);
		break;
	case 6:
		fprintf(stdout, "Enter a card name >>> ");
		fscanf(stdin, "%s", userString);
		output = name2num_algo(userString);
		fprintf(stdout, "%d\n", output);
		break;
	default:
		fprintf(stdout, "Invalid Choice, pick a function from 1-6\n");
		break;
	}

	return 0;

}

/////////////////////////////////////////////////////////////
//  NUM 2 NAME - Convert Card Number to Card Name
//
/////////////////////////////////////////////////////////////

//
// Convert number to its card name using conditional statements
// program iterates 52 times until the counter reaches the same number
// as the input number.  Then program points nameString to the card which
// correlates with the input number
//
char *num2name_if(unsigned char input)
{
	unsigned char count = 0;
	int increment = 0;
	int increment2 = 0;
	char *nameString;

	for (increment = 0; increment < 4; increment++)
	{
		for (increment2 = 0; increment2 < 13; increment2++)
		{
			count += 1;

			if (input == count)
			{
				nameString = cardList[count - 1];
			}
		}
	}
	return nameString;
}

//
// Convert number to its card name checking with ternary statements
// program iterates 52 times until the input number matches the counter
// when they agree, the program assigns name string to the card which correlates
// and returns that string.  the 0 is there to in the ternary to allow the program to
// continue iterating over the loop
//
char *num2name_tern(unsigned char input)
{
	unsigned char count = 0;
	int increment = 0;
	int increment2 = 0;
	char *nameString;

	for (increment = 0; increment < 4; increment++)
	{
		for (increment2 = 0; increment2 < 13; increment2++)
		{
			count += 1;
			(input == count) ? (nameString =
					    cardList[count - 1]) : 0;

		}
	}
	return nameString;
}

//
// Convert number to card name using only mathematical expressions
// point char string at the card in card list which agrees with the input
// char.  Simplest mathematical way of pulling out the card name.  The input directly
// correlates with the cardList element
//
char *num2name_algo(unsigned char input)
{
	char *nameString;

	nameString = cardList[input - 1];

	return nameString;
}
/////////////////////////////////////////////////////////////
//	NAME 2 NUM	Convert Card Name to Num
//	
/////////////////////////////////////////////////////////////

//
// Convert card name to card Number using conditional statements
// Program iterates from 0 to 51, checking until input string matches
// card name string.  Once that occurs, output is increment by 1 to match
// the card number and returned
//
unsigned char name2num_if(char *card)
{
	unsigned char increment = 0;
	char str1[5];
	char str2[5];

	strcpy(str2, card);
	for (increment = 0; increment < 52; increment++)
	{
		strcpy(str1, cardList[increment]);
		if (strcmp(str1, str2) == 0)
			break;
	}
	increment++;
	return increment;
}

//
// Convert card name to card Number using ternary statements
// Continue copying and comparing card List strings until the strings
// match, then return the card number at first match 
//
unsigned char name2num_tern(char *card)
{
	unsigned char increment = 0;
	unsigned char output = 0;

	char str1[5];
	char str2[5];

	strcpy(str2, card);

	while (increment <= 52)
	{
		strcpy(str1, cardList[increment]);
		(strcmp(str1, str2) == 0) ? (output = increment) : 0;
		increment++;
	}
	output++;
	return output;
}

//
// Convert card name to card number using only mathematical expressions
// Create string copies and compare them until both the card name and input match
//
unsigned char name2num_algo(char *card)
{
	unsigned char increment = 0;
	char str1[5];
	char str2[5];

	strcpy(str2, card);
	while (strcmp(str1, str2) != 0)
	{
		strcpy(str1, cardList[increment]);
		increment++;
	}
	return increment;
}
