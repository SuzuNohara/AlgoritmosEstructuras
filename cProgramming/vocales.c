#include<stdio.h>


void contarVocales(char cad[]);
void mayus(char cad[]);
void palabras(char cad[]);

int main(){
    
    int j=0, cont=0;
    char cad[200];
    printf("Ingrese un texto no mayor a 200 caracteres:");
    scanf("%[^\n]", cad);
    
    /*for(i=0; i<200; i++){
        printf("%c", cad[i]);
    }*/
    while(cad[j]!='\0'){
        printf("%c", cad[j]);
        j++;
    }
    contarVocales(cad);
    mayus(cad);
    palabras(cad);
    j=0;
    while(cad[j] != '\0'){
        cont++;
        j++;
    }
    printf("\nHay %d caracteres", cont);
    
    return 0;
}
void contarVocales(char cad[]){
        int j=0;
        int a=0;
        int e=0;
        int i=0;
        int o=0;
        int u=0;
        while(cad[j] != '\0'){
           if(cad[j]=='a' || cad[j]=='A'){
               a++;
           }
           if(cad[j]=='e' || cad[j]=='E'){
               e++;
               
           }
            if(cad[j]=='i' || cad[j]=='I'){
               i++;
               
           }
            if(cad[j]=='o' || cad[j]=='O'){
               o++;
           }
            if(cad[j]=='u' || cad[j]=='U'){
               u++;
           }
        j++;
       }
       printf("\nHay %d a %d e, %d i, %d o y %d u",a,e,i,o,u);
}
void mayus(char cad[]){
    int i=0, cont=0;
    while(cad[i] != '\0'){
        if(cad[i]>='A' && cad[i]<='Z'){
            cont++;
        }
        i++;
    }
    printf("\nHay %d mayusculas", cont);
}
void palabras(char cad[]){
    int i=0, cont=1;
    while(cad[i]!='\0'){
        if(cad[i]==' '){
            cont++;
        }
        i++;
    }
    printf("\nHay %d palabras", cont);
}





