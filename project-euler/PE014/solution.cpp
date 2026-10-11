#include <iostream>
using namespace std;
long long Max, ans;

int collatz(long long n){
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz(3*n + 1);
}

int main(){
    for(long long i = 1; i < 1e6; i++){
        long long len = collatz(i);
        if (len > Max){
            Max = len;
            ans = i;
        }
    }
    cout << ans;
}
