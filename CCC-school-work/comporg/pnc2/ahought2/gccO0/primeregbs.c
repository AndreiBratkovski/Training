#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

/*
 |     primeregbs.c is a program to calculate a USER INPUT quantity of prime numbers
 |     using the square root AND break on composite optimizations
 |     ./primeregbs [quantity]
 |     ex: ./primereg 8
 */

int main(int argc, char **argv)
{
    struct timeval time_start; // starting time
    struct timeval time_end;   // ending time
    int number, factor, quantity, count, check, sqr;
    

    /*****Argument Processing*****/
    if(argc != 2)
    {
        fprintf(stderr, "Incorrect Number of Arguments!\n./primereg QUANTITY\n");
        exit(1);
    }
    else
    {
        quantity = atoi(argv[1]);   // set quantity from STDIN
        count = 0;
    }

    /*****Processing Primes*****/
    gettimeofday(&time_start, 0); // start timing

    for(number = 2; count < quantity; number++)
    {
        check = 0;  // reset check to 0 so number must be disproved of primality
        sqr = sqrt(number);
        for(factor = 2; factor <= sqr; factor++)
        {
            if((number % factor) == 0)
            {
                check = 1;
                break;
            }
        }
        
        if(check == 0)  // number is prime
        {
            fprintf(stderr, "%d ", number);
            count++;
        }
    }

    fprintf(stderr, "\n");

    gettimeofday(&time_end, 0); // end timing

    fprintf (stdout, "%8.4lf\n",
    time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));
    
    return(0);
}
