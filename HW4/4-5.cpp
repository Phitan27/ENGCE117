#include <stdio.h>

int main() {
    
    int days ;
    int sec ;

    printf( "Input Days : \n" ) ;
    scanf( "%d", &days ) ;

    sec = days * 24 * 60 * 60  ;
    printf( "%d Days = %d seconds",days , sec  ) ;

    return 0 ;
}