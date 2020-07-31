#include <iostream>

template <class T>
int insertSearch(const T* Container, const T& x, int l, int r) {
    while (l < r) {
        int m = l + ((r - l) * (x - Container[l]) / (Container[r] - Container[l]));
        if (x < Container[m]) r = m;
        else if (x > Container[m]) l = m + 1;
        else return m;
    }
    return -1;
}

template <class T>
int insertSearch(const T* Container, const T& x, int size) {
    return insertSearch<T>(Container, x, 0, size);
}
// Classic insert search
// Only applicable to sorted array!
// O(log log n)

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 90, 123, 435, 22313, 223121};
    std::cout << insertSearch(arr, 34, 11) << std::endl;
    return 0;
}