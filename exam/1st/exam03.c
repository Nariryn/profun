#include <stdio.h>

int main()
{
    int numbers[4], sum = 0, temp;
    printf("Enter number: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    sum = numbers[1] + numbers[2];
    printf("Answer: %d", sum);

    return 0;
}
