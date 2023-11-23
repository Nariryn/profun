        arr3[k++] = arr1[i++];
    }

    // Merge the second array (arr2) into arr3
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    // Sort the whole array (arr3) using a simple sorting algorithm
    for (int m = 0; m < n1 + n2; m++) {
        for (int n = m + 1; n < n1 + n2; n++) {
            if (arr3[m] > arr3[n]) {
                int temp = arr3[m];
                arr3[m] = arr3[n];
                arr3[n] = temp;
            }
        }
    }
}

int main() {
    int arr1[20], arr2[20];
    printf ("Enter first: ");
    scanf ("%d", &arr1[20]);