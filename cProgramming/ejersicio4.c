#include<stdio.h>
#include<stdlib.h>

struct Asiento{
    int numero;
    int ocupado;
};

int menu();
void printAsientos(struct Asiento asientos[4][25], int num, int opt);
void printAsientosO(struct Asiento asientos[4][25]);
void printAsientosD(struct Asiento asientos[4][25]);
void fillAsientos(struct Asiento asientos[4][25]);

int main(){
    int option = 1;
    int reserva;
    struct Asiento asientos[4][25];
    fillAsientos(asientos);
    while(option < 5 && option > 0){
        option = menu();
        if(option == 1){
            printAsientosD(asientos);
        }else if(option == 2){
            printAsientosO(asientos);
        }else if(option == 3){
            printf("Ingrese el numero de asiento a reservar");
            scanf("%d", &reserva);
            printAsientos(asientos, reserva, 0);
        }else if(option == 4){
            printf("Ingrese el numero de asiento a reservar");
            scanf("%d", &reserva);
            printAsientos(asientos, reserva, 1);
        }
    }
}

int menu(){
    int option;
    printf("Ingresa la opcion deseada\n");
    printf("1.Mostrar asientos disponibles\n");
    printf("2.Mostrar asientos ocupados\n");
    printf("3.Reservar asiento\n");
    printf("4.Cancelar asiento\n");
    printf("5.Salir\n");
    scanf("%d", &option);
    return option;
}

void printAsientos(struct Asiento asientos[4][25], int num, int opt){
    for(int j = 0; j < 24; j++){
        for(int i = 0; i < 4; i++){
            if(asientos[i][j].numero == num){
                asientos[i][j].ocupado = opt;
            }
        }
    }
}

void printAsientosO(struct Asiento asientos[4][25]){
    for(int j = 0; j < 24; j++){
        for(int i = 0; i < 4; i++){
            if(asientos[i][j].ocupado == 0){
                printf("(%d, %d)\t", asientos[i][j].numero, asientos[i][j].ocupado);
            }else{
                printf("(-, -)\t");
            }
        }
        printf("\n");
    }
}
void printAsientosD(struct Asiento asientos[4][25]){
    for(int j = 0; j < 24; j++){
        for(int i = 0; i < 4; i++){
            if(asientos[i][j].ocupado == 1){
                printf("(%d, %d)\t", asientos[i][j].numero, asientos[i][j].ocupado);
            }else{
                printf("(-, -)\t");
            }
        }
        printf("\n");
    }
}

void fillAsientos(struct Asiento asientos[4][25]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 24; j++){
            asientos[i][j].numero = 25 * i + j;
            asientos[i][j].ocupado = 1;
        }
    }
}