#include <stdio.h>
#define RECSIZE 14

int main()
{
    FILE *f; 
    char froot[RECSIZE]; 
    char newfroot[RECSIZE] = "NEWberry"; 
    int record, offset; 

    if(!(f=fopen("froot.txt", "r+")))
    {
        puts("Error opening file"); 
        return(1); 
    }

    record = 12; 
    offset = record *RECSIZE;
    fseek(f, offset, SEEK_SET);
    fread(froot, RECSIZE, 1, f); 
    fwrite(newfroot, RECSIZE, 1, f);
    printf("%2d: %s\n", record, froot); 
   
    fclose(f); 
 
    return 0; 

}

