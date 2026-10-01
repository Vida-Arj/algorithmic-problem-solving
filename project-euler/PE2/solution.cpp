#include <iostream>
using namespace std;

int fibo(){
    int ans = 2;
    int f1 = 1, f2 = 2, f3 = 0;
    while (f3 < 4000000){
        f3 = f1 + f2;
        if (f3 % 2 == 0)
            ans += f3;
        f1 = f2;
        f2 = f3;
    }
    return ans;
}
int main () {
    cout << fibo();
}
