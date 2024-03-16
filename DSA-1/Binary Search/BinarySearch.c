#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int index = binarySearch(arr, n, key);
    FILE *outputFile = fopen("binarysearchoutput.txt", "w");
    if (outputFile == NULL)
    {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    if (index != -1)
    {
        fprintf(outputFile, "Element found at index %d.\n", index);
    } else
    {
        fprintf(outputFile, "Element not found.\n");
    }
    fclose(outputFile);
    return 0;
}
