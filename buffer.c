#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 255

int main(int argc, char *argv[])
{
    FILE *viewfile;
    char buffer[BUFSIZE+1]; 

    if(argc<2)
    {
        puts("Missing filename!"); 
        puts("Here is the format:"); 
        puts("VIEW filename");
        exit(1);
    }

    viewfile = fopen(argv[1], "r");
    if(!viewfile)
    {
        printf("Error opening %s \n", argv[1]);
        exit(1);
    }

    while(fgets(buffer, BUFSIZE, viewfile))
        printf("%s", buffer);
    fclose(viewfile);
 
    return(0);

}
