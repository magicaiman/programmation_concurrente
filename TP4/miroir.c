#include <stdio.h>
#include <stdlib.h>

char* reverse_ordre(char* text){
    int len = 0;
    while (text[len] != '\0') {
        len++;
    }
    char* new_word = malloc(sizeof(char)* (len + 1));
    int i =0;
    new_word[len] = '\0';
    int j = len;
    while(j != 0){
        j--;
        new_word[i] = text[j];
        i++;
    }
    return new_word;
}


int main(int argc, char* argv[]){
    printf("le resultat est %s",reverse_ordre(argv[1]));
    return 0;
}