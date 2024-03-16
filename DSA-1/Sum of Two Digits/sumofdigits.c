#include <stdio.h>

int main() {
    int number1, number2, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);
    sum = number1 + number2;
    FILE *outputFile = fopen("sumofdigitsoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to open sumofdigitsoutput.txt for writing.\n");
        return 1;
    }
    fprintf(outputFile, "%d and %d is %d\n", number1, number2, sum);
    fclose(outputFile);
    return 0;
}
