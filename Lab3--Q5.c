#include <stdio.h>

void addMatrices(const int *matrix1, const int *matrix2, int *result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = matrix1[i] + matrix2[i];
    }
}

void displayMatrix(const int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(matrix+i * cols+j));
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int size = rows * cols;

    // Declare matrices and result matrix
    int matrix1[size], matrix2[size], result[size];

    // Input elements for the first matrix
    printf("Enter elements for the first matrix:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &matrix1[i]);
    }

    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &matrix2[i]);
    }

    addMatrices(matrix1, matrix2, result, size);

    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows, cols);

    printf("Matrix 2:\n");
    displayMatrix(matrix2, rows, cols);

    printf("Sum of matrices:\n");
    displayMatrix(result, rows, cols);

    return 0;
}
