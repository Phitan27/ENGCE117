#include <stdio.h>

int main() {
  char Yes_or_No ;

    while (1) {
  printf( ">> ตรวจสอบ วัถุดิบ และ อุปกรณ์ <<\n" ) ;
  printf( "-----------------------\n" ) ;
  printf( ">> บะหมี่แถมเครื่องปรุง << (y/n) : " ) ;
  scanf( " %c", &Yes_or_No ) ;

  if( Yes_or_No == 'n') {
    printf( "-----------------------\n" ) ;
    printf( ">> ไปซื้อของที่ตลาด <<\n " ) ;
    printf( "-----------------------\n" ) ;
    printf( ">> ของหมดหรือไม่ << (y/n) : " ) ;
    scanf(" %c", &Yes_or_No ) ;
        
        if( Yes_or_No == 'n' ) {
        printf( "-----------------------\n" ) ;
        printf( ">> เงินไม่พอจ่ายใช่หรือไม่ << (y/n) : " ) ;
        scanf( " %c", &Yes_or_No ) ; 
        printf( "-----------------------\n" ) ;
            if( Yes_or_No == 'n' ) {
            printf( ">> ซื้อบะหมี่กึ่งสำเร็จรูป <<\n" ) ;
            printf( "-----------------------\n" ) ;
            }//end if
        }//end if
        printf( "กลับบ้าน\n" ) ;
        

    do {
        printf( ">> แก๊สหมดหรือไม่ << (y/n) : " ) ;
        scanf( " %c", &Yes_or_No ) ;
        printf( "-----------------------\n" ) ;
        if( Yes_or_No == 'y' ) {
            printf( ">> บอกผู้ปกครองซื้อแก๊ส <<\n" ) ;
            do {
                printf( "-----------------------\n" ) ;
                printf( ">> ผู้ปกครองซื้อแก๊ส << (y/n) : " ) ;
                scanf( " %c", &Yes_or_No ) ;
            }
            while ( Yes_or_No == 'n' ) ;
        }//end if
    }
        while ( Yes_or_No == 'y' ) ;
        printf( "-----------------------\n" ) ;
        printf( ">> เปิดแก๊ส <<\n" ) ;
        printf( "-----------------------\n" ) ;
        printf( ">> ต้มน้ำ <<\n") ;
        printf( "-----------------------\n" ) ;
        printf( ">> รอน้ำเดือด <<\n" ) ;

        do {
            printf( "-----------------------\n" ) ;
            printf( ">> น้ำเดือดหรือยัง << (y/n) : " ) ;
            scanf( " %c", &Yes_or_No ) ;
        }
            while ( Yes_or_No == 'n' ) ;
            printf( "-----------------------\n" ) ;
            printf( ">> ใส่บะหมี่กึ่งสำเร็จรูปได้เลย <<\n" ) ;
            printf( "-----------------------\n" ) ;
            printf( ">> นำบะหมี่ใส่ชาม <<\n" ) ;

            break ;
  }//end if
    }//end while
    return 0 ;  
}//end function