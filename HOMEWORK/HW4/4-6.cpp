#include <stdio.h>
#include <string.h>

int main() {
    char    id[ 11 ] ;
    char    decimal[ 20 ] ;
    int     h ;
    int     salary ;

    printf( "Input the Employee ID(Max. 10 chars) : \n" ) ;
    scanf( "%s", id ) ;
    printf( "Input the working hrs : \n" ) ;
    scanf( "%d", &h ) ;
    printf( "Salary amount/hr: \n" ) ;
    scanf( "%d", &salary ) ;

    float total = h * salary ;
    sprintf( decimal, "%.2f", total ) ; 
    printf( "Expected Output :\n" ) ;
    printf( "Employees ID = %s\n", id ) ;
    printf( "Salary = U$ " ) ;

    int len = strlen( decimal ) ;

    for (int i = 0 ; i < len - 3 ; i++ ) { 
        if (i != 0 && ( len - i ) % 3 == 0 ) { 
            printf( "," ) ;
        }//end if
        printf( "%c" , decimal[ i ] ) ; 
    }//end for
    
    printf( "%s\n",  strchr( decimal, '.' ) ) ;
    return 0 ;
}//end function