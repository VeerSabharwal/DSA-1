#include <stdio.h>

int check_prime(int i, int num)
{
    if (i * i > num) {
        return 0;
    }
    if (num % i == 0) {
        return 1;
    }
    return check_prime(i + 1, num);
}

int main()
{
    int num;
    FILE *file;

    file = fopen("primenuminput.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    printf("Enter a number:\n");
    scanf("%d", &num);
    fprintf(file, "%d", num);
    fclose(file);

    if (check_prime(2, num) == 0)
        {
        printf("It's a prime number.\n");
    }
    else
    {
        printf("Not a prime number.\n");
    }

    file = fopen("primenumoutput.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    if (check_prime(2, num) == 0)
    {
        fprintf(file, "%d is a prime number.\n", num);
    }
    else
    {
        fprintf(file, "%d is not a prime number.\n", num);
    }

    fclose(file);

    return 0;
}

