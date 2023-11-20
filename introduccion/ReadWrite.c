#include <stdio.h>

int a;

int main() {
    int i = 214, *ptr = &i;
    scanf("%i", ptr);
    printf("%p\n", &i);
    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    return 0;
}

int something(){
    return 14;
}