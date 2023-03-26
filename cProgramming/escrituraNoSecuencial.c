#include <stdlib.h>//Si no incluyo esta biblioteca, la funcion rand() hace cosas raras
#include <stdio.h>
#include <time.h>
int main()
{
    int a[30];
    time_t b;
    FILE * arch;
    
    srand((unsigned) time(&b));
    
    for(int i=0; i<30; i++){
        a[i]=(-100 + rand()%200);
        printf("%d\n", a[i]);//Imprimimos números en la terminal para comparar los del archivo con el interprete
    }

    arch = fopen("Seek.bin", "wb");

    if (arch == NULL)
        printf("\n Error de apertura del archivo");
    else{
        fwrite(a, sizeof(int), 30, arch);
    }

    printf("El apuntador actual al archivo esta en el byte %d\n", ftell(arch));//deberia indicar el final del archivo
    fseek(arch, 60, SEEK_SET); /*SEEKSET nos dice que empieza a contar el movimiento del apuntador 
    desde el inicio del archivo, independientemente de su posición actual. Es decir, ese parámetro es el ORIGEN del conteo*/
    fputs("8888", arch);
    fseek(arch, 100, SEEK_SET);
    fputs("9999", arch);
    rewind(arch);
    printf("Tras usar la funcion rewind, apuntador actual al archivo esta en el byte %d\n", ftell(arch));
    
    fclose(arch);

    return 0;
}
