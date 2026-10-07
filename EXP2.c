#include <stdio.h>
#define MAX 10

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements (%dx%d):\n", rows, cols);
    int i,j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    printf("Result of Addition:\n");
    displayMatrix(result, rows, cols);
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], 
int r1, int c1, int c2) 
{
    int result[MAX][MAX];
    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;
  // Matrix multiplication logic
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
    printf("Result of Multiplication:\n");
    displayMatrix(result, r1, c2);
}
void transposeMatrix(int A[MAX][MAX], int rows, int cols)  {
    int result[MAX][MAX];
    int i,j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[j][i] = A[i][j];
    printf("Transpose of Matrix:\n");
    displayMatrix(result, cols, rows);
}
int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;
    do {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
        case 1:
            printf("Enter rows and columns for matrices (same size): ");
            scanf("%d%d", &r1, &c1);
            printf("Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Matrix B:\n");
            readMatrix(B, r1, c1);
            addMatrix(A, B, r1, c1);
            break;
        case 2:
            printf("Enter rows and columns for Matrix A: ");
            scanf("%d%d", &r1, &c1);
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d%d", &r2, &c2);
            if (c1 != r2) {
                printf("Matrix multiplication not possible (c1 != r2).\n");
                break;
            }
            printf("Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Matrix B:\n");
            readMatrix(B, r2, c2);
            multiplyMatrix(A, B, r1, c1, c2);
            break;

        case 3:
            printf("Enter rows and columns for Matrix: ");
            scanf("%d%d", &r1, &c1);
            printf("Matrix:\n");
            readMatrix(A, r1, c1);
            transposeMatrix(A, r1, c1);
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
