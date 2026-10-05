#include<bits/stdc++.h>
using namespace std;
int ans;

int sofp(int x, int sum){
    if (x == 0)
        return sum;
    sum += pow(x % 10, 5);
    return sofp(x / 10, sum);
}

int main(){
    for(int i = 2; i < 1000000; i++){
        if (i == sofp(i, 0))
            ans += i;
    }
    cout << ans;
}
