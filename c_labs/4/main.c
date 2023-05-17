#include <stdio.h>
#include "sub.h"

int main(){
    float side1, side2, side3;

    printf("введите стороны треугольника через 'пробел': ");
    scanf("%f %f %f", &side1, &side2, &side3);
    
    if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2){
        float perimetr = calcPerimetr(side1, side2, side3);
        float area = calcArea(side1, side2, side3);

        printf("периметр равен: %.2f\nплощадь равна: %.2f", perimetr, area);
    } else {
        printf("треугольника не существует");
    }
    return 0;
};

