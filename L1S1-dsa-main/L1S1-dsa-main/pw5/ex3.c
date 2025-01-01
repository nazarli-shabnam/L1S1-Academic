#include <stdio.h>

int search(int size, int *array, int element);

int main()
{
    int n, element, i, found;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &element);
    found = 0;
    for (i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            found = 1;
            printf("Element %d found at index %d (without function)\n", element, i);
            break;
        }
    }
    if (!found)
    {
        printf("Element %d not found (without function)\n", element);
    }
    int result = search(n, array, element);
    if (result != -1)
    {
        printf("Element %d found at index %d (using function)\n", element, result);
    }
    else
    {
        printf("Element %d not found (using function)\n", element);
    }

    return 0;
}

int search(int size, int *array, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}
