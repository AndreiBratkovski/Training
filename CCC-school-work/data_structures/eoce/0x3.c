//////////////////////////////////////////////////////
// Andrei Bratkovski - 0x3 DATA Grade figure outer-er
//
//////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//
// Note: This particular implementation gets the job done for data, however,
// I avoided string formatting specifiers and did NOT follow the DRY principle
// all too well. ( Don't repeat yourself ).  I believe that this is due to my
// burned out stream of consciousness. Anyways, without further ado,
// my grade figure outerer.
//
// P.S. the final grade would have been more accurate, slightly higher, if the
// math.h library was working here, however I could not link it using the compiler
// due to our list.h header.  Therefore, I floored everything.
//
// Lastly, be sure to test this in a directory that can access the list.h library.
// That way the program can work.  A good place would be dlt0/app/list
//
int main()
{
	//
	// Set up file pointer
	//
	FILE *in = NULL;

	//
	// Declare six linked lists to
	// store my grades and the grade totals
	//
	List *myJournalList = NULL;
	List *myPartList = NULL;
	List *myProjList = NULL;

	List *totalJournalList = NULL;
	List *totalPartList = NULL;
	List *totalProjList = NULL;

	//
	// Declare tmp nodes to traverse
	// over the lists for printing later
	//
	Node *tmp = NULL;

	//
	// Attempt to open the data.status.flat file for reading.  If this fails
	// send an error message
	//
	in = fopen("data.status.flat", "r");
	if (in == NULL)
	{
		fprintf(stderr,
			"Error opening 'data.status.flat' for reading. \n");
		exit(1);
	}

	//
	// Create a list for each grading section,
	// (Journal, Participation, Projects ) to put my grades into
	// Then put the totals into 3 more linked lists
	//
	mklist(&myJournalList);
	mklist(&myPartList);
	mklist(&myProjList);

	mklist(&totalJournalList);
	mklist(&totalPartList);
	mklist(&totalProjList);
	//
	// Declare an integer which represents the file integer contents being
	// read into each node. Even or odd is a variable used to determine which
	// linked list I am placing the points into. This splits up the flattened
	// data into totals and my own total
	//
	int fileNumber;
	int evenOrOdd = 1;

	//
	// A very repetetive sequence of loops.  Each integer is scanned out of
	// the flattened data, and checked against the number 127 because mknode
	// can only take a signed char as its second parameter. This caused me to
	// split up chunks of large numbers into smaller chunks so that they could
	// all be read into chars
	//
	while (fileNumber != -2)
	{
		fscanf(in, "%d", &fileNumber);
		if (fileNumber != -1 && fileNumber != -2)
		{
			if (evenOrOdd % 2 == 1)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&myJournalList,
					       myJournalList->caboose, tmp);
					tmp = NULL;
				}
				//
				// This program calls for making a node out of each integer and
				// appending it to the proper list. Total points lists or my total
				// points lists
				//
				mknode(&tmp, fileNumber);
				append(&myJournalList, myJournalList->caboose,
				       tmp);
				tmp = NULL;
			}
			else if (evenOrOdd % 2 == 0)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&totalJournalList,
					       totalJournalList->caboose, tmp);
					tmp = NULL;
				}

				mknode(&tmp, fileNumber);
				append(&totalJournalList,
				       totalJournalList->caboose, tmp);
				tmp = NULL;
			}
			evenOrOdd++;
		}
	}

	evenOrOdd = 1;
	//
	// The program resets evenorOdd due to switching to the next form of
	// evaluations, Participation.  The code is identical to above. Bonus points
	// were hard coded because I've capped my bonus points in both participation
	// and journals. ( Yay, lucky me. So doing better in classes makes eoce more
	// enjoyable.
	//
	while (fileNumber != -3)
	{
		fscanf(in, "%d", &fileNumber);
		if (fileNumber != -2 && fileNumber != -3)
		{
			if (evenOrOdd % 2 == 1)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&myPartList, myPartList->caboose,
					       tmp);
					tmp = NULL;
				}

				mknode(&tmp, fileNumber);
				append(&myPartList, myPartList->caboose, tmp);
				tmp = NULL;
			}
			else if (evenOrOdd % 2 == 0)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&totalPartList,
					       totalPartList->caboose, tmp);
					tmp = NULL;
				}

				mknode(&tmp, fileNumber);
				append(&totalPartList, totalPartList->caboose,
				       tmp);
				tmp = NULL;
			}
			evenOrOdd++;
		}
	}

	evenOrOdd = 1;
	//
	// Now, we move on to projects, not capping the bonus points this time.  Same
	// implementation as before.  Note: the while loop checks negative numbers because
	// flattened data is formatted to separated sectional data by negative numbers. It
	// is essentially very similar to the control byte method in dcf2
	//
	while (fileNumber != -4)
	{
		fscanf(in, "%d", &fileNumber);
		if (fileNumber != -3 && fileNumber != -4)
		{
			if (evenOrOdd % 2 == 1)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&myProjList, myProjList->caboose,
					       tmp);
					tmp = NULL;
				}

				mknode(&tmp, fileNumber);
				append(&myProjList, myProjList->caboose, tmp);
				tmp = NULL;
			}
			else if (evenOrOdd % 2 == 0)
			{
				while (fileNumber > 127)
				{
					mknode(&tmp, 127);
					fileNumber -= 127;
					append(&totalProjList,
					       totalProjList->caboose, tmp);
					tmp = NULL;
				}

				mknode(&tmp, fileNumber);
				append(&totalProjList, totalProjList->caboose,
				       tmp);
				tmp = NULL;
			}
			evenOrOdd++;
		}
	}

