#include <stdio.h>
#include <stdlib.h>
int findLargest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int findSmallest(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; ++i)

    {
        if (arr[i] < min)
        {
            min = arr[i];
        }

    }
    return min;
}

int calculateSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
    sum += arr[i];
    }
    return sum;
}

float calculateAverage(int arr[], int n)
{
    int sum = calculateSum(arr, n);
    return (float)sum / n;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
    printf("Memory allocation failed.\n");
    return 1;
    }
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    int largest = findLargest(arr, n);
    int smallest = findSmallest(arr, n);
    int sum = calculateSum(arr, n);
    float average = calculateAverage(arr, n);
    FILE *outputFile = fopen("arrayoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to open file for writing.\n");
        free(arr);
        return 1;
    }

    fprintf(outputFile, "Largest element: %d\n", largest);
    fprintf(outputFile, "Smallest element: %d\n", smallest);
    fprintf(outputFile, "Sum of elements: %d\n", sum);
    fprintf(outputFile, "Average of elements: %.2f\n", average);

    fclose(outputFile);
    free(arr);

    return 0;
}
