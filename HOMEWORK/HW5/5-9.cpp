#include <stdio.h>
int main() {
    float x1, x2, y1, y2 ;
    float midx, midy ;

    printf( "Input A point : \n" ) ;
    scanf( "%f %f", &x1, &x2 ) ; 
    printf( "Input B point : \n" ) ;
    scanf( "%f %f", &y1, &y2 ) ; 

    midx = ( x1 + y1 ) / 2.0 ;
    midy = ( x2 + y2 ) / 2.0 ;

    printf( "Mid Point of A and B is ( %.1f , %.1f ) ", midx, midy ) ;

    return 0 ;
}