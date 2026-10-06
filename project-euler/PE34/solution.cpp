#include<bits/stdc++.h>
using namespace std;
int ans;

int fact(int x){
    if(x == 0)
        return 1;
    return x * fact(x - 1);
}

int sof(int x, int sum){
    if (x == 0)
        return sum;
    sum += fact(x % 10);
    return sof(x / 10, sum);
}

int main(){
    for(int i = 3; i < 100000; i++){
        if (i == sof(i, 0))
            ans += i;
    }
    cout << ans;
}
