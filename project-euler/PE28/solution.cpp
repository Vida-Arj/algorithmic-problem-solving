#include <iostream>
using namespace std;
int n, a[1002][1002]; // Stores the full spiral grid for potential future use (e.g. printing the spiral)
int ans;

void sprl(int i, int j, int k){
    if ((i == (n+1)) || (j == (n+1)) || (i == 0) || (j == 0))
        return;

    if ((i == j) || (i+j == n+1))
        ans += k;

    if ((i <= j) && (i+j <= n+1)){
        a[i][j] = k;
        sprl(i, j+1, ++k);

    }

    if ((i >= j) && (i+j > n+1)){
        a[i][j] = k;
        sprl(i, j-1, ++k);
    }

    if ((i < j) && (i+j > n+1)){
        a[i][j] = k;
        sprl(i+1, j, ++k);
    }

    if ((i > j) && (i+j <= n+1)){
        a[i][j] = k;
        sprl(i-1, j, ++k);
    }

}

int main(){
    cin >> n;
    sprl(n/2 + 1, n/2 + 1, 1);
    cout << ans << endl;
}
