#include <iostream>

static int F[] = {
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903
};

template <class T>
int fibSearch(const T* Container, const T& x, int l, int r) {
    int fibSeed = r - l;
    int ptr = l + F[fibSeed] - 1;
     while (l < r) {
        while (F[fibSeed] > r - l)
            ptr = l + F[--fibSeed] - 1;
        if (x == Container[ptr]) return ptr;
        else if (x < Container[ptr]) r = ptr;
        else l = ptr + 1;
    }
    return -1;
}

template <class T>
int fibSearch(const T* Container, const T& x, int size) {
    return fibSearch(Container, x, 0, size);
}
// Classic Fibonacci search
// Only applicable to sorted array!
// O(1.4 * log n)

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 90, 123, 435, 22313, 223121};
    std::cout << fibSearch(arr, 34, 11) << std::endl;
    return 0;
}