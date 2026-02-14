#include <stdio.h>
#include <stdlib.h>


#define GAUCHE(i) (2 * (i) + 1)
#define DROITE(i) (2 * (i) + 2)
#define PARENT(i) (((i) - 1) / 2)
#define CAPACITE_MAX 15

void entasser(int* tab, int* taille_utile,int taille_reelle ,int valeur){
    if(*taille_utile >= taille_reelle){
        printf("Erreur : le tas est plein, impossible d'ajouter la valeur %d\n", valeur);
        return;
    }
    tab[*taille_utile] = valeur;
    *taille_utile += 1;
    int indice = *taille_utile - 1;
    int parent = PARENT(indice);
    if(indice == 0){
        printf("L'element %d a été ajouté en premier positon",valeur);
        return;
    }
    while(indice > 0){
        if(tab[indice] < tab[parent]){
            int temp = tab[indice];
            tab[indice] = tab[parent];
            tab[parent] = temp;
            indice = parent;
            parent = PARENT(indice);
        }else{
            break;
        }
    }
}

void detasser(int* tab, int* taille_utile){
    printf("Voici le premier element du tableau: %d\n",tab[0]);
    printf("Voici l'élément le plus à droite possible du dernier niveau: %d \n", tab[*taille_utile - 1]);
    tab[0] = tab[*taille_utile - 1];
    *taille_utile = *taille_utile - 1;
    int indice  = 0;
    while (GAUCHE(indice) < *taille_utile){
        //imagine juste fils gauche
        int indice_min_fils = GAUCHE(indice);
        if(DROITE(indice) < *taille_utile && tab[DROITE(indice)] < tab[indice_min_fils]){
            indice_min_fils = DROITE(indice);
        }
        if(tab[indice_min_fils] < tab[indice]){
            int temp = tab[indice];
            tab[indice] = tab[indice_min_fils];
            tab[indice_min_fils] = temp;
            indice = indice_min_fils;
        }else{
            break;
        }
    }
}

void afficher_tas(int* tab, int taille) {
    printf("[ ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}


int main(void) {
    int tas[100];
    int taille_utile = 0;
    int capacite = 100;

    // 1. On reconstruit le tas (comme on l'a fait avant)
    int valeurs[] = {40, 51, 62, 48, 49, 55, 38, 42, 39};
    for (int i = 0; i < 9; i++) {
        entasser(tas, &taille_utile, capacite, valeurs[i]); // Ajoute "capacite" si tu as gardé cette version
    }

    printf("--- ÉTAT INITIAL DU TAS ---\n");
    // [ 38 39 40 42 49 62 55 51 48 ]
    for(int i=0; i<taille_utile; i++) printf("%d ", tas[i]);
    printf("\n\n");

    // 2. On teste le détassement (Extraction du Min)
    printf("--- EXTRACTION 1 ---\n");
    detasser(tas, &taille_utile);
    
    // Le 38 a dû disparaître, et le tableau a dû se réorganiser !
    printf("Tas apres extraction : ");
    for(int i=0; i<taille_utile; i++) printf("%d ", tas[i]);
    printf("\n\n");

    // 3. On teste une deuxième extraction
    printf("--- EXTRACTION 2 ---\n");
    detasser(tas, &taille_utile);
    
    printf("Tas apres 2eme extraction : ");
    for(int i=0; i<taille_utile; i++) printf("%d ", tas[i]);
    printf("\n");

    return 0;
}