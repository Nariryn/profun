#include <stdio.h>

int main() {

    int n1, n2, n3, max;

    printf ("Enter number: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    max = (n1 > n2) ? n1 : n2 || (n2 > n3) ? n2 : n3 || (n3 > n1) ? n3 : n1;

    while (1) {
        if ((max % n1 == 0) && (max % n2 == 0) && (max % n3 == 0)) {
            printf("output : %d", max);
            break;
        }
        ++max;
    }
    return 0;
}