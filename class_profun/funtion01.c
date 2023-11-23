#include <stdio.h>

float area (int x1,int x2,int x3,int y1,int y2,int y3 )
{
    float ans = 0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) ;
    if (ans<0)
    {
        return ans *-1;
    }
    return ans;
    
}

int main ()
{
    int x1, x2, x3, y1, y2, y3;
    printf("Input: ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3 );
    printf("Output: %.2f", area(x1, x2, x3, y1, y2, y3));
    return 0;
}