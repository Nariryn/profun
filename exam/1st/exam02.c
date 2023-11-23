#include <stdio.h>

int main()
{
    int i, j, sum = 0;
    printf("Enter number: ");
    scanf("%d", &i);
    for (j = 1; j <= 12; j++)
    {
        sum = i*j;
        printf("%d x %d = %d\n", i, j, sum);
    }
    return 0;
}
