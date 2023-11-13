#include <stdio.h>
#include <stdbool.h>

// Function to find and print the subset that sums to k
void printSubset(int arr[], bool dp[][1001], int n, int k) {
    if (!dp[n][k]) {
        return; // No subset found
    }

    int i = n;
    while (i > 0) {
        if (dp[i - 1][k]) {
            i--; // Skip this element
        } else {
            // Include this element in the subset
            printf("%d ", arr[i - 1]);
            k -= arr[i - 1];
            i--;
        }
    }
    printf("\n");
}

// Function to print the dp table
void printDpTable(bool dp[][1001], int n, int k) {
    // Rows represent elements of the input array, columns represent target sums.
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            printf("dp[%d][%d] = %d ", i, j, dp[i][j]);
        }
        printf("\n");
    }
}

bool isSubsetSum(int arr[], int n, int k) {
    bool dp[n + 1][1001];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                dp[i][j] = true;
            } else if (i == 0) {
                dp[i][j] = false;
            } else if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][k]) {
        printf("yes\n");
        printf("Subset that sums to %d: ", k);
        printSubset(arr, dp, n, k);
        printf("Dynamic Programming Table:\n");
        printDpTable(dp, n, k);  // Print the dp table
        return true;
    } else {
        printf("no\n");
        printf("Dynamic Programming Table:\n");
        printDpTable(dp, n, k);  // Print the dp table
        return false;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    isSubsetSum(arr, n, k);

    return 0;
}
