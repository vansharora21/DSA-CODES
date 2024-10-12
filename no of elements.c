#include <stdio.h>

int main() {
    int n;

    // Ask the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array with user-defined size

    // Taking array elements as input from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Display the number of elements
    printf("The number of elements in the array is: %d\n", size);

    return 0;
}
