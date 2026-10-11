#include <iostream>
using namespace std;
int a[16][16];

int Max(int m, int n){
    if (m > n)
        return m;
    return n;
}

int max_pth(int i, int j){
    if (i == 16)
        return 0;
    return Max(max_pth(i+1, j), max_pth(i+1, j+1)) + a[i][j];
}

int main(){
    for(int i = 1; i <= 15; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
    cout << max_pth(1, 1);

}
