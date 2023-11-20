#include<stdio.h>
#include<stdlib.h>

struct connection {
    int data;
    struct node* connect;  
};

struct node{
    int data;
    int size;
    struct connection *conn;
};

typedef struct node Node;
typedef struct connection Conn;

Node * cNode(int data){
    printf("Creating node %d...\n", data);
    Node *new = (Node *) malloc(sizeof(Node));
    new -> data = data;
    new -> size = 0;
    return new;
}

void cConn(int conn, Node *ori, Node *dest){
    if(ori -> size == 0){
        ori -> size = 1;
        ori -> conn = (Conn *) malloc(sizeof(Conn));
        ori -> conn -> data = conn;
        ori -> conn -> connect = dest;
    }else{
        ori -> size = ori -> size + 1;
        ori -> conn = (Conn *) realloc(ori -> conn, (ori -> size) * sizeof(Conn));
        for(int i = 1; i < ori -> size; i++){
            ori -> conn ++;
        }
        ori -> conn -> data = conn;
        ori -> conn -> connect = dest;
        for(int i = 1; i < ori -> size; i++){
            ori -> conn --;
        }
    }
}

int main(){
    Node *root, *aux;
    root = cNode(0);
    aux = cNode(1);
    cConn(0, root, aux);
    aux = cNode(2);
    cConn(0, root, aux);
    aux = cNode(3);
    cConn(0, root, aux);
    aux = cNode(4);
    cConn(0, root, aux);
    free(root);
    free(aux);
}