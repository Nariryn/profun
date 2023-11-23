#include <stdio.h>

void pattern(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || 
                j == 0 || j == n - 1 || 
                i == j || i == n - 1 - j)
                {
                   printf ("*");  
                }            
                           
  
            else
            {
                printf (" ");
            }
                
        }
  
        printf("\n");
    }
}
  
int main()
{
    int n;
    scanf("%d", &n);
    pattern(n);
    return 0;
}