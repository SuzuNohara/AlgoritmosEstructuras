#include<stdio.h>
#include<stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree* right;
};

struct tree *crateNode(int data);
int fillArray(int data[20]);
int printArray(int data[20]);

int main(){
    int data[20];
    struct tree *raiz;
    fillArray(data);
    for(int i = 0; i < 20; i++){
        if(i == 0){
            raiz -> data = data[i];
        }else{
            raiz -> left = createNode(data[i]);
            raiz -> right = createNode(data[i]);
        }
    }
}

struct tree *createNode(int data){
    struct tree *pointer = (struct tree *) malloc(sizeof(struct tree));
    pointer -> data = data;
    return pointer;
}

int fillArray(int data[20]){
    printf("[");
    for(int i = 0; i < 20; i++){
        data[i] = rand() % 20;
        printf("%d,", data[i]);
    }
    printf("]\n");
}

int printArray(int data[20]){
    printf("[");
    for(int i = 0; i < 20; i++){
        printf("%d,", data[i]);
    }
    printf("]\n");
}