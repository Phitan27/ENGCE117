#include <stdio.h>

int main() {

    float H ;
    float W ;
    float area ;

    printf( "Enter H & W : \n" ) ;
    scanf( "%f %f", &H, &W ) ;

    area = ( H * W ) / 2 ;
    printf( "Triangle Area : %.1f \n", area ) ;
    

    return 0 ;
}