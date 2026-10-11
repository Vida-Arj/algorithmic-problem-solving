#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    string s = to_string(num);
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main() {
    int maxPalindrome = 0;
    for (int i = 100; i <= 999; i++) {
        for (int j = i; j <= 999; j++) {
            int product = i * j;
            if (isPalindrome(product) && product > maxPalindrome)
                maxPalindrome = product;
        }
    }
    cout << maxPalindrome;
}
