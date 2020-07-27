#include <iostream>

const int MIN = -1e9 - 7;

int greatestSum_trivial(int a[], int n) {
    int result = MIN;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) sum += a[k];
            result = std::max(result, sum);
        }
    return result;
}
// Trivial algorithm
// O(n^2)

int greatestSum_divide(int a[], int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) >> 1;
    int leftMax = MIN;
    int rightMax = MIN;

    int tmpSum = 0;
    for (int i = m; i >= l; i--) {
        tmpSum += a[i];
        leftMax = std::max(leftMax, tmpSum);
    }
    // Greatest sum of left part

    tmpSum = 0;
    for (int j = m + 1; j <= r; j++) {
        tmpSum += a[j];
        rightMax = std::max(rightMax, tmpSum);
    }
    // Greatest sum of right part

    return std::max(
        leftMax + rightMax,
        std::max(
            greatestSum_divide(a, l, m),
            greatestSum_divide(a, m + 1, r)
        )
    );
    // std::max only accepts 2 parameters
    // This is not very good
}

int greatestSum_divide(int a[], int n) {
    return greatestSum_divide(a, 0, n - 1);
}
// A better algorithm
// O(n * log n)

int greatestSum_decrease_DP(int a[], int n) {
    int* maxSum = new int[n];
    maxSum[0] = a[0];
    if (n > 1)
        for (int i = 1; i < n; i++) {
            maxSum[i] = std::max(maxSum[i - 1] + a[i], a[i]);
        }
    int result = MIN;
    for (int i = 0; i < n; i++) {
        result = std::max(result, maxSum[i]);
    }
    delete[] maxSum;
    return result;
}
// The most efficient algorithm
// O(n)

int main() {
    int arr[] = {2, -4, 3, -1, 2, -4, 3};
    std::cout
        << greatestSum_trivial(arr, 7)
        << greatestSum_divide(arr, 7)
        << greatestSum_decrease_DP(arr, 7)
        << std::endl;
    return 0;
}