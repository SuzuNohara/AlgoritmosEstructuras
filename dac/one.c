#include <stdio.h>
#include <stdlib.h>

/*
Edgardo se puso un poco intenso este semestre y puso a trabajar a sus alumnos con problemas de mayor dificultad.

La tarea es simple, dado un arreglo 
 de números enteros debes imprimir cual es la suma máxima en cualquier subarreglo contiguo.

Por ejemplo si el arreglo dado es {-2, -5, 6, -2, -3, 1, 5, -6}, entonces la suma máxima en un subarreglo contiguo es 7.

Entrada
La primera línea contendrá un numero 
.

En la siguiente línea 
 enteros representando el arreglo 
.

Salida
La suma máxima en cualquier subarreglo contiguo.
*/

int max = -9999999;

void sum(int *arr, int orig, int fin);
void retroSum(int *arr, int orig, int size);
void forwardSum(int *arr, int orig, int size);

int main() {
    int count;
    int *arr, *root;

    scanf("%d", &count);
    printf("Size of array: %d\n", count);
    arr = malloc(sizeof(int) * count);
    root = arr;
    for(int i = 0; i < count; i++){
        printf("Numero %d: ", i);
        scanf("%d", arr);
        arr++;
    }
    arr = root;
    forwardSum(arr, 0, count);
    printf("---%d", max);
    return 0;
}

void sum(int *arr, int orig, int fin){
    int sumatoria = 0;
    for(int i = orig; i < fin; i++){
        sumatoria += arr[i];
    }
    if(sumatoria > max){
        max = sumatoria;
    }
}

void retroSum(int *arr, int orig, int size){
    int retorno;
    if(orig == size){
        return 0;
    }else{
        sum(arr, orig, size);
        retroSum(arr, orig, size - 1);
    }
}

void forwardSum(int *arr, int orig, int size){
  if(orig = size){
    return;
  }else{
    forwardSum(arr, orig + 1, size);
    retroSum(arr, orig, size);
    return;
  }
}