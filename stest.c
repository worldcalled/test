#include <signal.h>
#include <stdio.h>

void sigcatch(int);
void sigc2(int);
void sigc4(int);

int main() {
    if (SIG_ERR == signal(SIGHUP, sigcatch)) {
        printf("failed to set signal handler\n");
        exit(1);
    }

    if (SIG_ERR == signal(SIGINT, sigc2)) {
        printf("failed to set signal handler\n");
        exit(1);
    }
	
    if (SIG_ERR == signal(SIGILL, sigc4)) {
        printf("failed to set signal handler\n");
        exit(1);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}
 
void sigcatch(int sig) {
    printf("catch signal %d\n", sig); 
    exit(1);
}

void sigc2(int sig){
    printf("sig %d\n", sig); 
    exit(1);
}
void sigc4(int sig){
    printf("ctrl + C %d\n", sig); 
    exit(1);
}

