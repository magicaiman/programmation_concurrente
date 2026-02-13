#include <stdio.h>


struct point{
    int x;
    int y;
};

float coeff_dir(struct point* p1,struct point* p2){
    if (p2->x == p1->x){
        printf("Error impossible de faire une division par 0 vu que x2 et x1 sont les memes");
        return 1;
    }
    return (p2->y - p1->y)/(p2->x - p1->x);
}

float ordonné(float coeff,struct point* p){
    return (p->y - (coeff * p->x));
}

int main(void){
    return 0;
}