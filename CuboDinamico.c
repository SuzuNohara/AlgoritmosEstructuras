#include<stdio.h>
#include <stdlib.h>

struct nodo{
    int data;
    struct nodo *sig;
    struct nodo *ant;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

void crearNodo(NodoPtr nodo, int valor);

int main(){
    int size = 5;
    printf("Ingresa el tamano del cubo: ");
    scanf("%d", &size);
    size = size * size * size;
    printf("Creando %d nodos\n", size);
    NodoPtr lista = (NodoPtr) malloc(sizeof(NodoPtr));
    lista -> data = rand() % 20;
    lista -> sig = NULL;
    lista -> ant = NULL;
    printf("Localizacion: %p\n", lista);
    printf("Datos: %d\n", lista -> data);
    printf("Nodo siguiente: %p\n", lista -> sig);
    printf("Nodo anterior: %p\n", lista -> ant);
    for(int i = 0; i < size; i++){
        crearNodo(lista, rand() % 20);
        lista = lista -> sig;
    }
}

void crearNodo(NodoPtr list, int valor){
    printf("Crando nodo con valor: %d\n", valor);
    NodoPtr nodo = (NodoPtr) malloc(sizeof(NodoPtr));
    nodo -> data = valor;
    nodo -> sig = NULL;
    nodo -> ant = list;
    printf("Localizacion: %p\n", nodo);
    printf("Datos: %d\n", nodo -> data);
    printf("Nodo siguiente: %p\n", nodo -> sig);
    printf("Nodo anterior: %p\n", nodo -> ant);
    list -> sig = nodo;
}