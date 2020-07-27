#include <iostream>
#include <string>

std::string longestCommonSubsequence(std::string a, std::string b) {
    if (a == "" || b == "") return "";

    char aFinal = *(--a.end());
    char bFinal = *(--b.end());

    if (aFinal == bFinal) {
        a.pop_back();
        b.pop_back();
        return longestCommonSubsequence(a, b) + aFinal;
    } else {
        std::string _a = a.substr(0, a.size() - 1);
        std::string _b = b.substr(0, b.size() - 1);

        std::string resultA = longestCommonSubsequence(_a, b);
        std::string resultB = longestCommonSubsequence(a, _b);
        if (resultA.size() > resultB.size()) return resultA;
        else return resultB;
    }
}

int main() {
    std::cout << longestCommonSubsequence("qqxxssdd", "xxdd");
    return 0;
}