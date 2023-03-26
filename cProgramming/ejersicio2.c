#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int n);
void frecuencias(int frec[], int arr[]);

int main(){
    int dados[5];
    int frec[5];
    int r1, r2, r3, r4;
    int max = 0;
    int rep = 0;
    int tree = 0;
    int dos = 0;

    for(int i = 0; i < 5; i++){
        dados[i] = (rand() % 6) + 1;
        frec[i] = 0;
    }

    bubbleSort(dados, 5);
    frecuencias(frec, dados);

    for(int i = 0; i < 5; i++){
        printf("%d\n", dados[i]);
    }

    r1 = dados[0];
    r2 = 0;
    for(int i = 1; i < 5; i ++){
        if(dados[i] == r1){
            r2++;
        }
    }
    if(r2 == 5){
        printf("Son 5 resultados del mismo valor");
        exit(0);
    }

    for(int j = 0; j < 5; j++){
        r1 = dados[j];
        r3 = 0;
        r4 = 0;
        for(int i = j; i < 5; i ++){
            if(dados[i] == r1){
                r3++;
            }
        }
        if(r3 == 4){
            printf("Pokar de %d", r1);
            exit(0);
        }else if(r3 == 3){
            printf("Tercia de %d", r1);
            exit(0);
        }else if(r3 == 2){
            printf("Par de de %d", r1);
            exit(0);
        }else if(r3 == 2){
            printf("Par de %d", r2);
            exit(0);
        }
    }

    r1 = 0;
    r2 = 0;
    for(int i = 1; i < 5; i ++){
        if(dados[i] == dados[i - 1] + 1){
            r2++;
        }
    }
    if(r2 == 4){
        printf("Escalera %d SON 5 valores distintos consecutivos", dados[4]);
    }
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void frecuencias(int frec[], int arr[]){
    for(int i = 0; i < 5; i++){
        frec[arr[i - 1]]++;
    }
}