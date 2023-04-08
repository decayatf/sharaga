#include <stdio.h>
#include <math.h>
int a = 1, b = -2, c = -24;
double x1, x2, d;

void main(){
    d = pow(b, 2) - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / (a * 2);
        x2 = (-b - sqrt(d)) / (a * 2);
        printf("x1 = %f , x2 = %f" , x1 , x2);
    } else if (d==0){
        x1 = (-b) / (a * 2);
        printf("x1 = %f" , x1);
    } else
    {printf("корней нет");}
}