///////////////////////////////////////
// Total up and percent-ify all points
///////////////////////////////////////

//
// Again, a very repetetive, yet functional "calculator" for grade
// totals to be added up and beautified
//
	int myTotal = 0;
	int total = 0;
	int bonus = 16;
	int overallTotal = 0;
	float percent;

	//
	// Similarly to the rest of our data structures course, I used a tmp variable
	// here to iterate over each linked list, totaling up the values
	//
	tmp = myPartList->engine;
	while (tmp != NULL)
	{
		if (tmp->VALUE <= 40)
			myTotal += tmp->VALUE;
		tmp = tmp->to;
	}
	myTotal += bonus;

	tmp = totalPartList->engine;
	while (tmp != NULL)
	{
		total += tmp->VALUE;
		tmp = tmp->to;
	}
	//
	// Here, we calculate the percentages out of total "weight" for each
	// section. Of course, projects are worth the most weight in percentage
	// points.
	//
	percent = (float)myTotal / (float)total;
	fprintf(stdout, "Participation:  %d+%d  / %d =>  %d / %d\n", myTotal,
		bonus, total, (int)(percent * 13), 13);
	overallTotal += (int)(percent * 13);

	myTotal = 0;
	total = 0;
	tmp = myJournalList->engine;
	while (tmp != NULL)
	{
		if (tmp->VALUE <= 8)
			myTotal += tmp->VALUE;
		tmp = tmp->to;
	}
	myTotal += bonus;

	tmp = totalJournalList->engine;
	while (tmp != NULL)
	{
		total += tmp->VALUE;
		tmp = tmp->to;
	}
	percent = (float)myTotal / (float)total;
	fprintf(stdout, "      Journal:  %d+%d  /  %d =>  %d / %d\n", myTotal,
		bonus, total, (int)(percent * 13), 13);

	overallTotal += (int)(percent * 13);
	myTotal = 0;
	total = 0;
	tmp = myProjList->engine;
	while (tmp != NULL)
	{
		myTotal += tmp->VALUE;
		tmp = tmp->to;
	}

	tmp = totalProjList->engine;
	while (tmp != NULL)
	{
		total += tmp->VALUE;
		tmp = tmp->to;
	}
	bonus = myTotal - total;
	percent = (float)myTotal / (float)total;
	fprintf(stdout, "     Projects:  %d+%d /%d =>  %d / %d\n", myTotal,
		bonus, total, (int)(percent * 52), 52);

	overallTotal += (int)(percent * 52);
	float percentGrade = ((overallTotal) / 78.0) * 100;
	char *letterGrade = "A+";

	//
	// Now that we have the total grade out of 100 percent, we can check it against
	// Prof. Haas's grading scale for printing the correct grade later. I set the
	// default grade to A+ just to show that this implementation works in printing
	// out any grade but that.
	//
	if (percentGrade >= 100.0)
		letterGrade = "A";
	else if (percentGrade >= 94.0)
		letterGrade = "A-";
	else if (percentGrade >= 88.0)
		letterGrade = "B+";
	else if (percentGrade >= 82.0)
		letterGrade = "B";
	else if (percentGrade >= 76.0)
		letterGrade = "B-";
	else if (percentGrade >= 70.0)
		letterGrade = "C+";
	else if (percentGrade >= 64.0)
		letterGrade = "C";
	else if (percentGrade >= 58.0)
		letterGrade = "D";
	else
		letterGrade = "F";

	//
	// Formatting beautifier for the grade output.  Format specifiers are used
	// very sparingly.
	//
	fprintf(stdout, "-----------------------------------------\n");
	fprintf(stdout, "Total:                            %d / 78\n",
		overallTotal);
	fprintf(stdout, "=========================================\n");
	fprintf(stdout, "Score:                            %.3f\n",
		percentGrade);
	fprintf(stdout, "Grade:                                  %s\n",
		letterGrade);
	//
	// Close out file being read
	//
	fclose(in);

	return (0);
}
