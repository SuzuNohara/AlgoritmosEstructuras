#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person {
    int id;
    char aPaterno[20];
    char aMaterno[20];
    char nombre[20];
    float estatura;
    char email[30];
};

int main() {
    struct Person persons[20];

    FILE *file = NULL;

    if((file = fopen("data.dat", "rb+")) == NULL){
        puts("Error opening file");
    }else{
        struct Person p;
        p.id = 0;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[0] = p;
        p.id = 1;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[1] = p;
        p.id = 2;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[2] = p;
        p.id = 3;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[3] = p;
        p.id = 4;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[4] = p;
        p.id = 5;
        strcpy(p.aPaterno, "lopez");
        strcpy(p.aMaterno, "torres");
        strcpy(p.nombre, "etnan");
        p.estatura = 167.3f;
        strcpy(p.email, "namy.nkdca@gmail.com");
        persons[5] = p;
    
        fwrite(persons, sizeof(struct Person) * 20, 1, file);

        puts("content writen");
    }
}