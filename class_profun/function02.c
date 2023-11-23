#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
int main ()
{
    int as, bs;
    printf("Enter Input: ");
    scanf ("%d %d", &as, &bs);
    swap(&as, &bs);
    printf("Output: %d %d", as, bs);
    return 0;

}