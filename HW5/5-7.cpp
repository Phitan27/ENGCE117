#include <stdio.h>
int main() {

    int y ;

    printf( "Year(s) : \n" ) ;
    scanf( "%d", &y ) ;

    if( y % 4 != 0 || ( y % 4 == 0 && y % 100 == 0 && y % 400 != 0 ) ) {
        printf( "February has 28 days\n" ) ;
    } else {
        ( y % 4 == 0 ||( y % 100 != 0 && y % 400 == 0 ) ) ;
        printf( "February has 29 days\n" ) ;
    }

    return 0 ;
}