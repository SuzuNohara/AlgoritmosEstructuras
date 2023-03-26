#include<stdio.h>
#include<stdlib.h>

struct connection {
    int data;
    struct node* connect;  
};

struct node{
    int data;
    int size;
    struct connection conn[];
};

typedef struct node Node;
typedef struct connection Conn;

void cNode(int data, int conn, Node *root){
    Node *new = (Node *) malloc(sizeof(Node));

}

void cConn(int conn, Node *ori, Node *dest){
    Conn *new = (Conn *) (sizeof(Conn));
    new -> data = conn;
    new -> conn = 
}

int main(){

}