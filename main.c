#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    pid_t fork1;
    printf("%d about to create 2 child processes\n", getpid());
    fork();
    fork1 =fork();
    int r_file = open("/dev/urandom", O_RDONLY,0);
    if(fork1==0){
        int *p = malloc(sizeof(p));
        read(r_file, p, sizeof(p));
        int randnum = (*p) %5 ;
        if(randnum<=0){
            randnum+=5;
        }
        printf("%d %dsec \n", getpid(), randnum);
        sleep(randnum);
        printf("%d finished after %dsec\n", getpid(), randnum);
        exit(3);
    }
    if(WIFEXITED(fork1)){
        printf("Main Process %d is done. \n", getppid());
    }
}