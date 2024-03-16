#include <stdio.h>
#include <string.h>
int Palindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    printf("Enter the number: ");
    scanf("%s", input);
    int palindrome = Palindrome(input);
    FILE *outputFile = fopen("palindromeoutput.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open palindromeoutput.txt for writing.\n");
        return 1;
    }
    if (palindrome)
    {
        fprintf(outputFile, "%s is a palindrome.\n", input);
    } else
    {
        fprintf(outputFile, "%s is not a palindrome.\n", input);
    }
    fclose(outputFile);
    return 0;
}

