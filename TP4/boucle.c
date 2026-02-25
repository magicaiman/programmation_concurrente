#include <string.h>
#include <unistd.h>
#include <stdio.h>
int main(void){
    for(int i = 0;i < 3; i++){
        pid_t fils = fork();
        pid_t moi = getpid();
        pid_t pere = getppid();
        printf("%d : Je suis le processus %d, mon père est le processus %d et fork a retoruné  %d \n",i,moi,pere,fils);
    }
    return 0;
}