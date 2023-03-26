#include<stdio.h>
#include<math.h>

void radConvertion(float *x, float *y);
float degRad(float value);
float radDeg(float value);
float distance(float x1, float y1, float x2, float y2);
float angle(float x, float y);

double PI = 3.14159265358979323846;

int main(){
    float x1, x2, y1, y2, m, c;
    float r1, r2, a1, a2;
    printf("Ingresa los valores de (x1, y1)\n");
    scanf("%f %f", &x1, &y1);
    printf("Ingresa los valores de (x2, y2)\n");
    scanf("%f %f", &x2, &y2);
    r1 = distance(x1, y1, 0, 0);
    r2 = distance(x2, y2, 0, 0);
    a1 = angle( x1, y1);
    a2 = angle( x2, y2);

    printf("( %.2f, %.2f ) -> ( %.2f ) <) ( %.2f )\n", x1, y1, r1, a1);
    printf("( %.2f, %.2f ) -> ( %.2f ) <) ( %.2f )\n", x2, y2, r2, a2);

    printf("Distancia entre puntos: %f\n", distance(x1, y1, x2, y2));
    m = (y1 - y2) / (x1 - x2);
    c = (m * (-x1)) + y1;
    printf("Ecuacion: Y = %.2fX + (%.2f)\n", m, c);
    printf("Pendiente: %.2f\n", m);
    printf("Suma de puntos: ( %.2f ) , i( %.2f )\n", x1 + x2, y1 + y2);
    printf("Resta de puntos: ( %.2f ) , i( %.2f )\n", x1 - x2, y1 - y2);
    printf("Producto de puntos: %.2f <) %.2f\n", r1 * r2, a1 + a2);
    printf("Division de puntos: %.2f <) %.2f\n", r1 / r2, a1 - a2);
}

void radConvertion(float *x, float *y){
    *y = radDeg(atan(*x / *y));
    *x = sqrt(pow(*x, 2) + pow(*y, 2));
}

float degRad(float value){
    return (PI * value) / 180;
}

float radDeg(float value){
    return (180 * value) / PI;
}

float distance(float x1, float y1, float x2, float y2){
    float x = x2 - x1;
    float y = y2 - y1;
    return sqrt(pow(x, 2) + pow(y, 2));
}

float angle(float x, float y){
    if(x == 0 && y > 0){
        return 90;
    } else if(x == 0 && y < 0){
        return 270;
    }
    float angle = radDeg(atan(y / x));
    if(x < 0 && y > 0){
        angle += 180;
    }
    if(x <= 0 && y < 0){
        angle += 180;
    }
    return angle;
}