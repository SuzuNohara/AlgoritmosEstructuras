#include<stdio.h>

int tablero(int n, int tab[8][8]);
int valid(int tab[8][8]);
void printTablero(int tab[8][8]);
void cleanTable(int *tabP);
int horizontal(int tab[8][8]);
int vertical(int tab[8][8]);

int main(){
    int tab[8][8];
    int *tabP = tab;
    int result = 0;
    cleanTable(tabP);
    for(int i = 0; i < 3; i++){
        for(int i = 0; i < 3; i++){
            result = tablero(0, tab);
        }
    }
    printf("\n%d\n", result);
}

int tablero(int n, int tab[8][8]){
    if(n == 8){
        return valid(tab);
    }else{
        int retorno = 0;
        int *p = tab;
        for(int i = 0; i < 64; i++){
            if(*p == 0){
                *p = 1;
                retorno += tablero(n + 1, tab);
                *p = 0;
                p++;
            }
        }
        return retorno;
    }
}

int valid(int tab[8][8]){
    int tabs[8][2];
    int found = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(tab[i][j] == 1){
                tabs[found][0] = i;
                tabs[found][1] = j;
                // printf("[%d,%d]\n", tabs[found][0], tabs[found][1]);
                found++;
            }
        }
    }
    // printf("Reynas en el trablero: %d", found);
    for(int i = 0; i < found - 1; i++){
        for(int j = i + 1; j < found; j++){
            // printf("%d - %d == %d - %d\n", tabs[i][0], tabs[j][0], tabs[i][1], tabs[j][1]);
            if(tabs[i][0] - tabs[j][0] == tabs[i][1] - tabs[j][1]){
                return 0;
            }else if(tabs[i][0] == tabs[j][0] || tabs[i][1] == tabs[j][1]){
                return 0;
            }else if(tabs[i][0] == tabs[j][0] || tabs[i][1] == tabs[j][1]){
                return 0;
            }
        }
    }
    printTablero(tab);
    return 1;
}

void printTablero(int tab[8][8]){
    for(int i = 0; i < 8; i++){
        printf("_________________________________________________________\n\n");
        for(int j = 0; j < 8; j++){
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
    printf("_________________________________________________________\n");
}

void cleanTable(int *tabP){
    for(int i = 0; i < 64; i++){
        *tabP = 0;
        tabP++;
    }
}