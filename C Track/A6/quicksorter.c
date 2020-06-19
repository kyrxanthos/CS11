 /* Created by Kyriacos Xanthos
 * Course : CS11
 * Assignment 6
 */


/*
 * This program performs sorting of numbers 
 * using quicksort. It uses linked lists, and
 * takes the input from command-line arguments.
 * When the sort is finished the program prints
 * every element sorted, on a new line.
 */

#include <stdio.h>
#include <stdlib.h>
#include "memcheck.h"
#include "linked_list.h"
#include <string.h>
#include <assert.h>

/***
 * takes: the character p_name which is the program name
 * does: prints usage message and exits.
 * returns: nothing 
 ***/

void usage(char *p_name)
{
    
    fprintf(stderr, "usage: %s  [-q] number1 "
                    " [number2 ... ] \n", p_name);
    exit(1);
}

/***
 * takes: the list to be sorted
 * does: uses linked list to sort the original list
 * returns: the sorted list
 ***/

node *
quicksort(node *list)
{
    node *node_1 = NULL;    /* 1st node */
    node *right = NULL;     
    node *left = NULL;      
    /* node of elements of the right of the pivot */
    node *right_sorted = NULL; 
    /* node of elements of the left of the pivot */ 
    node *left_sorted = NULL;   
    node *head = NULL;      
    node *list1 = NULL;     
    node *list2 = NULL;     /* this will be the sorted list */

    int i = 0;  /* to the left */
    int j = 0;  /* to the right */
    int pivot;
    int head_data;

    if (list == NULL || list -> next == NULL )
    {
        /* Base case */
        return copy_list(list);
    }
    
    
        node_1 = create_node(list->data, NULL);  /* create 1st node */
        pivot = node_1->data;
        head = list -> next;
    /* Loop until all the elements left and right of 
        the pivot are at their correct place  */
        while (head != NULL)        
        {
            head_data = head -> data;
            if (head_data < pivot)
            {
                if ( i == 0)    /* initialize the node */
                {
                    left = create_node(head_data, NULL);
                }
                else    /* create the left node for each increment */
                {
                    left = create_node(head_data, left);
                }
                i++;
            }
            else
            {
                if (j == 0) /* initialize the node */
                {
                    right = create_node(head_data, NULL);
                }
                else /* create the left node for each increment */
                {
                    right = create_node(head_data, right);
                }
                j++;
            }
            head = head->next; /* go to the next node */
        }
        /* recursion is used to go through the sorted  elements */
        left_sorted = quicksort(left);
        right_sorted = quicksort(right);

        list1 = append_lists(left_sorted, node_1); /* append from the left */
        list2 = append_lists(list1, right_sorted); /* final list */

        assert(is_sorted(list2)); /* check assertion of final list */

        /* free all the memory */
        free_list(left_sorted);
        free_list(right_sorted);
        free_list(node_1);
        free_list(left);
        free_list(right);
        free_list(list1);

        return list2;
    
}

/***
 * takes: command line arguments
 * does: creates list of command line arguments and
 * sorts them using the quicksort mechanism
 * returns: nothing
 ***/

int main(int argc, char *argv[])
{ 
    char *p_name = argv[0]; /* name of program */
    int i;
    int j = 0;
    int data;
    int quiet = 0;  /* Value for the "-q" optional argument. */
    node *list = NULL; /* empty list */
    node *list1;

    for (i = 1; i < argc; i++)  /* Skip program name. */
    {

        if (strcmp(argv[i], "-q") == 0)  /* Process optional arguments. */
        {
            quiet = 1;  /* This is used as a boolean value. */
        }
        else
        {
            data = atoi(argv[i]);
            if (j == 0)
            {
                list = create_node(data, NULL); /* base case */
            }
            else
            {
                /* create nodes for every command-line argument */
                list = create_node(data, list ); 
            }
            j++;
        }

    }

    if ( j == 0 )
    {
        usage(p_name); /* if no arguments were given */
    }
    else
    {
        /* perform the sort to the list */
        list1 = quicksort(list); 
        free_list(list);
        list = list1; /* assigns list to the sorted list */
    }

    if (!quiet) /* if -q in command line arguments then prints nothing */
    {
        print_list(list);
    }

    free_list(list);
    print_memory_leaks();
    return 0;

}

