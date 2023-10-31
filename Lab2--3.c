#include <stdio.h>

//Write a C program to compare two strings without using string library functions.

int main() {
    char str1[100], str2[100];
    int i, isEqual = 1;

    printf("Enter the first string: ");
    scanf("%s", &str1);
    printf("Enter the second string: ");
    scanf("%s", &str2);

    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            isEqual = 0;
            break;
        }
    }

    if (isEqual) {
        printf("The two strings are equal.");
    } else {
        printf("The two strings are not equal.");
    }

    return 0;
}
