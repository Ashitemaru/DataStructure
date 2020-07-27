#include <iostream>

#define DEFAULT_CAPACITY 3

template <class T>
class myVector {
private:
    int _size;
    int _capacity;
    T* _elem;

protected:
    void copyFrom(const T* a, int l, int r) {
        _elem = new T[_capacity = 2 * (r - l)];
        _size = 0;
        while (l < r)
            _elem[_size++] = a[l++];
    }
    // Copy data from an array

public:
    myVector(int c = DEFAULT_CAPACITY) {
        _elem = new T[_capacity = c];
        _size = 0;
    }
    // Initialize a vector by its size
    // Default size is 3

};

int main() {

    return 0;
}