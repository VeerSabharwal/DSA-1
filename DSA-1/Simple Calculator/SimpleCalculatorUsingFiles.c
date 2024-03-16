#include <stdio.h>
#include <stdlib.h>

void process_file(FILE *file)
{
    char ch;
    float a, b;
    while (1)
    {
        printf("Enter the operator + or - or * or / or Quit\n");
        scanf(" %c", &ch);
        if(ch=='q')
            break;
        printf("Enter the operands a and b: ");
        scanf("%f %f", &a, &b);

        switch (ch)
        {
        case '+':
            fprintf(file, "%f + %f = %f\n", a, b, a + b);
            break;
        case '-':
            fprintf(file, "%f - %f = %f\n", a, b, a - b);
            break;
        case '*':
            fprintf(file, "%f * %f = %f\n", a, b, a * b);
            break;
        case '/':
            if (b == 0)
            {
                fprintf(file, "Division by zero is not possible.\n");
            }
            else
            {
                fprintf(file, "%f / %f = %f\n", a, b, a / b);
            }
            break;
        default:
            fprintf(file, "Invalid operator\n");
        }
    }
}

int main()
{
    FILE *file;
    char filename[100] = "SimpleCalciOut.txt";
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Could not open or create the file.\n");
        return 1;
    }
    process_file(file);
    fclose(file);
    return 0;
}

