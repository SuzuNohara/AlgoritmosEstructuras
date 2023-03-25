#include<stdio.h>
#include<windows.h>
#include<conio.h>

void towerOfHanoi(int n, int from_rod[], int to_rod[], int aux_rod[]);
void printTower(int iteration);

int a[3], b[3], c[3];

int main(){
    int size = 3;
    a[0] = 3;
    a[1] = 2;
    a[2] = 1;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;

    towerOfHanoi(size, a, c, b);
    return 0;
}

void printTower(int iteration){
    printf("Iteration: %d\n", iteration);
    for(int i = 2; i >= 0; i--){
        if(a[i] == 0){
            printf("[-]\t");
        }else{
            printf("[%d]\t", a[i]);
        }
        if(b[i] == 0){
            printf("[-]\t");
        }else{
            printf("[%d]\t", b[i]);
        }
        if(c[i] == 0){
            printf("[-]\t");
        }else{
            printf("[%d]\t", c[i]);
        }
        printf("\n");
    }
    printf("________________________________\n\n\n");
}

void towerOfHanoi(int n, int a[3], int c[3], int b[3]){
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, a, b, c);
    b[n] = a[n];
    a[n] = 0;
    printTower(n);
    printf("Move disk %d from rod %c to rod  %c \n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, b, c, a);
}

// void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
//     if (n == 0) {
//         return;
//     }
//     towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
//     b[n] = a[n];
//     a[n] = 0;
//     printTower(a, b, c);
//     // printf("Move disk %d from rod %c to rod  %c \n", n, from_rod, to_rod);
//     towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
// }