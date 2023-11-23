#include <stdio.h>

int main() {
    int m, n;

    printf("Enter the value of m: ");
    scanf("%d", &m);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Calculate the side length of the square
    int side_length = 2 * m + 1;

    // Create and print the reversed square pattern
    for (int i = 0; i < side_length; i++) {
        for (int j = 0; j < side_length; j++) {
            int max = i > j ? i : j;
            max = max > side_length - i - 1 ? max : side_length - i - 1;
            max = max > side_length - j - 1 ? max : side_length - j - 1;

            printf("%d", n + max - m);
        }
        printf("\n");
    }

    return 0;
}
