#include<iostream>
using namespace std;
int a[200], ans;

int main() {
    a[0] = 1;
    for(int k = 1; k <= 100; k++){
        int carry = 0;
        for(int i = 0; i < 200; i++){
            a[i] *= k;
            a[i] += carry;
            carry = a[i] / 10;
            a[i] %= 10;
        }
    }

    for(int i = 0; i < 200; i++)
        ans += a[i];
    cout << ans;
}
