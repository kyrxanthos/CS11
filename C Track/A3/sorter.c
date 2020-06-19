 /* Created by Kyriacos Xanthos
 * Course : CS11
 * Assignment 3
 */

/* This program sorts command lime arguments in ascending order.
 * It uses either minimum element sort algorithm or bubble sort
 * depending on the command line arguments.
 */

#include <stdio.h> 
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 32  /* definition of max possible length of input */

/***
 * takes: the character p_name which is the program name
 * does: prints usage message and exits.
 * returns: nothing 
 ***/

void usage(char *p_name)
{
    
    fprintf(stderr, "usage: %s [-b] [-q] number 1"
                    " [number2 ... ] (maximum 32 numbers)\n", p_name);
    exit(1);
}

/* 
 * Input : pointer xp and xy which are just going to be used to 
 * create the swap mechanism
 * This function simply swaps the values
 * It is going to be used in the sorting functions
 */

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp;  /* swaps the value stored in xp with yp */
    *yp = temp; 
} 

/***
 *takes the array of numbers and the value of N which is the
 * length of the array.
 * performs bubble sort
 * returns nothing 
 ***/

void sort_bubble(int array_num[], int N)
{
    int i, j;
    for ( i = 0 ; i < N - 1 ; i++ ) 
        for ( j = 0 ; j < N - i - 1 ; j++)
            if ( array_num[j] > array_num[j + 1] )
            {   
                /* using functio from above to swap */
                swap( &array_num[j], &array_num[j + 1] );
            }
/* assertion function to check sorting */
for (i = 1; i < N; i++)
{
    assert( array_num[i] >= array_num[i - 1] );
}

}

/* Takes the array of integers and the length of the array
 * which is the length of the aray
 * performs minimum element sort 
 * returns nothing */

void sort_min(int array_num[], int n) 
{ 
    int i, j, min_idx; 
  
    /* One by one move boundary of unsorted subarray  */
    for ( i = 0; i < n - 1; i++ ) 
    { 
        /* Find the minimum element in unsorted array  */
        min_idx = i; 
        for ( j = i + 1; j < n; j++ ) 
          if (array_num[j] < array_num[min_idx]) 
            min_idx = j; 
  
        /* Swap the found minimum element with the first element */
        swap(&array_num[min_idx], &array_num[i]); 
    } 

/* assertion function to check sorting */
    for (i = 1; i < n; i++)
    {
        assert( array_num[i] >= array_num[i - 1] );
    }

} 

/* main function analyzes command line arguments (their
 * length and the actual input).
 * it identifies optional arguments -q and -b
 * checks if the input is less than the MAX required
 * changes strings to integers
 * calls either bubble sort function or min sort function
 */



int main(int argc, char *argv[])
{   int i;
    int j;
    int count = 0;
    int quiet = 0;  /* Value for the "-q" optional argument. */
    int bubble = 0; /* Value for the "-b" optional argument. */
    int array_num[MAX_LENGTH];
    char *p_name = argv[0]; /* name of program */

    for (i = 1; i < argc; i++)  /* Skip argv[0] (program name). */
    {

        if (strcmp(argv[i], "-q") == 0)  /* Process optional arguments. */
        {
            quiet = 1;  /* This is used as a boolean value. */
        }

        else if (strcmp(argv[i], "-b") == 0)  /* Process optional arguments. */
        {
            bubble = 1;  /* This is used as a boolean value. */
        }

        else if (count < MAX_LENGTH)
        {
            array_num[count++] = atoi(argv[i]); /* changes str to int */
        }

        else
        {
            usage(p_name);
        }
    }
    if (count > 0) /* ensures there is no 0 input */
    {
        if (bubble) /* if -b in command line arguments then bubble sort */
        {
            sort_bubble(array_num, count);
        }
        else
        {
            sort_min(array_num, count);
        }
            
    }
    else
    {
        usage(p_name);
    }

    if (!quiet) /* if -q in command line arguments then prints nothing */
    {
        for (j = 0; j < count; j++)
        {
            printf("%d \n", array_num[j]); /* prints the sorted arrah */
        }
    }
    return 0;

}
