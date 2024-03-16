#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int reverse = 0;
    while (n != 0)
    {
        int remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    FILE *outputFile = fopen("Reverseoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error: Unable to open output.txt for writing.\n");
        return 1;
    }
    fprintf(outputFile, "Reversed number = %d", reverse);
    fclose(outputFile);
    printf("Reversed number: %d\n", reverse);
    return 0;
}
