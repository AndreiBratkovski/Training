//////////////////////////////////////////////
//
// Andrei Bratkovski - EoCE - Hash Tables
//
//////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MEMBOUND 50
//
// Declare a struct with a key and value which
// reflects the hash mapping of keys and values per
// array element
//
// For the purposes of simple implementation, our keys will be
// integer values
//
struct hashData {

	int key;
	int value;
};

//
// Collisions cannot occur due to only one value being assigned to
// one unique key in this particular instance. If a value is inserted into an
// a key with a value already, it overwrites that value
//
typedef struct hashData Hash;	// because we deserve nice things

//
// Declare an array of hashData
// which contains hashData keys and values per
// array element. Using a global array for the purposes
// of this project, limiting all hash tables to a maximum of
// 50 hashes
//
Hash *hashArray[MEMBOUND];

//
// hashing function which limits all key values within the
// range of MEMBOUND.  That way the input cannot exceed
// our hashtable memory bounds
//
int hashIndex(int key)
{
	return key % MEMBOUND;
}

Hash *search(int searchKey)
{
	//
	// obtain hash index
	//
	int hashPlace = 0;

	//
	// search over hashArray until hashData is
	// located
	//
	while ( hashPlace < 50)
	{
		if (hashArray[hashPlace]->key == searchKey)
			break;
		hashPlace++;
	}

	if (hashArray[hashPlace] == NULL)
		fprintf(stdout, "\nHash is empty or does not exist!\n");
	else
		fprintf(stdout, "Hash Found! { key: %d, value: %d }\n",
			hashArray[hashPlace]->key, hashArray[hashPlace]->value);

	return hashArray[hashPlace];
}

//
// Hash insertion handles both allocation of memory and creation of
// hash key/value pair to place into the hashArray
//
void insertHash(int key, int value)
{
	Hash *newHash = NULL;
	newHash = (Hash *) malloc(sizeof(Hash));
	newHash->key = key;
	newHash->value = value;

	int trigger = 0;
	int hashPlace = 0;

	//
	// Iterate over hash Array until there is an empty spot
	// to append a hash
	//
	while ( hashArray[hashPlace] != NULL && hashPlace < MEMBOUND  )
	{
		if (hashArray[hashPlace]->key == key)
			trigger = 1;
		hashPlace++;
	}
	if ( trigger == 0 )
		hashArray[hashPlace] = newHash;
	//
	// Handling collision of possible attempt at doubling a key
	//
	else
		fprintf(stdout, "Key already exists! Need a unique key!\n\n");
}

//
// Delete a hash value by its key
//
void deleteHash(int key)
{
	if (hashArray[key] != NULL)
		hashArray[key] = NULL;
}

//
// Displays current state of hash table
//
void testDisplay()
{
	int increment = 0;

	//
	// Iterates over each key in the hashtable and
	// displays the key/value pair
	//
	for (; increment < MEMBOUND; increment++)
	{
		if (hashArray[increment] != NULL)
			fprintf(stdout, " { key: %d, value: %d }\n",
				hashArray[increment]->key,
				hashArray[increment]->value);
		else
			fprintf(stdout, "{ key: NULL, value: NULL }\n");
	}
	fprintf(stdout, "\n");
}

int main()
{
	//
	// Declare variables for user input on function choice, keys and values in
	// the hash table
	//
	int functionChoice;
	int key;
	int value;

	//
	// Super cool and user friendly interface so that user can manipulate
	// hash table
	//
	fprintf(stdout,
		"=====Welcome to integer based Hash Tables! 0x1=====\n");
	do
	{
		fprintf(stdout, "\n0. Insert key/value pair to hash table\n");
		fprintf(stdout, "1. Delete Hash by Key.\n");
		fprintf(stdout, "2. Search for Key in Hash table\n");
		fprintf(stdout, "3. Display Current Hash table\n");
		fprintf(stdout, "4. Quit program\n");
		fprintf(stdout, ">>> ");
		fscanf(stdin, "%d", &functionChoice);
		getchar();

		//
		// Respond to user input with function call. User enters value, key or just key
		// to insert, remove, display the hash table, and quit the program
		//
		switch (functionChoice)
		{
		case 0:
			fprintf(stdout, "Enter key ( 0-49 ): ");
			fscanf(stdin, "%d", &key);
			fprintf(stdout, "Enter value: ");
			fscanf(stdin, "%d", &value);
			insertHash(key, value);
			break;

		case 1:
			fprintf(stdout, "Enter key to delete ( 0-49 ): ");
			fscanf(stdin, "%d", &key);
			deleteHash(key);
			break;

		case 2:
			fprintf(stdout, "Enter a key to search ( 0-49 ): ");
			fscanf(stdin, "%d", &key);
			search(key);
			break;

		case 3:
			testDisplay();
			break;

		case 4:
			break;

		default:
			fprintf(stdout,
				"Choice out of range, choice needs to be (0-4)\n");
			break;
		}

	}
	while (functionChoice != 4);

	return 0;
}
