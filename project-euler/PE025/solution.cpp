#include<iostream>
using namespace std;
int a[1000], b[1000], sum[1000];

int main(){
    a[0] = 1;
    b[0] = 1;
    int iofs = 2;
    while(sum[999] == 0){
        int carry = 0;
        for(int i = 0; i < 1000; i++){
            sum[i] = a[i] + b[i] + carry;
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
        iofs++;
        for(int j = 0; j < 1000; j++){
            a[j] = b[j];
            b[j] = sum[j];
        }
    }
    cout << iofs;
}
