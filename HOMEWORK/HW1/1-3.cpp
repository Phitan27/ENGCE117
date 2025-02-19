#include <stdio.h>

int main(){
    char FirstName[ 20 ] ;
    char LastName[ 20 ] ;

    printf( "First Name: " ) ;
    scanf( "%s" ,&FirstName ) ;
    printf( "Last Name: " ) ;
    scanf( "%s" ,&LastName ) ;
    printf( "%s %s TC, RMUTL, Chiang Mai, Thailand" ,FirstName ,LastName ) ;
    return 0 ;
}//end function