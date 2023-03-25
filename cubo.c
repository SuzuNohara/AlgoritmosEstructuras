#include<stdio.h>

int menu();

int main(){
    int arreglo[5][5][5];
    int *p = arreglo;
    int opcion = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                arreglo[i][j][k] = i*100 + j*10 + k;
            }
        }
    }

    opcion = menu();

    if(opcion == 1){
        p = arreglo;
        int cont = 0;
        int cumulo = 0;
        for(int i = 0; i < 5; i++){
            cont = 0;
            cumulo = 0;
            for(int j = 0; j < 5; j++){
                cont += *p;
                p++;
            }
            p++;
            printf("Fila %d: %d\n", i + 1, cont);
        }
    }else if(opcion == 2){
        p = arreglo;
        int cont = 0;
        int cumulo = 0;
        for(int i = 0; i < 5; i++){
            p = arreglo;
            p += i;
            cont = 0;
            cumulo = 0;
            for(int j = 0; j < 5; j++){
                cont += *p;
                p += 5;
            }
            printf("Columna %d: %d\n", i + 1, cont);
        }
    }else if( opcion == 3){
        p = arreglo;
        int cont = 0;
        int cumulo = 0;
        for(int i = 0; i < 25; i++){
            cont += *p;
            p++;
        }
        printf("Cara 1: %d\n", cont);

        cont = 0;
        p = arreglo;
        cumulo = 0;
        for(int i = 0; i < 25; i++){
            cont += *p;
            p += 25;
            cumulo += 25;
            if(cumulo >= 125){
                p = arreglo;
                p += cumulo % 25 + 5;
                cumulo = cumulo % 25 + 5;
            }
        }
        printf("Cara 2: %d\n", cont);

        cont = 0;
        p = arreglo;
        p += 4;
        cumulo = 4;
        for(int i = 0; i < 25; i++){
            cont += *p;
            p += 25;
            cumulo += 25;
            if(cumulo >= 125){
                p = arreglo;
                p += cumulo % 25 + 5;
                cumulo = cumulo % 25 + 5;
            }
        }
        printf("Cara 3: %d\n", cont);

        cont = 0;
        p = arreglo;
        p += 100;
        for(int i = 0; i < 25; i++){
            cont += *p;
            p++;
        }
        printf("Cara 4: %d\n", cont);

        cont = 0;
        p = arreglo;
        p += 0;
        cumulo = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cont += *p;
                p++;
                cumulo++;
            }
            p += 20;
            cumulo += 20;
        }
        printf("Cara 5: %d\n", cont);

        cont = 0;
        p = arreglo;
        p += 20;
        cumulo = 0;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cont += *p;
                p++;
                cumulo++;
            }
            p += 20;
            cumulo += 20;
        }
        printf("Cara 6: %d\n", cont);
    }
}

int menu(){
    int opcion;
    printf("Seleccione la opcion deseada\n");
    printf("1. Suma de filas\n");
    printf("2. Suma de columnas\n");
    printf("3. Suma de caras\n");
    scanf("%d", &opcion);
    return opcion;
}