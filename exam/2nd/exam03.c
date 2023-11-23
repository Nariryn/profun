#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double side1 = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    double side2 = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
    double side3 = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    double primeter = side1 + side2 + side3;
    printf("%.3lf", primeter);
    return 0;
}