//Write a program to find sum of every row and every column in a two-dimensional array.
#include <stdio.h>

int main() {
    int rows, cols;

    // Input number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[50][50];
    int rowSum[50] = {0};
    int colSum[50] = {0};

    // Input elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of each row and column
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Print matrix with row sums
    printf("\nMatrix with row sums:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("| %d\n", rowSum[i]);
    }

    // Print column sums
    printf("\nColumn sums:\n");
    for (int j = 0; j < cols; j++) {
        printf("%d ", colSum[j]);
    }
    printf("\n");

    return 0;
}