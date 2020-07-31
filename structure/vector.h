#pragma once

#include <iostream>
#include <string>

#define DEFAULT_CAPACITY 3

static int F[] = {
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903
};

template <class T>
class myVector {
private:
    int _size;
    int _capacity;
    T* _elem;

    bool isSorted = false;

protected:
    void copyFrom(const T* a, int l, int r) {
        // TODO: check whether the index is legal
        _elem = new T[_capacity = 2 * (r - l)];
        _size = 0;
        while (l < r)
            _elem[_size++] = a[l++];
    }
    // Copy data from an array

    void expand() {
        if (_size < _capacity) return;
        _capacity = std::max(_capacity, DEFAULT_CAPACITY);
        T* oldelem = _elem;
        _elem = new T[_capacity <<= 1];
        for (int i = 0; i < _size; ++i) {
            _elem[i] = oldelem[i];
        }
        delete[] oldelem;
    }
    // Expand container

    void shrink() {
        if (_size * 4 > _capacity) return;
        _capacity = std::max(_capacity, DEFAULT_CAPACITY);
        T* oldelem = _elem;
        _elem = new T[_capacity >>= 1];
        for (int i = 0; i < _size; ++i) {
            _elem[i] = oldelem[i];
        }
        delete[] oldelem;
    }
    // Shrink container

    int binSearch(const T& x, int l, int r) {
        while (l < r) {
            int m = (l + r) >> 1;
            if (x < _elem[m]) r = m;
            else if (x > _elem[m]) l = m + 1;
            else return m;
        }
        return -1;
    }
    // Binary search

    int restrictedBinSearch(const T& x, int l, int r) {
        while (l < r) {
            int m = (l + r) >> 1;
            x < _elem[m] ? r = m : l = m + 1;
        }
        return --l;
    }
    // Restricted binary search
    // When more than 1 element equal to x
    // It will return the element with the maximum index

    int fibSearch(const T& x, int l, int r) {
        int fibSeed = r - l;
        int ptr = l + F[fibSeed] - 1;
        while (l < r) {
            while (F[fibSeed] > r - l)
                ptr = l + F[--fibSeed] - 1;
            if (x == _elem[ptr]) return ptr;
            else if (x < _elem[ptr]) r = ptr;
            else l = ptr + 1;
        }
        return -1;
    }
    // Fibonacci search

    int insertSearch(const T& x, int l, int r) {
        while (l < r) {
            int m = l + ((r - l) * (x - _elem[l]) / (_elem[r] - _elem[l]));
            if (x < _elem[m]) r = m;
            else if (x > _elem[m]) l = m + 1;
            else return m;
        }
        return -1;
    }
    // Insert search

    void bubbleSort() {
        if (_size > 1)
            for (int i = 0; i < _size - 1; i++)
                for (int j = 0; j < _size - 1 - i; j++)
                    if (_elem[j + 1] < _elem[j]) {
                        T tmp = _elem[j];
                        _elem[j] = _elem[j + 1];
                        _elem[j + 1] = tmp;
                    }
        return;
    }
    // Bubble sort

    void mergeSort(int l, int r) {
        if (r - l < 2) return;
        int m = (l + r) >> 1;
        mergeSort(l, m);
        mergeSort(m, r);

        T* tmp = new T[_size];
        int first = l;
        int second = m;
        int flag = l;

        while (first < m && second < r) {
            if (_elem[first] > _elem[second]) tmp[flag++] = _elem[second++];
            else tmp[flag++] = _elem[first++];
        }

        while (first < m) tmp[flag++] = _elem[first++];
        while (second < r) tmp[flag++] = _elem[second++];

        for (int i = l; i < r; i++) _elem[i] = tmp[i];
        delete[] tmp;
        return;
    }

    void mergeSort() {
        mergeSort(0, _size);
        return;
    }
    // Merge sort

public:
    myVector(int c = DEFAULT_CAPACITY) {
        _elem = new T[_capacity = c];
        _size = 0;
    }
    // Initialize a vector by its size
    // Default size is 3

    myVector(const T* a, int l, int r) {
        copyFrom(a, l, r);
    }
    // Initialize a vector from an array

    myVector(const myVector<T>& v, int l, int r) {
        copyFrom(v._elem, l, r);
    }
    // Initialize a vector from a vector

    myVector(const myVector<T>& v) {
        copyFrom(v._elem, 0, v._size);
    }
    // Copy constructor

    int size() {
        return _size;
    }
    // Get the size of the vector

    T& operator[](int index) {
        if (index < 0 || index > _size - 1) {
            throw "Illegal index!";
        }
        return _elem[index];
    }
    // Overload the operator[]

    int insert(int index, const T& x) {
        if (index < 0 || index > _size) {
            throw "Illegal index!";
        }
        expand();
        for (int i = _size; i > index; --i)
            _elem[i] = _elem[i - 1];
        _elem[index] = x;
        ++_size;
        return index;
    }
    // Insert an element into the vector

    int remove(int l, int r) {
        if (l >= r) return 0;
        while (r < _size) {
            _elem[l++] = _elem[r++];
        }
        _size = l;
        shrink();
        return r - l;
    }
    // Delete elements in [l, r)

    T remove(int index) {
        if (index < 0 || index > _size - 1) {
            throw "Illegal index!";
        }
        T tmp = _elem[index];
        remove(index, index + 1);
        return tmp;
    }
    // Delete an element by its index

    int find(const T& x, int l, int r) {
        while (l < r-- && x != _elem[r]) {};
        return r;
    }

    int find(const T& x) {
        return find(x, 0, _size);
    }
    // Find an element by its value

    template <class func>
    void forEach(func f) {
        for (int i = 0; i < _size; ++i) f(_elem[i]);
        return;
    }
    // Traverse the vector

    int uniquify() {
        int i = 0, j = 0;
        while (++j < _size)
            if (_elem[i] != _elem[j]) _elem[++i] = _elem[j];
        _size = ++i;
        shrink();
        return j - i;
    }
    // Uniquify the vector
    // Only applicable to sorted vector!

    int search(const T& x, int l, int r, std::string request = "binary") {
        if (!isSorted) throw "Not applicable to unsorted vector!";
        if (request == "binary") return binSearch(x, l, r);
        else if (request == "rBinary") return restrictedBinSearch(x, l, r);
        else if (request == "fibonacci") return fibSearch(x, l, r);
        else if (request == "insert") return insertSearch(x, l, r);
        else throw "Unknown request!";
    }

    int search(const T& x, std::string request = "binary") {
        return search(x, 0, _size, request);
    }
    // Search an element by its value
    // More efficient than 'find'
    // Only applicable to sorted vector!

    void sort(std::string request = "merge") {
        if (request == "bubble") bubbleSort();
        else if (request == "merge") mergeSort();
        else throw "Unknown request!";
        isSorted = true;
    }
    // Sort the vector & set 'isSorted' true

    friend std::ostream& operator<<(std::ostream& out, myVector<T>& src) {
        out << '[';
        if (src._size > 1) {
            out << src.operator[](0);
            for (int i = 1; i < src._size; ++i) out << ',' << src.operator[](i);
        }
        out << ']';
        return out;
    }
    // Output the vector
};