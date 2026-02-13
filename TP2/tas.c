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
        printf("L'element %d a été ajouté en premier posiiton",valeur);
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


void afficher_tas(int* tab, int taille) {
    printf("[ ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}
int main(void) {
    int tas[CAPACITE_MAX];
    int taille_utile = 0;

    int valeurs_a_tester[] = {40, 51, 62, 48, 49, 55, 38, 42, 39};
    int nb_valeurs = 9;

    printf("=== CONSTRUCTION DU TAS ===\n");

    for (int i = 0; i < nb_valeurs; i++) {
        int val = valeurs_a_tester[i];
        printf("Ajout de %d... ", val);
        
        entasser(tas, &taille_utile, CAPACITE_MAX, val);

        afficher_tas(tas, taille_utile);
    }

    printf("\n=== RESULTAT FINAL ===\n");
    printf("Taille du tas : %d\n", taille_utile);
    printf("Racine (Min)  : %d\n", tas[0]);
    
    printf("Tableau final : ");
    afficher_tas(tas, taille_utile);

    return 0;
}