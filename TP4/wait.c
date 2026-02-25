#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char* argv[]){
    int status_fils = 0;
    printf("Le numéro des processus à génerer %s\n",argv[1]);
    int nb_processus = atoi(argv[1]);
    for(int i =0;i< nb_processus;i++){
        pid_t fils = fork();
        if(fils == 0){
            pid_t fils_pid = getpid();
            pid_t fils_ppid = getppid();
            printf("[Fils] Mon PID est %d et mon PPID est %d\n",fils_pid,fils_ppid);
            sleep(2*i);
            printf("Je reprends mon execution\n");
            exit(i);
        }
    }

    for(int i =0;i < nb_processus; i++){
        pid_t fils_termine = wait(&status_fils);//fils_termine retourne le pid de fils retourné et status_fils contient tous les informations de retour
        if(WIFEXITED(status_fils)){
            int retour = WEXITSTATUS(status_fils);
            printf("Fils %d terminé avec valeur %d\n", fils_termine, retour);
        }
    }

    return 0;
}