#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sortString(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool canFormString(char str1[], char str2[]) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2){
        return false;
    }
    
    sortString(str1);
    sortString(str2);

    return strcmp(str1, str2) == 0;
}

int main ()
{
    char str1[30], str2[30];
    printf("Enter string 1: ");
    scanf ("%s", str1);
    printf("Enter string 2: ");
    scanf ("%s", str2);

    printf("Output: ");
    if (canFormString(str1, str2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
