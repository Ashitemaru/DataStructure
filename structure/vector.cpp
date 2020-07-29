#include <iostream>
#include <string>

#define DEFAULT_CAPACITY 3

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

    int fibSearch(const T& x, int l, int r) {
        return -1;
    }
    // Fibonacci search

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

    int search(std::string request, const T& x, int l, int r) {
        if (request == "binary") return binSearch(x, l, r);
        else if (request == "fibonacci") return fibSearch(x, l, r);
        else throw "Unknown request!";
    }

    int search(std::string request, const T& x) {
        return search(request, x, 0, _size);
    }
    // Search an element by its value
    // More efficient than 'find'
    // Only applicable to sorted vector!
};

int main() {
    myVector<int> a;
    for (int i = 0; i < 30; ++i) a.insert(0, i);
    for (int i = 0; i < 30; ++i) std::cout << a.search("binary", i) << ' ';
    return 0;
}