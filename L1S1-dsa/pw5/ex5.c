#include <stdio.h>

// Program to Find the Maximum Value in an Array
int main()
{
    int n, i, max; // Declare variables: n for size of array, i for loop index, max for maximum value

    // Prompt user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n); // Read the size of the array from the user

    int arr[n]; // Declare an array of size n

    // Prompt user to enter the elements of the array
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) // Loop through the array to take input
    {
        scanf("%d", &arr[i]); // Store each input value in the array
    }

    max = arr[0];           // Initialize max with the first element of the array
    for (i = 1; i < n; i++) // Traverse the rest of the array to find the maximum value
    {
        if (arr[i] > max) // Compare current element with max
        {
            max = arr[i]; // Update max if current element is greater
        }
    }

    // Display the maximum value found in the array
    printf("The maximum value in the array is: %d\n", max);

    return 0; // Return 0 to indicate successful execution
}
