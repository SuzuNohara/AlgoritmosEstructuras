#include<stdio.h>
#include<stdlib.h>

struct connection {
    int data;
    struct node* connect;  
};

struct node{
    int data;
    struct connection conn[];
};

int main(){

}