#include<stdio.h>
#include<stdlib.h>

int *createArr(int size);
int fill(int size, int *arr);
void printArr(int size, int *arr);
void buble(int size, int *arr);
void bubbleStep(int size, int *arr);
void insertion(int size, int *arr);
void insertionStep(int size, int initial, int actual, int*arr);
void selectionSort(int size, int *arr);

int main(){
    int *arr;
    int size = 20;
    // scanf("%d", &size);
    arr = createArr(size);
    fill(size, arr);
    printArr(size, arr);
    selectionSort(20, arr);
    printArr(size, arr);
}

int *createArr(int size){
    int *arr = (int *) malloc(sizeof(int) * size);
    return arr;
}

int fill(int size, int *arr){
    if(size == 0){
        return 0;
    }else{
        *arr = rand() % 20;
        fill(size - 1, ++arr);
        arr--;
        return 0;
    }
}

void printArr(int size, int *arr){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d, ", *arr++);
    }
    printf("]\n");
}

void buble(int size, int *arr){
    for(int i = 0; i < size; i++){
        bubbleStep(size - i, arr);
    }
}

void bubbleStep(int size, int *arr){
    int val1, val2;
    int *aux;
    if(size == 1){
        return;
    }else{
        val1 = *arr;
        ++arr;
        val2 = *arr; 
        if(val1 > val2){
            *arr = val1;
            arr--;
            *arr = val2;
        }else{
            arr--;
        }
        bubbleStep(size - 1, ++arr);
    }
}

void insertion(int size, int *arr){
    for(int i = 0; i < size; i++){
        insertionStep( size, 0, i, arr);
    }
}

void insertionStep(int size, int initial, int actual, int*arr){
    if(size == 0){
        return;
    } else if(actual == 0) {
        return;
    }else{
        int val1, val2;
        int *aux;
        val1 = *arr;
        arr--;
        val2 = *arr;
        if(val2 > val1){
            *arr = val1;
            arr++;
            *arr = val2;
            insertionStep(size + 1, 0, actual, arr);
        }

    }
}

void selectionSort(int size, int *arr){
    int *ar2 = arr;
    for(int i = 0; i < size; i++){
        int max = 0, position;
        for(int j = 0; j < size - i; j++){
            if(*ar2 > max){
                max = *ar2;
                position = j;
            }
            ar2++;
        }
        ar2 = arr;
        arr[position] = arr[size - i];
        arr[size - i] = max;
    }
}