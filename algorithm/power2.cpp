#include <iostream>

inline __int64_t sqr(int n) {
    return n * n;
}

__int64_t power2(int n) {
    if (n == 0) return 1;
    return (n & 1) ? sqr(power2(n >> 1)) << 1 : sqr(power2(n >> 1));
}

int main() {
    int n;
    std::cin >> n;
    std::cout << power2(n) << std::endl;
    return 0;
}