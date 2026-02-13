#include <stdio.h>

int plus_petit_diviseur(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            printf(" %d",i);
            n = plus_petit_diviseur(n/i);
        }
    }    
    return n;
}

int main(void){
    plus_petit_diviseur(1170701532);
    return 0;
}