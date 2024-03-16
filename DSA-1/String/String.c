#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void concatenateStrings(char *dest, const char *src)
 {
    strcat(dest, src);
}

void copyString(char *dest, const char *src)
{
    strcpy(dest, src);
}

int compareStrings(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    char concatenatedStr[200] = "";
    concatenateStrings(concatenatedStr, str1);
    concatenateStrings(concatenatedStr, " ");
    concatenateStrings(concatenatedStr, str2);
    char copiedStr[100];
    copyString(copiedStr, str1);
    int comparisonResult = compareStrings(str1, str2);
    FILE *outputFile = fopen("stringoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to open file for writing.\n");
        return 1;
    }
    fprintf(outputFile, "Concatenated string: %s\n", concatenatedStr);
    fprintf(outputFile, "Copied string: %s\n", copiedStr);
    fprintf(outputFile, "Comparison result: %d\n", comparisonResult);
    fclose(outputFile);
    return 0;
}
