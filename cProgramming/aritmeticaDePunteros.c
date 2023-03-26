#include<stdio.h>
#include<math.h>

int main(){
    int a, b, c, d, e, f, g, *ptr, arr[4], arr0[2][3];
    ptr = &a;

    printf("Direcciones de memoria de variables\n");
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);
    printf("%p\n", &e);
    printf("%p\n", &f);
    printf("%p\n", &g);
    printf("Direcciones de memoria de arreglo unidimencional\n");
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[2]);
    printf("%p\n", &arr[3]);
    printf("Direcciones de memoria de arreglo bidimencional\n");
    printf("%p\n", &arr0[0][0]);
    printf("%p\n", &arr0[0][1]);
    printf("%p\n", &arr0[0][2]);
    printf("%p\n", &arr0[1][0]);
    printf("%p\n", &arr0[1][1]);
    printf("%p\n", &arr0[1][2]);

    // la memoria se asigna en la cantidad de paquetes que cooresponden al tipo de la variable que se esta asignando
    // navegacion de un puntero de forma descendente entre las variables que componen el programa
    /* for(int i = 0; i < 4; i++){
        *ptr = i;
        ptr--;
    }*/
    ptr = &arr[0];
    for(int i = 0; i < 4; i++){
        *ptr = i;
        printf("%d\n", *ptr);
        ptr++;
    }
    ptr = &arr0[0][0];
    for(int i = 0; i < 6; i++){
        *ptr = i;
        printf("%d\n", *ptr);
        ptr++;
    }

    ptr = &arr[0];
    for(int i = 0; i < 4; i++){
        *ptr = *ptr * 2;
        printf("%d\n", *ptr);
        ptr++;
    }
    ptr = &arr0[0][0];
    for(int i = 0; i < 6; i++){
        *ptr = *ptr * 2;
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}