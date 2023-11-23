#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int start = 0, last, j = 0, max = 0, count = 0;
    printf("Enter String: ");
    scanf("%s", input);
    int size = strlen(input);
    last = size;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
        {
            for (j = i + 1; j < size - i; j++)
            {
                if (!(input[j] == 'a' || input[j] == 'e' || input[j] == 'i' || input[j] == 'o' ||  input[j] == 'u'))
                {
                    count++;
                }
                else
                {
                    if (count > max)
                    {
                        max = count;
                        start = i;
                        last = j;
                    }
                    count = 0;
                }
            }
        }
    }
    printf("Output: ");
    for (int i = start + 1; i < last; i++)
    {
        printf("%c", input[i]);
    }
}