#include <stdio.h>
#include <string.h>

char *tracks[] = {
    "I left my heart in Harvard Med School", 
    "Newark, Newark - a wonderful town", 
    "Dancing with a Dork", 
    "From here to maternity", 
    "The girl from Iwo Jima", 
};


void find_track(char *searchfor)
{
    int i;
    char *holder;
     
    for (i = 0; i < 5; i++) {
        holder = strstr (tracks[i], searchfor);
    
        if (holder) {
            printf("%s\n", tracks[i]);  
        }   

    }    

}

void print_reverse(char *s)
{
    size_t len = strlen(s); 
    char *t = s + len - 1; 

    while (t >= s) {
        printf("%c", *t); 

        t = t - 1; 
    }
    puts(""); 
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
//  char *searchfor;
    char searchfor[80];
    //searchfor = "town";  

    printf("Search for: "); 
    fgets(searchfor, 80, stdin); 

    chomp(searchfor);

    find_track(searchfor);

    print_reverse(searchfor);  

    return 0;
}


