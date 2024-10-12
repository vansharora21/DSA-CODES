#include <stdio.h>
#include <stdlib.h>

void createArray(int arr[], int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void insertElement(int arr[], int *n) {
    int elem, pos;

    if (*n == 100) {
        printf("Array is full! Cannot insert more elements.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &elem);

    printf("Enter the position (1 to %d): ", *n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right to create space
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    (*n)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf("Array is empty. Cannot delete elements.\n");
        return;
    }

    printf("Enter the position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    printf("Element deleted successfully.\n");
}

int main() {
    int arr[100], n = 0, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                insertElement(arr, &n);
                break;
            case 4:
                deleteElement(arr, &n);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
