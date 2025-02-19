#include <stdio.h>
int main() {

    int celsius ;
    float fahrenheit ;

    printf( "User Input :\n" ) ;
    scanf( "%d", &celsius ) ;

    fahrenheit = ( celsius * 9.0 / 5.0 ) + 32 ;
    printf( "%d degree Celsius = %.1f degree fahrenheit", celsius, fahrenheit ) ;

    return 0 ;
}