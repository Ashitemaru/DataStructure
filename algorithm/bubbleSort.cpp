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
void bubbleSort(T* Container, int size) {
    if (size > 1)
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - 1 - i; j++)
                if (Container[j + 1] < Container[j]) {
                    T tmp = Container[j];
                    Container[j] = Container[j + 1];
                    Container[j + 1] = tmp;
                }
    return;
}
// Classic

template <class T>
void anotherBubbleSort(T* Container, int size) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 1; i < size; i++)
            if (Container[i - 1] > Container[i]) {
                T tmp = Container[i];
                Container[i] = Container[i - 1];
                Container[i - 1] = tmp;
                isSorted = false;
            }
        size--;
    }
    return;
}
// More efficient

int main() {
    int arr1[] = {1, 2, 0, 3, 1, 3, 9};
    bubbleSort(arr1, 7);
    printArray(arr1, 7);
    int arr2[] = {1, 2, 0, 3, 1, 3, 9};
    anotherBubbleSort(arr2, 7);
    printArray(arr2, 7);
    return 0;
}