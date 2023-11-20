#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point{
    int id;
    float x, y;
    float ang, r;
};
double PI = 3.14159265358979323846;

int menu();
struct Point randPoint(int id);
struct Point manualPoint(int id);
void radConvertion(float *x, float *y);
float degRad(float value);
float radDeg(float value);
float distance(float x1, float y1, float x2, float y2);
float angle(float x, float y);
struct Point add(struct Point p1, struct Point p2);
struct Point less(struct Point p1, struct Point p2);
struct Point product(struct Point p1, struct Point p2);
struct Point divition(struct Point p1, struct Point p2);

void printPoints(struct Point points[]);
void printPoint(struct Point point);

float genX(struct Point p);
float genY(struct Point p);

void writePoints(struct Point points[]);
struct Point * readPoints();
void writeResults(struct Point points[]);

float minDistance(struct Point points[]);
float minDistanceTo(struct Point p, struct Point points[]);


int main(){
    int option = 1;
    int count = 200;
    int c;
    struct Point points[200];
    struct Point p;
    int p1, p2;
    int id;
    while(option < 13 && option > 0){
        option = menu();
        switch(option){
            case 1:
                c = 0;
                while(c++ < 200){
                    points[c] = randPoint(c);
                }
            break;
            case 2:
                printf("Ingrese la cantidad de puntos\n");
                scanf("%d", &count);
                c = 0;
                while(c++ < count){
                    points[c] = manualPoint(c);
                }
            break;
            case 3:
            break;
            case 4:
                printf("Ingrese los id de los puntos a sumar");
                scanf("%d%d", &p1, &p2);
                p = add(points[p1], points[p2]);
                printf("El resultado de la suma es: \n");
                printPoint(p);
            break;
            case 5:
                printf("Ingrese los id de los puntos a restar");
                scanf("%d%d", &p1, &p2);
                p = less(points[p1], points[p2]);
                printf("El resultado de la resta es: \n");
                printPoint(p);
            break;
            case 6:
                printf("Ingrese los id de los puntos a multiplicar");
                scanf("%d%d", &p1, &p2);
                p = product(points[p1], points[p2]);
                printf("El resultado de la multiplicacion es: \n");
                printPoint(p);
            break;
            case 7:
                printf("Ingrese los id de los puntos a dividir");
                scanf("%d%d", &p1, &p2);
                p = divition(points[p1], points[p2]);
                printf("El resultado de la division es: \n");
                printPoint(p);
            break;
            case 8:
                printf("Distancia entre puntos");
                for(int i = 0; i < count - 1; i++){
                    printPoint(points[i]);
                    for(int j = i + 1; j < count; j++){
                        printf("%d - %d (%.2f)\n", points[i].id, points[j].id, distance(points[i].x, points[i].y, points[j].x, points[j].y));
                    }
                }
            break;
            case 9:
                printf("La menor distancia entre puntos es: %.2f\n", minDistance(points));
            break;
            case 10:
                printf("Ingrese el punto inicial: \n");
                scanf("%d", &id);
                printPoint(points[id]);
                for(int j = 0; j < count; j++){
                    printf("%d - %d (%.2f)\n", points[id].id, points[j].id, minDistanceTo(points[id], points));
                }
            break;
            case 11:
                for(int j = 0; j < count; j++){
                    printPoint(points[j]);
                }
            break;
            case 13:

            break;
        }
    }
}

int menu(){
    int option;
    printf("1.- Genera lista de puntos aleatoriamente\n");// check
    printf("2.- Genera lista de puntos manualmente\n");// check
    printf("3.- Obtener puntos de archivo\n");
    printf("4.- Suma puntos\n");// check
    printf("5.- Resta puntos\n");// check
    printf("6.- Multiplica puntos\n");// check
    printf("7.- Divide puntos\n");// check
    printf("8.- Determina distancia entre puntos\n");// check
    printf("9.- Determina la menor distancia entre puntos\n");
    printf("10.- Determinar el punto vecino más cercano\n");
    printf("11.- Imprime detalles de puntos\n");//check
    printf("13.- Salir\n");
    scanf("%d", &option);
    return option;
}

