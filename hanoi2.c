#include<stdio.h>

void towerOfHanoi(int n, int* colA, int* colB, int* colC);

int main(){
    int c1[10], c2[10], c3[10];
    int size;
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        system(“clear”);
    }
}

void towerOfHanoi(int n, int* colA, int* colB, int* colC){
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, colA, colC, colB);

    towerOfHanoi(n - 1, colC, colB, colA);
}