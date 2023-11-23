#include <stdio.h>

void mergeAndSort(int arr1[], int size1, int arr2[], int size2) {
    int mergedArray[size1 + size2];
    int i = 0, j = 0, k = 0;

    // Merge the two sets of numbers into a single array
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            mergedArray[k++] = arr1[i++];
        } else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // Copy remaining elements from the first set, if any
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    // Copy remaining elements from the second set, if any
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }

    // Display the merged and sorted array
    printf("Merged and Sorted Array: ");
    for (int index = 0; index < size1 + size2; index++) {
        printf("%d ", mergedArray[index]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first set: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter the numbers of the first set in ascending order: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second set: ");
    scanf("%d", &size2);

    int arr2[size2];
    printf("Enter the numbers of the second set in ascending order: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    mergeAndSort(arr1, size1, arr2, size2);

    return 0;
}
