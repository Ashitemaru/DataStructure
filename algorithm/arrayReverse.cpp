#include <iostream>

template <class T>
void printArray(T* Container, int size) {
    std::cout << "[";
    if (size != 0) {
        std::cout << Container[0];
        for (int i = 1; i < size; i++) {
            std::cout << "," << Container[i];
        }
    }
    std::cout << "]" << std::endl;
}

template <class T>
void reverse(T* Container, int l, int r) {
    if (r > l) {
        T tmp = Container[l];
        Container[l] = Container[r];
        Container[r] = tmp;
        reverse(Container, l + 1, r - 1);
    }
    return;
}

template <class T>
void reverse(T* Container, int size) {
    reverse<T>(Container, 0, size - 1);
    return;
}

int main() {
    int arr[] = {1, 2, 0, 3, 1, 3, 9};
    reverse(arr, 7);
    printArray(arr, 7);
    return 0;
}