#include<iostream>
using namespace std;
int ans;
bool m[30000];

bool isabun(int n){
    int sum = 0;
    for(int i = 1; i*i <= n; i++)
        if(n % i == 0){
            if(i == n / i)
                sum += i;
            else
                sum += i + n / i;
        }
    return ((sum - n) > n);
}

void check(){
    for(int i = 1; i <= 28123; i++)
        if (isabun(i))
            m[i] = true;
}

bool sumabun(int n){
    for(int i = 1; i < n; i++)
        if(m[i] && m[n - i])
            return true;
    return false;
}

int main(){
    check();
    for(int i = 1; i <= 28123; i++)
        if (!sumabun(i))
            ans += i;
    cout << ans;
}
