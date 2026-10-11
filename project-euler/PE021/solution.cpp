#include <iostream>
using namespace std;

int ans;
int d(int n){
    int sum = 0;
    for(int i = 1; i*i <= n; i++)
        if(n % i == 0){
            if (i == n/i)
                sum += i;
            else
                sum+= i + n/i;
        }
    return sum - n;
}
int main(){
    for(int i = 1; i < 10000; i++)
        if (i == d(d(i)) && i != d(i))
            ans += i;
    cout << ans;
}
