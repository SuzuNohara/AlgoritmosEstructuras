#include<stdio.h>
#include<math.h>

double distance(double x1, double y1, double x2, double y2);

int main(){
    float x1, y1, x2, y2;
    printf("Ingresa las coordenadas X1 y Y1\n");
    scanf("%f", &x1);
    scanf("%f", &y1);
    printf("Ingresa las coordenadas X2 y Y2\n");
    scanf("%f", &x2);
    scanf("%f", &y2);
    printf("(%f,%f) -> (%f,%f) = %.6f\n", x1, y1, x2, y2, distance(x1, y1, x2, y2));
    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}