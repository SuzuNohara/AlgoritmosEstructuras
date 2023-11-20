#include<stdio.h>
#include<stdlib.h>

int coords(int *mapx, int *mapy, int stars);

int main(){
    int stars = 0;
    int *mapx, int *mapy;
    scanf("%d", &stars);
    mapx = malloc(sizeof(int) * stars);
    mapy = malloc(sizeof(int) * stars);
    for(int i = 0; i < stars; i++){
        scanf("%d", mapx);
        scanf("%d", mapy);
    }

}

int coords(int *mapx, int *mapy, int stars){
    int min = 0;
    for(int i = 0; i < stars; i++){
        distances(mapx, mapy, i, stars);
    }
    return min;
}

int distances(int *mapx, int*mapy, int initial, int stars){
    int min = 0;
    int dis = 0;
    min = dist(mapx, mapy, initial, stars);
    dis = distances(mapx, mapy, initial, stars - 1);
    if(min < dis){
        return min;
    }else{
        return dis;
    }
}

int dist(int *mapx, int *mapy, int stars, int step){
    int min = 0, dis = 0;
    for(int i = 0; i < stars - step; i++){
        dis = sqrt(pow(mapx[stars - i] - mapx(step), 2) + pow((mapy[stars - i] + mapy[step], 2) - (mapy + step), 2));
        if(min > dis){
            min = dis;
        }
    }
    return min;
}