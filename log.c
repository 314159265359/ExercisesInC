#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* now()
{
    time_t t; 
    time (&t); 
    return asctime(localtime (&t)); 
}


char *chomp(char *s)
{
        unsigned int l = strlen(s);

        if (l && s[l - 1] == '\n') {
                s[l - 1] = '\0';
        }
        return s;
}


int main()
{
    char comment[80];
    char cmd[120]; 
    fgets(comment, 80, stdin);
    chomp(comment);
    sprintf(cmd, "echo '%s %s' >> reports.log", comment, now() );
    system(cmd); 
   
    return 0;
}

