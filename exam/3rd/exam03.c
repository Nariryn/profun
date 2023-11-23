#include <stdio.h>

void dectobi(float num) {
    int intPart = (int)num;
    float decimalPart = num - intPart;

    printf("Answer : ");
    while (intPart > 0) {
        printf("%d", intPart % 2);
        intPart /= 2;
    }

    printf("0.");

    for (int i = 0; i < 10; i++) {
        decimalPart *= 2;
        int bit = (int)decimalPart;
        printf("%d", bit);
        decimalPart -= bit;
    }

    printf("\n");
}

int main() {
    float num;

    printf("Enter number: ");
    scanf("%f", &num);

    dectobi(num);

    return 0;
}
