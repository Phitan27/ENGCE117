#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Customer {
    public :
        char Name[20] ;
        int Age ;
        char Category[20] ;
        char Product[20] ;
        float Price ;
    public : 
        void GetCustomerInfo( char StrMode[ 50 ] ) ;
} ;

class FileHandler {
    public :
        FILE *fp ;
        char FilePath[ 100 ] ;
        Customer C[ 500 ] ;
        int MaxCustomer ;
    public :
        FileHandler( char FilePath[ 100 ] ) ;
        void GetFilePath() ;
        void ReadFile() ;
        void SelectMode() ;
} ;

int main() {
    FileHandler *F = new FileHandler( "customer.csv" ) ;
    while( 1 ) F->SelectMode() ;
    return 0 ;
}

void FileHandler :: SelectMode() {
    int Mode = 0 ;
    printf( "Select Mode : " ) ;
    scanf( "%d", &Mode ) ;

    if( Mode == 0 ) { //Exit
        printf("Thank you!\n") ;
        exit(0) ;
    } else if( Mode == 1 ) { //Who bought higest price
        int maxIndex = 0 ;
        for (int i = 1 ; i < this->MaxCustomer ; ++i) {
            if (this->C[i].Price > this->C[maxIndex].Price) {
                maxIndex = i ;
            }
        }
        this->C[maxIndex].GetCustomerInfo("Who bought highest price") ;
    } else if( Mode == 2 ) { //Lines of file
        printf( "File data = %d records.\n", this->MaxCustomer ) ;
    } else if( Mode == 3 ) { //Average Price
        float total = 0 ;
        for (int i = 0 ; i < this->MaxCustomer ; ++i) {
            total += this->C[i].Price ;
        }
        printf("Average price = %.2f\n", total / this->MaxCustomer) ;
    } else if( Mode == 4 ) { //Count People who age above average.
        float totalAge = 0 ;
        for (int i = 0 ; i < this->MaxCustomer ; ++i) {
            totalAge += this->C[i].Age ;
        }
        float averageAge = totalAge / this->MaxCustomer ;
        int countAboveAverage = 0 ;
        for (int i = 0 ; i < this->MaxCustomer ; ++i) {
            if (this->C[i].Age > averageAge) {
                ++countAboveAverage ;
            }
        }
        printf("Average age = %.2f.\n", averageAge) ;
        printf("People who aged above average = %d.\n", countAboveAverage) ;
    } else if( Mode == 5 ) { //Most Popular Product
        int maxCount = 0 ;
        char popularProduct[20] ;
        for (int i = 0 ; i < this->MaxCustomer ; ++i) {
            int count = 0 ;
            for (int j = 0 ; j < this->MaxCustomer ; ++j) {
                if (strcmp(this->C[i].Product, this->C[j].Product) == 0) {
                    ++count ;
                }
            }
            if (count > maxCount) {
                maxCount = count ;
                strcpy(popularProduct, this->C[i].Product) ;
            }
        }
        printf("Most popular product = %s (sold %d times).\n", popularProduct, maxCount) ;
    } else if( Mode == 6 ) { //Least Popular Product
        
        int minCount = this->MaxCustomer + 1 ;
        char leastPopularCategory[20] ;
        for (int i = 0 ; i < this->MaxCustomer ; ++i) {
            int count = 0 ;
            for (int j = 0 ; j < this->MaxCustomer ; ++j) {
                if (strcmp(this->C[i].Category, this->C[j].Category) == 0) {
                    ++count ;
                }
            }
            if (count < minCount) {
                minCount = count ;
                strcpy(leastPopularCategory, this->C[i].Category) ;
            }
        }
        printf("Least popular category = %s (sold %d times).\n", leastPopularCategory, minCount) ;
    } else {
        printf("Invalid mode. Exiting...\n") ;
        exit(0) ;
    }
}

FileHandler :: FileHandler( char FilePath[ 100 ] ) {
    strcpy( this->FilePath, FilePath ) ;
    this->ReadFile() ;
}

void FileHandler :: ReadFile() {
    this->fp = fopen(this->FilePath, "r") ;
    if (!this->fp) {
        printf("Error opening file.\n") ;
        exit(1) ;
    }
    this->MaxCustomer = 0;
    while (fscanf(this->fp, "%[^,],%d,%[^,],%[^,],%f\n", this->C[this->MaxCustomer].Name, &this->C[this->MaxCustomer].Age, this->C[this->MaxCustomer].Category, this->C[this->MaxCustomer].Product, &this->C[this->MaxCustomer].Price) != EOF) {
        this->MaxCustomer++ ;
    }
    fclose(this->fp) ;
}

void Customer :: GetCustomerInfo( char StrMode[ 50 ] ) {
    printf( "--------| %-8s\n", StrMode ) ;
    printf("%-8s : %-10s\n", "Name", this->Name ) ; 
    printf("%-8s : %-4d\n", "Age", this->Age ) ;
    printf("%-8s : %-10s\n", "Category", this->Category ) ; 
    printf("%-8s : %-10s\n", "Product", this->Product ) ; 
    printf("%-8s : %-5.2f\n", "Price", this->Price ) ; 
}

void FileHandler :: GetFilePath() {
    printf("File Path: %s\n", this->FilePath) ;
}
