#include <stdio.h>

int main() {
    int n;
    int k;

    // 1. Get and validate the size of the array
    while (1) {
        printf("Enter the total number of elements: ");
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Error: Please enter a valid positive integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        break;
    }

    // 2. Declare the array based on user input size
    int arr[n];

    // 3. Take array values from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error: Invalid number. Please re-enter this element.\n");
            while (getchar() != '\n'); // Clear input buffer
            i--; // Repeat this index
        }
    }

    // 4. Take and validate the value of k
    while (1) {
        printf("\nEnter the value of k (1 to %d): ", n);
        
        // Check if the input is a valid integer
        if (scanf("%d", &k) != 1) {
            printf("Error: Please enter a valid integer numeric value.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Validate that k falls within the acceptable range
        if (k < 1 || k > n) {
            printf("Error: Value out of range. Please try again.\n");
            continue;
        }
        break; 
    }

    // 5. Sort the array in ascending order (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    
    printf("\nThe %dth smallest element is: %d\n", k, arr[k - 1]);
    return 0;
}
