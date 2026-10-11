#include <iostream>
using namespace std;

int sumsq(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (i*i);
    return ans;
}

int sqsum(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i;
    return ans * ans;
}

int main () {
    cout << sqsum(100) - sumsq(100);
}
