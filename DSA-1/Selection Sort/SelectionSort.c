#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp; // Swap arr[i] with the minimum element
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
    selectionSort(arr, n);
    FILE *outputFile = fopen("selectionsortoutput.txt", "w");
    if (outputFile == NULL) {
        printf("Unable to open file for writing.\n");
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