struct Point randPoint(int id){
    struct Point p;
    p.id = id;
    p.x = rand() % 400 - 200;
    p.y = rand() % 400 - 200;
    p.ang = angle(p.x, p.y);
    p.r = distance(p.x, p.y, 0, 0);
    return p;
}

struct Point manualPoint(int id){
    struct Point p;
    p.id = id;
    printf("Ingrese el calor de X\n");
    scanf("%f", &p.x);
    printf("Ingrese el calor de Y\n");
    scanf("%f", &p.y);
    p.ang = angle(p.x, p.y);
    p.r = distance(p.x, p.y, 0, 0);
    return p;
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

struct Point add(struct Point p1, struct Point p2){
    struct Point p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    p.ang = angle(p.x, p.y);
    p.r = distance(p.x, p.y, 0, 0);
    return p;
}
struct Point less(struct Point p1, struct Point p2){
    struct Point p;
    p.x = p1.x - p2.x;
    p.y = p1.y - p2.y;
    p.ang = angle(p.x, p.y);
    p.r = distance(p.x, p.y, 0, 0);
    return p;
}
struct Point product(struct Point p1, struct Point p2){
    struct Point p;
    p.r = p1.r * p2.r;
    p.ang = p1.ang + p2.ang;
    p.x = genX(p);
    p.y = genY(p);
    return p;
}
struct Point divition(struct Point p1, struct Point p2){
    struct Point p;
    p.r = p1.r / p2.r;
    p.ang = p1.ang - p2.ang;
    p.x = genX(p);
    p.y = genY(p);
    return p;
}

void printPoints(struct Point points[]){
    int count = 0;
    while(count++ < sizeof(points)){
        printPoint(points[count]);
    }
}

void printPoint(struct Point point){
    printf("(%.2f,%.2f) - (%.2f, %.2f)\n", point.x, point.y, point.r, point.ang);
}

float genX(struct Point p){
    return p.r * acos(degRad(p.ang));
}
float genY(struct Point p){
    return p.r * asin(degRad(p.ang));
}

void writePoints(struct Point points[]){
    FILE *file;
    file = fopen("points.txt","w");
    // fprintf(file,"%d, %.2f, %.2f, %.2f, %.2f\n",p.id, p.x, p.y, p.r, p.ang);
    fclose(file);
}
struct Point * readPoints(){
    char line[2000];
    int count = 0;
    FILE *file;
    file = fopen("points.txt","r");
    while(line != EOF){
        fscanf(file,"%2000[^\n]", line);
        count++;
    }
    struct Point points[count + 1];
    fclose(file);
    file = fopen("points.txt","r");
    while(line != EOF){
        fscanf(file,"%2000[^\n]", line);
        count++;
    }
    // struct Point points[count + 1];
    fclose(file);
    // pendiente
}
void writeResults(struct Point points[]){
    FILE *file;
    file = fopen("results.txt","w");
    // fprintf(file,"%d, %.2f, %.2f, %.2f, %.2f\n",p.id, p.x, p.y, p.r, p.ang);
    fclose(file);
    // pendiente
}

float minDistance(struct Point points[]){
    float min = 400;
    for(int i = 0; i < sizeof(points); i++){
        for(int j = 0; i < sizeof(points); i++){
            if(i != j){
                if(distance(points[i].x, points[i].y, points[j].x, points[j].y) < min){
                    min = distance(points[i].x, points[i].y, points[j].x, points[j].y);
                }
            }
        }   
    }
}
float minDistanceTo(struct Point p, struct Point points[]){
    float min = 400;
    for(int i = 0; i < sizeof(points); i++){
        if(p.id != points[i].id){
            if(distance(p.x, p.y, points[i].x, points[i].y) < min){
                min = distance(p.x, p.y, points[i].x, points[i].y);
            }
        }
    }
}