#include<stdio.h>

char string[200];

int main() {
    int vauls[5] = {0,0,0,0,0}, upper = 0, accents[5] = {0,0,0,0,0}, spaces = 0, size = 0;
    printf("Introduce una cadena de texto no mayor a 200 caracteres\n");
    scanf("%[^\n]%*c", string);
    // lowercase(string);
    for(int i = 0; i < 200; i++){
        if(string[i] >= 65 && string[i] <= 90) {
            string[i] += 32;
            upper++;
        }
        if(string[i] == 160){
            accents[0]++;
            vauls[0]++;
        } else if(string[i] == 130){
            accents[1]++;
            vauls[1]++;
        } else if(string[i] == 161){
            accents[2]++;
            vauls[2]++;
        } else if(string[i] == 162){
            accents[3]++;
            vauls[3]++;
        } else if(string[i] == 163){
            accents[4]++;
            vauls[4]++;
        }
        if(string[i] == 32){
            spaces++;
        }
        if(string[i] == "\0"){
            size = i;
        }
    }
    for(int i = 0; i < sizeof(string); i++){
        if(string[i] == 'a'){
            vauls[0]++;
        } else if(string[i] == 'e'){
            vauls[1]++;
        } else if(string[i] == 'i'){
            vauls[2]++;
        } else if(string[i] == 'o'){
            vauls[3]++;
        } else if(string[i] == 'u'){
            vauls[4]++;
        }
    }
    printf("Frecuencia de vocales\n");
    printf("________________________________\n");
    printf("a :: %d \n", vauls[0]);
    printf("e :: %d \n", vauls[1]);
    printf("i :: %d \n", vauls[2]);
    printf("o :: %d \n", vauls[3]);
    printf("u :: %d \n\n", vauls[4]);

    printf("Mayusculas: %d\n\n", upper);

    printf("Frecuencia de acentos\n");
    printf("________________________________\n");
    printf("a :: %d \n", accents[0]);
    printf("e :: %d \n", accents[1]);
    printf("i :: %d \n", accents[2]);
    printf("o :: %d \n", accents[3]);
    printf("u :: %d \n\n", accents[4]);

    printf("Palabras: %d\n\n", spaces);

    printf("Tamano de la cadena: %d\n\n", spaces);
}