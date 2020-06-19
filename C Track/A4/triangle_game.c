#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "triangle_routines.h"

/* This program takes an initial input from 
 * the user with a triangle orientation
 * with pegs and without. It performs a loop
 * where it tries to remove the pegs from 
 * every number until just one peg is left.
 * If the input is solvable it prints the steps
 * If not then it prints not solvable
 */ 


#define NMOVES 36   /* number of moves */

#define TOTAL_EL 15 /* total elements */

/***
 * takes: number of moves, number of moving elements
 * does: list all possible allowable moves
 * returns: the list of all arrangements
 ***/ 

/* Found and changed the wrong element */

int moves[NMOVES][3] =
{
  {0, 1, 3},
  {3, 1, 0},
  {1, 3, 6},
  {6, 3, 1},
  {3, 6, 10},
  {10, 6, 3},
  {4, 7, 11},
  {11, 7, 4},
  {5, 9, 14},
  {14, 9, 5},
  {1, 4, 8},
  {8, 4, 1},
  {6, 7, 8},
  {8, 7, 6},
  {0, 2, 5},
  {5, 2, 0},
  {2, 5, 9},
  {9, 5, 2},
  {7, 8, 9},
  {9, 8, 7},
  {3, 7, 12},
  {12, 7, 3},
  {3, 4, 5},
  {5, 4, 3},
  {5, 8, 12},
  {12, 8, 5},
  {4, 8, 13},
  {13, 8, 4},
  {2, 4, 7},
  {7, 4, 2},
  {10, 11, 12},
  {12, 11, 10},
  {11, 12, 13},
  {13, 12, 11},
  {12, 13, 14},
  {14, 13, 12}
};

/*** 
 * Takes: input board
 * does: count the number of pegs
 * returns: the number of pegs on the board. 
 ***/

int npegs(int board[])
{
    int i;
    int j = 0;

    for (i = 0; i < TOTAL_EL; i++) /* less than total elements */
    {
        if (board[i] == 1)
        {
            j++;
        }
    }
    return j;

}

/***
 * takes: board array and initializes move array
 * does:  Checks 1st 2nd and 3rd spots if they have pegs
          if 1st and 2nd have but 3rd does not, then returns 0
          if this is not the case then it is not a valid move.
 *  Return 1 if the move is valid on this board, otherwise return 0. 
 ***/

int valid_move(int board[], int move[])
{
    /* only pssibility of valid move through the 
     *triangle is the following */

    if ((board[move[0]] == 1) && (board[move[1]] == 1)
            && (board[move[2]] == 0))
    {
        return 1;
    }

    return 0;
}

/* Make this move on this board. */
void make_move(int board[], int move[])
{
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
}

/* Unmake this move on this board. */
void unmake_move(int board[], int move[])
{
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;

}    

/***
 * takes: input board array
 * does: solve the game. doesn't permanently alter the board.
 * return: 1 if the game can be solved and if not 0
 ***/
int solve(int board[])
{
    int i;
    int solveable = 0;
    int available_pegs = npegs(board);

    if (available_pegs == 1) /* base case */
    {
        triangle_print(board);
        return 1;

    }
    else
    {   
        for (i = 0; i < NMOVES; i++)    /* iterate through all moves */
        {
            if (valid_move(board, moves[i]))
            {
                make_move(board, moves[i]); /* makes the move */
                solveable = solve(board);   /* recursion */
                unmake_move(board, moves[i]); /* unmakes move */
                if (solveable)
                { 
                    /* prints only if board is 
                     * solvavle for the given iteration
                     */

                    triangle_print(board);
                    return 1;
                }

            }

        }

        return 0;
    }

}

/***
 * takes : input board
 * does: solves the board. if not print error statement.
 * returns: 0
 ***/ 


int main(void)
{
    int board[15];
    int solveable;
    triangle_input(board);
    solveable = solve(board);

    /* if not solvable then print accordingly */
    if (!solveable)
    {
        printf("The input board cannot be solved.\n");
        exit(0);
    }

    return 0;

}

