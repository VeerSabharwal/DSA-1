#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    FILE *outputFile = fopen("insertionsortoutput.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    fprintf(outputFile, "Sorted array:\n");
    for (int i = 0; i < n; ++i) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\n");
    fclose(outputFile);
    return 0;
}
