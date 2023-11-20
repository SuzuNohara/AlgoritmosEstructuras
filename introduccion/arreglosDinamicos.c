#include<stdio.h>
#include<stdlib.h>

int main(){
    int dimention, dim;
    int *arreglo, *even, evenn = 2;
    scanf("%d", &dimention);

    dim = dimention;
    arreglo = (int) calloc(dimention, sizeof(int));
    even = (int) calloc(2, sizeof(int));

    while(dimention-- > 0){
        *arreglo = rand() % 1000;
        if(*arreglo % 2 == 0){
            even = (int) realloc(even, ++evenn * sizeof(int));
        }
        printf("%d\n", *arreglo);
        arreglo++;
    }
    arreglo--;

    printf("______________________________________\n");

    while(dim-- > 0){
        if(*arreglo % 2 == 0){
            *even = *arreglo;
            printf("%d\n", *even);
            even++;
        }
        arreglo--;
    }

    free(arreglo);
    free(even);
}