#include <stdio.h>
int main() {

    int number ;

    printf( "Input :\n" ) ;
    scanf( "%d", &number ) ;

    if( number > 0 ) {
        printf( "Positive" ) ;
    } else {
        printf( "Negative" ) ;
    }
    return 0 ;
}