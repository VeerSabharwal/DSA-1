#include <stdio.h>
void generateFibonacci(int n)
{
    int first = 0, second = 1, next, i;
    FILE *outputFile;
    outputFile = fopen("fibonaccioutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Could not open output file.\n");
        return;
    }
    fprintf(outputFile, "%d %d ", first, second);
    for (i = 3; i <= n; ++i)
    {
        next = first + second;
        fprintf(outputFile, "%d ", next);
        first = second;
        second = next;
    }
    fclose(outputFile);
}

int main()
{
    int numTerms;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &numTerms);
    if (numTerms <= 0)
    {
        printf("Number of terms should be a positive integer.\n");
        return 1;
    }
    generateFibonacci(numTerms);
    return 0;
}

