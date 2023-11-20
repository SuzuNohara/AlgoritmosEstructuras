#include<stdio.h>
#include<stdlib.h>

int copyArray(int a[16], int b[16]){
    for(int i = 0; i < 16; i++){
        b[i] = a[i];
    }
}

int fillArray(int data[16]){
    printf("[");
    for(int i = 0; i < 16; i++){
        data[i] = rand() % 16;
        printf("%d,", data[i]);
    }
    printf("]\n");
}

int printArray(int data[16]){
    printf("[");
    for(int i = 0; i < 16; i++){
        printf("%d,", data[i]);
    }
    printf("]\n");
}

int mergueStep(int size, int data[16], int order[16]){
    for(int i = 0; i < 16; i+=size){
        printf("[");
        for(int j = 0; j < size; j++){
            printf("%d,", data[i + j]);
        }
        printf("]\n");
        int ini = i, end = (int) i + size / 2;
        for(int j = 0; j < size; j++){
            if(ini >= (int) i + size / 2){
                order[i + j] = data[end];
                end++;
            }else if(end >= (int) i + size){
                order[i + j] = data[ini];
                ini++;
            }else{
                if(data[ini] > data[end]){
                    order[i + j] = data[end];
                    end++;
                }else{
                    order[i + j] = data[ini];
                    ini++;
                }
            }
        }
    }
    copyArray(order, data);
    printArray(data);
}

int main(){
    int data[16];
    int order[16];
    fillArray(data);
    mergueStep(2, data, order);
    printf("___________________________\n");
    mergueStep(4, data, order);
    printf("___________________________\n");
    mergueStep(8, data, order);
    printf("___________________________\n");
    mergueStep(16, data, order);
    printf("___________________________\n");
}
