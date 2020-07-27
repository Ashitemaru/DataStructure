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
void randomGenerator(T a[], int n) {
    for (int i = 1; i < n; i++) {
        int location = rand() % i;
        int tmp = a[i];
        a[i] = a[location];
        a[location] = tmp;
    }
    return;
}

int main() {
    srand(time(0));
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    randomGenerator(arr, 10);
    printArray(arr, 10);
    return 0;
}