#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char*argv[])
{
//MOD 1 START
/*
      char *feeds[] = {"http://www.npr.org/rss/rss.php?id=1019",
                       "http://www.npr.org/rss/rss.php?id=10003", 
                       "http://www.npr.org/rss/rss.php?id=1026"};
      int times = 3; 
      char *phrase = argv[1]; 
      int i; 
      for (i=0; i < times; i++) {
          char var[255];
          sprintf(var, "RSS_FEED=%s", feeds[i]); 
          char *vars[] = {var, NULL}; 
*/      
//MOD 1 END


//MOD 1A START

    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://www.npr.org/rss/rss.php?id=1019", NULL};
    FILE *f = fopen("stories.txt", "a");
    if (!f) {
        error("Can't open stories.txt");
    }

    pid_t pid = fork(); 

//MOD 1A END

//MOD 2 START
/*
        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Can't fork process: %s\n", strerror(errno)); 
            return 1; 
        }
        //!pid same as pid == 0
        if (!pid) {
            if (execle ("/usr/bin/python", "/usr/bin/python", 
                        "./rssgossip.py", phrase, NULL, vars) == -1) {
                fprintf(stderr, "Can't run script: %s\n", strerror(errno));
                return 1;
            }    
    

        } 
}
*/
//MOD 2 END

//MOD 2A START
    
    int descriptor = fileno(f);
    printf("Descriptor number before dup2: %d \n", descriptor);

        if (pid == -1) {
            error("Can't fork process");
        }
        if (!pid) {
            if (dup2(fileno(f), 1) == -1) {
                error("Can't redirect Standard Output");
            }
            if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", 
                phrase, NULL, vars) == -1) {
                error("Can't run script");
            }
        }

//MOD 2A END
    printf("Descriptor number after dup2: %d \n", descriptor);


    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("Error waiting for child process");
    }

    if (WEXITSTATUS(pid_status))
        puts("Error status non-zero"); 

    return 0; 

}

