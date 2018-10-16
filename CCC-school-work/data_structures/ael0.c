//
//  main.c
//  ael0
//
//  Created by Andrei Bratkovski on 8/27/17.
//  Copyright © 2017 Andrei Bratkovski. All rights reserved.
//

#include <stdio.h>

//
//  Declaring prototype functions
//
void buildList(int *, int *);
void displayf(int *, int *);
void displayb(int *, int *);
void insertIntoList(int *, int *);
void append(int *, int *);
void obtain(int *, int *, int *);
void clearList(int *, int *);

int main() {
    // 
    // Initializing the list and list size that we will be manipulating
    //
    int userInput;
    int list[20];
    list[0] = -1;
    int displaySize = 1;
    int arrayIndex = 0;
    
    //
    // Menu
    //
    
    do
   {
        fprintf(stderr,"\n\n====ael0====\n");
        fprintf(stderr,"0. build list\n");
        fprintf(stderr,"1. display list forward\n");
        fprintf(stderr,"2. display list backward\n");
        fprintf(stderr,"3. insert into list\n");
        fprintf(stderr,"4. append into list\n");
        fprintf(stderr,"5. obtain from list\n");
        fprintf(stderr,"6. clear list\n");
        fprintf(stderr,"7. quit\n");
        fprintf(stderr, ">>> ");
        scanf("%d", &userInput);
        getchar();

	//
	// Responses to user input
	//
        switch (userInput)
        {
            case 0:
                buildList(list, &displaySize);
                break;
            case 1:
                displayf(list, &displaySize);
                break;
            case 2:
                displayb(list, &displaySize);
                break;
            case 3:
                insertIntoList(list, &displaySize);
                break;
            case 4:
                append(list, &displaySize);
                break;
            case 5:
                obtain(list, &displaySize, &arrayIndex);
                break;
            case 6:
                clearList(list, &displaySize);
                break;
            case 7:
                break;
            default:
                printf("your input is wrong\n");
                break;
            
        }
    }
    while(userInput != 7);
    
    return 0;
}
//
// Builds List
//
void buildList(int *list, int *displaySize){

    int localInput;
    int i = 0;
    
    do
    {
        fprintf(stderr, "enter value: (-1 to finish): ");
        scanf("%d", &localInput);
        list[i] = localInput;
        i++;
    }
    while(localInput != -1);
    *displaySize = i;
    
    
}

//
// Display forward
//
void displayf(int *list, int *displaySize){

    for (int i = 0; i < *displaySize; i++){
        printf( "[%d]", i);
        printf( " %d", list[i]);
        if (list[i] != -1){
            printf( " -> ");
        }
    }
    printf("\n");
}

//
// Display Backward
//
void displayb(int *list, int *displaySize){
    for (int i = *displaySize-1; i >= 0; i--){
        printf( "[%d]", i);
        printf( " %d", list[i]);
        if (i != 0){
            printf( " -> ");
        }
    }
    printf("\n");
}

//
// Insert into List
//
void insertIntoList(int *list, int *displaySize){
    int beforeIndex = 0;
    int value = 0;
    
    fprintf(stderr, "Enter index to insert before: ");
    scanf("%d", &beforeIndex );
    fprintf(stderr, "\nEnter value to insert into list: ");
    scanf("%d", &value);
    if(list[0] == -1){
        beforeIndex = 0;
    }
    if (beforeIndex == 0){
        beforeIndex = 1;
    }
    else if(beforeIndex == 1){
        beforeIndex = 2;
    }
    
    for (int i = *displaySize; i >= beforeIndex; i--){
        list[i] = list[i-1];
    }
    list[beforeIndex-1] = value;
    *displaySize += 1;
}

//
// Append to list
//
void append(int *list, int *displaySize){
    int afterIndex = 0;
    int value = 0;
    
    fprintf(stderr, "Enter index to append after: ");
    scanf("%d", &afterIndex );
    fprintf(stderr, "Enter value to append into list: ");
    scanf("%d", &value);
    if (list[0] == -1){
        afterIndex = -1;
    }
    for (int i = *displaySize; i > afterIndex+1; i--){
        list[i] = list[i-1];
    }
    list[afterIndex+1] = value;
    *displaySize += 1;
}

//
// Obtain from list value/index
//
void obtain(int *list, int *displaySize, int *arrayIndex){
    
    fprintf(stderr, "Enter index to obtain: ");
    scanf("%d", arrayIndex);
    printf("The value you obtained is: %d\n", list[*arrayIndex]);
    
    for (int i = *arrayIndex; i < *displaySize; i++){
        list[i] = list[i+1];
    }
    *displaySize -= 1;
}

//
// Clear out list
//
void clearList(int *list, int *displaySize){
    list[0] = -1;
    *displaySize = 1;
}
