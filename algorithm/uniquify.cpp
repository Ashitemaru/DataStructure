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
int uniquify(T* Container, int size) {
    int i = 0, j = 0;
    while (++j < size)
        if (Container[i] != Container[j]) Container[++i] = Container[j];
    return j - i;
}
// Uniquify the vector
// Only applicable to sorted vector!

int main() {
    int arr[] = {1, 2, 4, 4, 4, 5, 6, 9, 9, 9, 9, 10, 12, 12, 12, 12, 333};
    uniquify(arr, 17);
    printArray(arr, 9);
    return 0;
}