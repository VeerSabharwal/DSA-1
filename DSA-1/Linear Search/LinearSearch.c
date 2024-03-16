#include <stdio.h>
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return 1;
}
int main()
{
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int index = linearSearch(arr, n, key);
    FILE *outputFile = fopen("linearsearchoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to open file for writing.\n");
        return -1;
    }

    if (index != -1)
    {
        fprintf(outputFile, "Element found at index %d.\n", index);
    }
    else
    {
        fprintf(outputFile, "Element not found.\n");
    }

    fclose(outputFile);
    return 0;
}
