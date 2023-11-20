#include<stdio.h>
#include<stdlib.h>

int v(int s1, int s2, int c1, int c2, int x1, int x2);

int main(){

}

int v(int v0, int s1, int s2, int c1, int c2, int x1, int x2){
    if(s1 == c1 && s2 == c2){
        return v;
    }else{
        if(c1 - s1 > c2 - s2 && v0 % x2 == 0){
            s2++;
            return v(v0 + 1, s1, s2, c1, c2, x1, x2);
        }else if(c1 - s1 > c2 - s2 && v0 % x1 == 0{
            s1++;
            return v(v0 + 1, s1, s2, c1, c2, x1, x2);
        }
    }
}