#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    pid_t fork1;
    printf("%d about to create 2 child processes\n", getpid());
    fork();
    fork1 =fork();
    int r_file = open("/dev/random", O_RDONLY,0);
    if(fork1==0){
        printf("%d", getpid());
    }
    
}