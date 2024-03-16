#include <stdio.h>

#define MAX_SIZE 10
void addMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int m, int n, int p)
{
    for (int i = 0; i < m; ++i)
        {
        for (int j = 0; j < p; ++j)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int transpose[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
        {
        for (int j = 0; j < cols; ++j)
        {
            transpose[j][i] = A[i][j];
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, FILE *file)
{
    for (int i = 0; i < rows; ++i)
        {
        for (int j = 0; j < cols; ++j)
        {
            fprintf(file, "%d ", mat[i][j]);
        }
        fprintf(file, "\n");
    }
}

int main()
{
    int m, n, p, q;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);
    int A[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &p, &q);
    int B[MAX_SIZE][MAX_SIZE];
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            scanf("%d", &B[i][j]);
        }
    }
    int C[MAX_SIZE][MAX_SIZE];
    int transpose[MAX_SIZE][MAX_SIZE];
    FILE *outputFile = fopen("matrixoutput.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open file for writing.\n");
        return 1;
    }
    if (m == p && n == q)
    {
        addMatrix(A, B, C, m, n);
        fprintf(outputFile, "Matrix Addition:\n");
        printMatrix(C, m, n, outputFile);
        fprintf(outputFile, "\n");
    }
    else
    {
        fprintf(outputFile, "Matrix Addition not possible\n\n");
    }
    if (m == p && n == q)
    {
        subtractMatrix(A, B, C, m, n);
        fprintf(outputFile, "Matrix Subtraction:\n");
        printMatrix(C, m, n, outputFile);
        fprintf(outputFile, "\n");
    }
    else
    {
        fprintf(outputFile, "Matrix Subtraction not possible.\n\n");
    }

    if (n == p)
    {
        multiplyMatrix(A, B, C, m, n, q);
        fprintf(outputFile, "Matrix Multiplication:\n");
        printMatrix(C, m, q, outputFile);
        fprintf(outputFile, "\n");
    }
    else
    {
        fprintf(outputFile, "Matrix Multiplication not possible:.\n\n");
    }
    transposeMatrix(A, transpose, m, n);
    fprintf(outputFile, "Transpose of Matrix A:\n");
    printMatrix(transpose, n, m, outputFile);
    transposeMatrix(B, transpose, p, q);
    fprintf(outputFile, "Transpose of Matrix B:\n");
    printMatrix(transpose, p, q, outputFile);
    fclose(outputFile);
    return 0;
}
