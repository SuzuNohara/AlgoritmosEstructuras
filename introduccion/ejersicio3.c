#include<stdio.h>
#include<stdlib.h>

struct persona{
    int id;
    char[50] nombre;
    char[50] apellidos;
    char[50] telefono;
    char[50] calle;
    int numero;
    char[50] email;
};

int main(){
    struct persona pers[100];
    FILE *a=NULL;
    a = fopen("agenda.txt", "at+");
    if(a == null)
}