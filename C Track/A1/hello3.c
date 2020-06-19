#include <stdio.h> 

#include <stdlib.h>

#include <time.h>

#define MAX_LEN 99     /* define the length of the input string */ 

int 
main (void) 
{ 
  int ran;
  char name[MAX_LEN];
  printf ("Enter your name: ");     
  scanf ("%s", name);

  srand(time(0));       /* set an initial value zero for the rand function */  
  ran = rand() %10;

  if(ran % 2 == 0)   /* divisible by 2 == even */
  {    
    int i;
    for (i = 0; i < ran; i++)   /* for loop to keep printing for "ran" times */
      { 
            printf ("%d" , ran);
            printf (" Hello, ");
            printf ("%s" , name);
            printf("!\n");
      }

  }
  else      /* odd */
  {       
    
     int i;
     for (i = 0; i < ran; i++)  /* same loop as above */
      { 
            printf ("%d" , ran);
            printf (" Hi there, ");
            printf ("%s" , name);
            printf("!\n");
      }
}

return 0;

}

