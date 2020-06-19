 /* Created by Kyriacos Xanthos
 * Course : CS11
 * Assignment 5
 */

/* 
 * A cellular automaton (CA) consists of a collection of cells 
 * which can hold data values.
 * This program uses only full and empty values
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "memcheck.h"
#include <time.h>

/*
 * input: program name
 * does : prints usage message
 * output: nothing
 */
void usage(char *p_name)
{
    fprintf(stderr, "usage: %s number_cells, number_gens\n", p_name);
    exit(1);
}
/*
 * input: pointers containing numbers to be input to program
 *        number of elements integer
 * does : changes or leaves the same number to the element
 *        depending on the elements next to it. Updates new arrays
 * output: nothing
 */
void update_array(int *numbers, int *next_numbers, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if ( i != 0 && i != len -1) /* ignore first and last elements */
        {
            if ( numbers[i] == 0 && ((numbers[i - 1] + numbers [ i + 1]) == 1))
            {
                next_numbers[i]= 1;
            }
            else
            {
                next_numbers[i]= 0;
            }
            
        }
        else if ( i == 0) /* deal with first element */
        {
            if ( numbers[i] == 0 && numbers[i + 1] == 1)
            {
                next_numbers[i] = 0;
            }
            else
            {
                next_numbers[i] = 0;
            }
            
        }
        else  /* deal with last element */
        {
            if (numbers[i] == 0 && numbers[i - 1] == 1)
            {
               next_numbers[i] = 0;
            }
            else
            {
                next_numbers[i] = 0;
            }
            
        }

    }

    /* asssigns all next_numbers to numbers */
    for (i = 0; i < len; i++)
    {
        numbers[i] = next_numbers[i];
    }
}

/*
 * input: array to be printed, length of array
 * does : prints "." for 0 and "*" for 1
 * output: nothing
 */
void print(int *out_array, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (out_array[i] == 0)
        {
            printf(".");
        }
        else
        {
            printf("*");
        }
    }
    printf("\n");
}

/*
 * input: command - line arguments ( and their number )
 * does : runs above functions and prints the output of the game
 */
int main(int argc, char *argv[])
{

    int *numbers; /* array for use */
    int *next_numbers;  /* next generation array for use */
    int cells_in; /* number of cells */
    int gen; /* number of generations */
    char *p_name = argv[0];
    int ran; /* random number */
    int i;

    /* only two arguments accepted */

    if ( argc == 1 || argc == 2 || argc > 3)
    {
        usage(p_name);
    }

    cells_in = atoi(argv[1]);
    gen = atoi(argv[2]);

    /* dynamic memory allocation */
    numbers = (int *) calloc(cells_in, sizeof(int));
    next_numbers = (int *) calloc(cells_in, sizeof(int));

    /* Check that the calloc call succeeded. */
    if ( numbers == NULL || next_numbers == NULL )
    {
        fprintf(stderr, "Error! Memory allocation failed!\n");
        exit(1);  /* abort the program */
    }

    srand(time(NULL)); /* set an initial value zero for the rand function */  
  
    /* generate the arrays with random numbers */



    for ( i = 0; i <cells_in ; i++)
    {
        ran = rand() %2;
        numbers[i] = ran;
        next_numbers[i] = ran;
    }

    print(numbers, cells_in);

    /* run through the update */

    for (i = 0; i < gen; i++)
    {
        update_array(numbers, next_numbers, cells_in);
        print(numbers, cells_in);
    }

    /* free the memory */
    free(numbers);
    free(next_numbers);
    print_memory_leaks();

    return 0;
}
