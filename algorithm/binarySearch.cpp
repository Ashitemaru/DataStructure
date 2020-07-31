#include <iostream>

template <class T>
int binSearch(const T* Container, const T& x, int l, int r) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (x < Container[m]) r = m;
        else if (x > Container[m]) l = m + 1;
        else return m;
    }
    return -1;
}

template <class T>
int binSearch(const T* Container, const T& x, int size) {
    return binSearch<T>(Container, x, 0, size);
}
// Classic binary search
// Only applicable to sorted array!
// O(1.5 * log n)

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 90, 123, 435, 22313, 223121};
    std::cout << binSearch(arr, 34, 11) << std::endl;
    return 0;
}