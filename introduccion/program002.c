#include<stdio.h>

int main(void){
    int number1, number2, sum;
    printf("insert first integer: ");
    scanf("%d", &number1);
    printf("insert second integer: ");
    scanf("%d", &number2);
    sum = number1 + number2;
    printf("the sum of the integers is: %d\n", sum);
    puts("something");
}