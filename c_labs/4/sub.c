#include <math.h>
#include "sub.h"

float calcPerimetr(float side1, float side2, float side3){
    return side1 + side2 + side3;
}

float calcArea(float side1, float side2, float side3){
    float halfPerimetr = calcPerimetr(side1, side2, side3) / 2;
    float area = sqrt(halfPerimetr * (halfPerimetr - side1) * (halfPerimetr - side2) * (halfPerimetr - side3));
    return area;
}