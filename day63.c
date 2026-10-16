#include <stdio.h>
#include <limits.h>

// Function to calculate maximum subarray sum using Kadane's Algorithm
int maxSubarraySum(int arr[], int n) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];
        
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    int n;
    
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements (separated by spaces or commas):\n", n);
    for (int i = 0; i < n; i++) {
        // The " %d," format reads a number and optionally consumes a trailing comma
        if (scanf("%d,", &arr[i]) != 1) {
            printf("Error reading element at index %d. Make sure to input numbers.\n", i);
            return 1;
        }
    }

    // Calculate and print the maximum subarray sum
    int max_sum = maxSubarraySum(arr, n);
    printf("The maximum sum of a contiguous subarray is: %d\n", max_sum);

    return 0;
}

