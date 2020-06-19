 /* Created by Kyriacos Xanthos
 * Course : CS11
 */

/* This program uses Donald Knuf's algorithm and computes
 * the easter date in a given year.
 */

#include <stdio.h> 

/* This function uses Donald Knuth's algorithm to find 
 * the Easter date in a given year.
 * It takes as input the year.
 * It checks if the input year is in the range that the algorith works.
 * If it is, it goes through the algorith and returns either a positive.
 * value which is the date in April or a negative which is the date in March.
 */ 

int calculate_Easter_date(int year)
{   

if (year < 1582 || year > 39999) /* checks the range */
{
    return 0;
}
else
{

int golden_year, century, skip_leap, z_corr, d_M, epact, N, date;

    /* this is the golden year in the 19-year cycle */
    golden_year = (year % 19) + 1 ;

    century = (year / 100) +1 ;     /* calculates the century. */
    skip_leap = ( 3 * century / 4 ) - 12 ;  /* skip leap years */

     /* correction factor of the moon's orbit. */
    z_corr = (( 8 * century + 5 ) / 25) - 5 ;

    /* March ((-D) mod 7 + 7) is a Sunday. */
    d_M = ( 5 * year / 4 )-skip_leap - 10 ; 

    /* specifies when full moon occurs */
    epact = ( 11 * golden_year + 20 +z_corr - skip_leap ) % 30 ; 

    if( (( epact == 25 ) && ( golden_year > 11 )) || epact == 24 ) 
    {
        epact ++ ;
        
    }
    N = 44 - epact;  /* full Moon orbits */
    if ( N < 21)
    {
        N = N + 30;    
        
    }
    N = N + 7 - ((d_M + N) % 7 );  /* Date in Aptil */

    if ( N > 31)
    {
        date= N - 31;
        return date;
    }
    else
    {    
        return - N;
    }
}

}
    /* The main function takes as input the values it
     * finds from scanf and assignes it to the int year.
     * it loops until there are no more entries in the txt file.
     * for every year it goes through the "calculate_Easter_date" 
     * function and depending on the value which was returned,
     * prints either "April" and the date, "March" and the date,
     * or prints an error message TO THE TERMINAL.
     * As a function it returns nothing.
     */

int main(void)   
{   
    while(1)
    {
        
        int year;
        int r;
        int return_value = scanf("%d", &year);
       
        if( return_value == EOF)  /* checks scanf */
        {
            break;
        } 
        r = calculate_Easter_date(year);

            if (r > 0 )     /* by def in r > 0 then the year is April */
            {
                printf("%d - April %d\n", year, r);
            }
            else if (r == 0)
            {
                /* when year not in range */
                fprintf(stderr, "Enter a Year between 1582 and 39999 \n"); 
            }
            else
            {
                /* by def in r > 0 then the year is March */
                printf("%d - March %d\n", year, - r); 
            }
        }
        
    return 0 ;

}







    


