#include<iostream>
using namespace std;
int a[500], ans;

int main(){
    a[0] = 2;
    for(int k = 0; k < 999; k++){
        int carry = 0;
        for(int i = 0; i < 500; i++){
            a[i] *= 2;
            a[i] += carry;
            carry = a[i]/10;
            a[i] %= 10;
        }
    }
    for(int i = 0; i < 500; i++)
        ans += a[i];
    cout << ans;
}
