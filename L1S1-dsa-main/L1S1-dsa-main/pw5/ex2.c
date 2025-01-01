#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], arr2[n], arr3[n];
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] % 2 == 0)
        {
            arr2[evenCount++] = arr[i]; 
        }
        else
        {
            arr3[oddCount++] = arr[i];
        }
    }
    printf("\nEven numbers: ");
    for (int i = 0; i < evenCount; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\nOdd numbers: ");
    for (int i = 0; i < oddCount; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}
