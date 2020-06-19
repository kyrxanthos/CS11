#include <stdio.h> 

#define MAX_LEN 99      /* define the length of the input string */

int 
main (void)
{
  char name[MAX_LEN];

  printf ("Enter your name: ");
  scanf ("%s", name);       /* check input */
  printf ("Hello ");
  printf ("%s" , name);
  printf("!\n");

  return 0;

}
