#include <stdio.h>
#include <stdlib.h>


void affichage(int* tab){
    for (int i =0;tab[i] != 0;i++){
        printf("%d",tab[i]);
    }
    printf("\n");
}

int* next_line(int* tab){
    int* new = malloc(100*sizeof(int)); // ici on va stocker la nouvelle ligne 
    int k = 0;
    for(int i=0; tab[i]!=0; ){
        int val = tab[i];
        int cpt = 1;

        while(tab[i+1] == val){
            cpt++;
            i++;
        }

        new[k++] = cpt;
        new[k++] = val;
        i++;
    }

    new[k] = 0;
    return new;
}



int main(void){
    int* ligne = malloc(2*sizeof(int));
    ligne[0] = 3;
    ligne[1] = 0;
    for(int i=0; i<6; i++){
        affichage(ligne);
        ligne = next_line(ligne);
    }
    return 0;
}