#include<iostream>
using namespace std;
string s, t;
int a[100], b[100], sum[10000];
int main(){
    for(int k = 0; k < 50; k++){
        cin >> s >> t;
        for(int j=0, i = s.size()-1; i >= 0; i--, j++)
            a[j] = s[i] - '0';
        for(int j = 0, i = t.size()-1; i >= 0; i--, j++)
            b[j] = t[i] - '0';
        int carry = 0;
        for(int i = 0; i < 100; i++)
        {
            sum[i] += a[i] + b[i] + carry;
            carry = sum[i] / 10;
            sum[i] %= 10;
        }
    }
    int e;
    for(int i = 99; i >= 0; i--)
        if(sum[i] > 0)
        {
            e = i;
            break;
        }
    for(int i = e;i >= 0; i--)
        cout << sum[i];
}
