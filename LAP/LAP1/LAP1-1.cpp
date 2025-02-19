#include <stdio.h>

int main() {
    int n,i ; 
    printf( "input number: " ) ; 
    scanf( "%d",&n) ; 
    for(int i = 1 ; i <= n ; i ++){ 
        printf( "[%d] Hello World \n", i) ; 
    }
    return 0 ;
}//end fucntion