#include <stdio.h>
#include <stdlib.h>

#define temp_max 100
#define temp_min -100

int main() {
    int opcion = 0;
    int arr[15];
    printf("Ingresa la opcion deseada\n");
    printf("1. Manual\n");
    printf("2. Aleatoria\n");
    scanf("%d", &opcion);
    for(int i = 0; i < 15; i++){
        if(opcion == 1){
            printf("ingresa el numero: ");
            scanf("%d", &arr[i]);
        }else if(opcion == 2){
            arr[i] =  (rand() % (temp_max - temp_min) + temp_min) % 100;
        }
    }

    for(int i = 0; i < 15; i++){
        printf("%d\n", arr[i]);
    }

    for(int i = 0; i < 15; i++){
        printf("%d\n", arr[i] * 2);
    }

    for(int i = 0; i < 15; i++){
        printf("%d\n", arr[i] / 3);
    }
}