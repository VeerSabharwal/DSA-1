#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    FILE *outputFile = fopen("bubblesortoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to file for writing.\n");
        return 1;
    }

    fprintf(outputFile, "Sorted array:\n");
    for (int i = 0; i < n; ++i)
    {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fprintf(outputFile, "\n");
    fclose(outputFile);
    return 0;
}
