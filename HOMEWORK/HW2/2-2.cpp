#include <stdio.h>

int main() {
    char job ;

    while ( 1 ) {
    printf( "โพสต์หางาน\n" ) ;
    printf( "มีลูกค้าสนใจ (y/n) : " ) ;
    scanf( " %c", &job ) ;


        if( job == 'y' ) {
            printf( "เรื่มคุยงาน\n" ) ;
            printf( "ลูกค้าสนใจอยู่หรือไม่ (y/n) : " ) ;
            scanf( " %c", &job ) ;
                if( job == 'y' ) {
                    printf( "เริ่มเขียนสัญญาจ้าง\n" ) ;
                    printf( "ลูกค้าจ่ายเงินมัดจำ\n" ) ;
                    printf( "เริ่มทำงาน\n" ) ;
                    printf( "รายงานความคืบหน้า\n" ) ;
                    printf( "งานเสร็จหรือไม่ (y/n) : " ) ;
                    scanf( " %c", &job ) ;
                    if( job == 'y' ) {
                            printf( "ลูกค้าจ่ายเงินที่เหลือ\n" ) ;
                        }else{
                            printf( "คืนเงินมัดจำลูกค้า\n" ) ;
                        }
                        break ;
                }
        }
    }
return 0 ;
}