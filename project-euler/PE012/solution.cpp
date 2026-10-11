#include<iostream>
using namespace std;

int ans;
int div(int x){
    int k = 0;
    for(int i = 1; i*i <= x; i++){
        if (x % i == 0)
            if(i == x/i)
                k++;
            else
                k += 2;
    }
    return k;
}
int main(){
    for(int i = 1; div(ans) < 500; i++){
        ans += i;
    }
    cout << ans;
}
