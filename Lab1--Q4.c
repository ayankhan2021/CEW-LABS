#include <stdio.h>

void decimalToBinary(int decimal) {
    if (decimal > 0) {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber == 0) {
        printf("Binary representation: 0\n");
    } else {
        printf("Binary representation: ");
        decimalToBinary(decimalNumber);
    }

    return 0;
}
