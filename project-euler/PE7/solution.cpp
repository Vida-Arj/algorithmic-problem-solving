#include<iostream>
using namespace std;

int ans, k;
bool prime(int n){
    for(int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    int x = 2;
    while(k < 10001){
        if (prime(x)){
            ans = x;
            k++;
        }
        x++;
    }
    cout << ans;
}
