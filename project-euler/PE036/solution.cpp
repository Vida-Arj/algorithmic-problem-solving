#include<iostream>
using namespace std;
int d[100], b[100], n, m, ans;

void stad(int x){
    if(x == 0)
        return;
    n++;
    d[n] = x % 10;
    stad(x / 10);
}

void stab(int x){
    if(x == 0)
        return;
    m++;
    b[m] = x % 2;
    stab(x / 2);
}

bool ispald(int l, int r){
    if (l >= r)
        return true;
    return d[l] == d[r] && ispald(l+1, r-1);
}

bool ispalb(int l, int r){
    if (l >= r)
        return true;
    return b[l] == b[r] && ispalb(l+1, r-1);
}

int main(){
        for(int i = 1; i < 1000000; i++){
            n = 0;
            m = 0;
            stad(i);
            stab(i);
            if (ispald(1, n) && ispalb(1, m))
                ans += i;
        }
        cout << ans;
}
