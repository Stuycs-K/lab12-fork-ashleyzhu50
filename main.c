#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    pid_t fork1;
    pid_t fork0;
    int * status=malloc(sizeof(int *));
    int randnum; int randnum2;
    printf("%d about to create 2 child processes\n", getpid());
    fork1 =fork();
    int r_file = open("/dev/urandom", O_RDONLY,0);
    if(fork1==0){ // first child
        int *p = malloc(sizeof(p));
        read(r_file, p, sizeof(p));
        randnum = (*p) %5 ;
        if(randnum<=0){
            randnum+=5;
        }
        printf("%d %dsec \n", getpid(), randnum);
        sleep(randnum);
        printf("%d finished after %dsec\n", getpid(), randnum);
        exit(randnum);
    }
    if(fork1>0){
        fork0=fork();
        if(fork0==0){ // second child
            int *pt = malloc(sizeof(pt));
            read(r_file, pt, sizeof(pt));
            int randnum = (*pt) %5 ;
            if(randnum<=0){
                randnum+=5;
            }
            printf("%d %dsec \n", getpid(), randnum);
            sleep(randnum);
            printf("%d finished after %dsec\n", getpid(), randnum);
            exit(randnum);
        }
        int d = wait(status);
        if(WIFEXITED(*status)!=-1){
            printf("Main Process %d is done. Child %d slept for %d sec!\n", getpid(), d, WEXITSTATUS(*status));
        }
        exit(0);
    }
}