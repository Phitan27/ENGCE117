#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
} ;

struct student ( *GetStudent( int *room ) )[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;
    children = GetStudent( &group ) ;
    for ( int i = 0 ; i < group ; i++ ) {
        printf( "Room %d: 10 students entered.\n", i + 1 ) ;
    }//end for
    return 0 ;
}//end function

struct student ( *GetStudent( int *room ) )[ 10 ] {
    // input room
    scanf( "%d", room ) ;

    // dynamic struct array
    struct student ( *child )[ 10 ] = new struct student[ *room ][ 10 ];

    for ( int i = 0 ; i < ( *room ) ; i++ ) {
        printf( "Room %d: \n", i + 1 ) ;

        // input 10 students
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Student %d: ", j + 1 ) ;
            scanf( "%s %d", &child[ i ][ j ].name, &child[ i ][ j ].age ) ;
        }

        printf( "----------------------------------------\n" ) ;
    }//end for
    return child ;
}